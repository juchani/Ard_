#ifdef ESP8266
#include <ESP8266WiFi.h>
#else //ESP32
#include <WiFi.h>//#include <ESP32Ping.h>//
#endif
#include <ModbusIP_ESP8266.h>
#include <ESPmDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include "EEPROM.h"
#define buzzer 5
#define add_reg 400
#define humo 35
#include "DHT.h"
#include <OneWire.h>
#include <DallasTemperature.h>
#define DHT1 25
#define DHT2 26
#define DHT3 27
#define led1 17
#define led2 16
#define led3 4
#define ONE_WIRE_BUS_1 25
#define ONE_WIRE_BUS_2 26
#define ONE_WIRE_BUS_3 27
OneWire s1(ONE_WIRE_BUS_1);
OneWire s2(ONE_WIRE_BUS_2);
OneWire s3(ONE_WIRE_BUS_3);
DallasTemperature ds1(&s1);
DallasTemperature ds2(&s2);
DallasTemperature ds3(&s3);
DHT dht1(DHT1, DHT21);
DHT dht2(DHT2, DHT21);
DHT dht3(DHT3, DHT21);
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
int H_HREG = 108;
int J1_HREG = 17;
int J2_HREG = 18;
int J3_HREG = 19;
ModbusIP mb;
TaskHandle_t tcp_loop;
long ts;
void tcp0code( void * pvParameters );
void setup() {
  Serial.begin(9600);
  ///////sensor
  dht1.begin();
  dht2.begin();
  dht3.begin();
  ds1.begin();
  ds2.begin();
  ds3.begin();
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
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
  pinMode(humo, INPUT);
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
  byte ih2 = 31;

  IPAddress ip(in1, in2, ih1, ih2);

  WiFi.setSleep(false);
  WiFi.mode(WIFI_STA);
  //
  WiFi.config(ip, gateway, subnet);
  //  WiFi.begin("Familia Juchani", "8884992sc");
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


  mb.server();		//Start Modbus IP
  mb.isTransaction(3);
  mb.addHreg(S_HREG);
  mb.addHreg(D1_HREG);
  mb.addHreg(D2_HREG);
  mb.addHreg(D3_HREG);
  mb.addHreg(H1_HREG);
  mb.addHreg(H2_HREG);
  mb.addHreg(H3_HREG);
  mb.addHreg(J1_HREG);
  mb.addHreg(J2_HREG);
  mb.addHreg(J3_HREG);
  mb.addHreg(H_HREG);
  ts = millis();
}


void loop() {
  ArduinoOTA.handle();
  delay(2000);
  sensor_1();
  sensor_2();
  sensor_3();
  digitalWrite(led1, uid16data[11]);
  digitalWrite(led2, uid16data[12]);
  digitalWrite(led3, uid16data[13]);
}
