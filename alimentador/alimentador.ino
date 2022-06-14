#include <WiFi.h>
#include "FirebaseESP32.h"
#include <LCD_I2C.h>
#include "RTClib.h"
#include "DHT.h"
#include <ESP32Servo.h>
//constantes
#define DHTPIN 23       //pin para el dht
#define DHTTYPE DHT11   // DHT 11
#define limite_c 2      //limite para el contador 
#define limite_h 60     //setpoint humedad 
//configuracion de los botones
#define b1 35
#define b2 34
#define b3 39
//bombas de agua
#define m1 32
#define m2 33
//configuracion de sensores ultrasonicos
#define echo4 15
#define trig4 2
#define echo3 4
#define trig3 16
#define echo2 17
#define trig2 5
#define echo1 18
#define trig1 19
//configuracion del ventilador
#define ventilador 27
//limites
#define desp_comida 9
#define desp_agua 6
#define res_agua 10
#define res_comida 5
//configuracion de wifi
#define WIFI_SSID "Familia Juchani"
#define WIFI_PASSWORD "8884992sc"
// Credenciales Proyecto Firebase
#define FIREBASE_HOST "https://espwemos-972c2-default-rtdb.firebaseio.com/"
#define FIREBASE_AUTH "ky3L8gzNDCIY8ahP0lZXaoRQbgI3qZCtxfBVhUQT"
//objetos
FirebaseData firebaseData;
LCD_I2C lcd(0x27, 16, 2);
RTC_DS3231 rtc;
DHT dht(DHTPIN, DHTTYPE);
Servo M1;
Servo M2;
//variables
int ind;     //indice
int hora[] =     {12, 2, 3};  
int minuto[] =   {30, 20, 39};
int duracion[] = {4,  3, 4};
int  hora_ ;  //hora actual RTC
int  minuto_; //minuto actual RTC

String parpadeo[] = {":", " "};
String puntero[] = {"", " "};
bool st;
bool bucle = 1;
int enc, enc_prev; //variables para detectar un cambio de minutos 
int h,t ;            //humedad y temperatura
int fr_comida,fr_agua;
void setup() {
  dht.begin();
  lcd.begin();
  lcd.backlight();
  Serial.begin(9600);
  ////////config pines
  pinMode(b1, INPUT);
  pinMode(b2, INPUT);
  pinMode(b3, INPUT);
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(ventilador, OUTPUT);
  if (! rtc.begin()) {
    //  while (1) delay(10);
  }
  //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  if (rtc.lostPower()) {
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
  //
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Conectado al Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
  //SERVO
  M1.attach(32);
  M2.attach(33);
  //ULTRASONICO
  pinMode(echo1, INPUT);
  pinMode(trig1, OUTPUT);
  pinMode(echo2, INPUT);
  pinMode(trig2, OUTPUT);
  pinMode(echo3, INPUT);
  pinMode(trig3, OUTPUT);
  pinMode(echo4, INPUT);
  pinMode(trig4, OUTPUT);
}

void loop() {
  rtc_act();
  menu_1();
  pantalla();
  alarma();
  reserva_agua();
  reserva_comida();

}


void rtc_act() {
  DateTime now = rtc.now();
  hora_ = now.hour();
  minuto_ = now.minute();
  // alarma();
}
