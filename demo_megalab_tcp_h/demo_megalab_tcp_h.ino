#ifdef ESP8266
#include <ESP8266WiFi.h>
#else //ESP32
#include <WiFi.h>//#include <ESP32Ping.h>//
#endif
#include <ModbusIP_ESP8266.h>
#include <ESPmDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include "EEPROM.h"
#include "DHT.h"
#include <Adafruit_NeoPixel.h>
#define PIN      23 // On Trinket or Gemma, suggest changing this to 1
#define NUMPIXELS 8 // Popular NeoPixel ring size
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define buzzer 5
#define s1 25
#define s2 26
#define s3 27
#define s4 4
#define s5 15
#define s6 16
#define add_reg 400
#define DHTPIN 2
#define DHTTYPE DHT22 
#define humo 35
OneWire ds_1(s1);
OneWire ds_2(s2);
OneWire ds_3(s3);
OneWire ds_4(s4);
OneWire ds_5(s5);
OneWire ds_6(s6);

DallasTemperature sensor_1(&ds_1);
DallasTemperature sensor_2(&ds_2);
DallasTemperature sensor_3(&ds_3);
DallasTemperature sensor_4(&ds_4);
DallasTemperature sensor_5(&ds_5);
DallasTemperature sensor_6(&ds_6);
DHT dht(DHTPIN, DHTTYPE);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);
int reg_id;
int reg_id_new;
volatile int id;
int uid16data[20];//0=a,1=b,2=enable,3=error
unsigned int data_ = 65000;
//Modbus Registers Offsets

int S_HREG = 5;
int D1_HREG = 100;
int D2_HREG = 101;
int D3_HREG = 102;
int D4_HREG = 103;
int D5_HREG = 104;
int D6_HREG = 105;
int DHT_T_HREG = 106;
int DHT_H_HREG = 107;
int H_HREG=108;

ModbusIP mb;
TaskHandle_t tcp_loop;
long ts;
void tcp0code( void * pvParameters );
void setup() {
  Serial.begin(9600);
  ///////DHT
  dht.begin();
  ////////NEOPIXEL
  pixels.begin();
  ////////DUAL CORE//////
  xTaskCreatePinnedToCore(
    tcp0code,   /* Task function. */
    "tcp_",     /* name of task. */
    10000,       /* Stack size of task */
    NULL,        /* parameter of the task */
    1,           /* priority of the task */
    &tcp_loop,      /* Task handle to keep track of created task */
    0);
    ////HUMO
    pinMode(humo,INPUT);
  /////////CONF PINES
  pinMode(buzzer, OUTPUT);
  ////////EEPROM
  EEPROM.begin(1000);
  ///////////REGISTRO//////
  reg_id = EEPROM.readUInt(add_reg);
  reg_id_new = reg_id ;
  //////////REGISTRO SENSORES
  D1_HREG = reg_id + 0;
  D2_HREG = reg_id + 1;
  D3_HREG = reg_id + 2;
  D4_HREG = reg_id + 3;
  D5_HREG = reg_id + 4;
  D6_HREG = reg_id + 5;
  DHT_T_HREG = reg_id + 6;
  DHT_H_HREG = reg_id + 7;
  H_HREG = reg_id + 8;

  ///////////CONFIGURACION IP/////////
  byte in1 = 192;
  byte in2 = 168;
  byte ih1 = 2;
  byte ih2 = 3;

  IPAddress ip(in1, in2, ih1, ih2);

  WiFi.setSleep(false);
  WiFi.mode(WIFI_STA);
  //
  WiFi.config(ip, gateway, subnet);
  // WiFi.begin("Familia Juchani", "8884992sc");
  WiFi.begin("nasa", "insertec1.");
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("Connection Failed! Rebooting...");
    delay(5000);
    ESP.restart();
  }
  otta();
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  sensor_1.begin();
  sensor_2.begin();
  sensor_3.begin();
  sensor_4.begin();
  sensor_5.begin();
  sensor_6.begin();
  mb.server();		//Start Modbus IP
  mb.isTransaction(3);
  mb.addHreg(S_HREG);
  mb.addHreg(D1_HREG);
  mb.addHreg(D2_HREG);
  mb.addHreg(D3_HREG);
  mb.addHreg(D4_HREG);
  mb.addHreg(D5_HREG);
  mb.addHreg(D6_HREG);
  mb.addHreg(DHT_T_HREG);
  mb.addHreg(DHT_H_HREG);
  mb.addHreg(H_HREG);
  ts = millis();
  
}


void loop() {
  ArduinoOTA.handle();
  ds();
  dht_h();
  Serial.print("\t");
  Serial.print(uid16data[7] );
  Serial.print("\t");
  Serial.print(uid16data[8] );
  Serial.print("\t");
  Serial.print(uid16data[9] );
  Serial.print("\t");
  Serial.println(uid16data[10] );
}
