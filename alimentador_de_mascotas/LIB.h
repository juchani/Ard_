#include <WiFi.h>
#include <ESPmDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include "Arduino.h"
#include "RTClib.h"
#include <LCD_I2C.h>
#include "DHT.h"
#include <ESP32Servo.h> 
Servo S1;
Servo S2;
#define DHTPIN 23
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);
#define bt1 39
#define bt2 34
#define bt3 35 
#define sp_ult1 6
#define sp_ult2 3
#define sp_ult3 3
#define sp_ult4 3
#define trig1 18
#define trig2 17
#define trig3 4
#define trig4 15
#define echo1 19
#define echo2 5
#define echo3 16
#define echo4 2
#define lim 20
String parpadeo[]={":"," "};
bool st;
LCD_I2C lcd(0x27, 16, 2);
RTC_DS3231 rtc;
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
bool en_ult1, en_ult2, en_ult3, en_ult4;
int  hora_ ;
int  minuto_; 
float distancia(int echo, int trig) {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  // EL PULSO DURA AL MENOS 10 uS EN ESTADO ALTO
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  // MEDIR EL TIEMPO EN ESTADO ALTO DEL PIN "ECHO" EL PULSO ES PROPORCIONAL A LA DISTANCIA MEDIDA
  int tiempo = pulseIn(echo, HIGH);

  // LA VELOCIDAD DEL SONIDO ES DE 340 M/S O 29 MICROSEGUNDOS POR CENTIMETRO
  // DIVIDIMOS EL TIEMPO DEL PULSO ENTRE 58, TIEMPO QUE TARDA RECORRER IDA Y VUELTA UN CENTIMETRO LA ONDA SONORA
  int dist = tiempo / 29;

  return dist;
}
