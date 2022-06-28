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
#define DHT2 25 
#define DHTTYPE DHT21
#define buzzer 5
#define s1 25
#define s2 26
#define s3 27
#define add_reg 400

#define humo 35
OneWire ds_1(s1);
OneWire ds_2(s2);
OneWire ds_3(s3);
DallasTemperature sensor_1(&ds_1);
DallasTemperature sensor_2(&ds_2);
DallasTemperature sensor_3(&ds_3);
DHT dht2(DHT2, DHTTYPE);
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
int H1_HREG = 100;
int D2_HREG = 101;
int H2_HREG = 100;
int D3_HREG = 102;
int H3_HREG = 100;
int H_HREG=108;

ModbusIP mb;
TaskHandle_t tcp_loop;
long ts;
void tcp0code( void * pvParameters );
void setup() {
  Serial.begin(9600);
  ///////DHT
   dht2.begin();
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
  H1_HREG = reg_id + 1;
  D2_HREG = reg_id + 2;
  H2_HREG = reg_id + 3;
  D3_HREG = reg_id + 4;
  H3_HREG = reg_id + 5;
  H_HREG = reg_id + 6;

  ///////////CONFIGURACION IP/////////
  byte in1 = 192;
  byte in2 = 168;
  byte ih1 = 2;
  byte ih2 = 130;

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

  mb.server();		//Start Modbus IP
  mb.isTransaction(3);
  mb.addHreg(S_HREG);
  mb.addHreg(D1_HREG);
  mb.addHreg(D2_HREG);
  mb.addHreg(D3_HREG);
  mb.addHreg(H_HREG);
  ts = millis();
  
}


void loop() {
  ArduinoOTA.handle();
  ds();
}
