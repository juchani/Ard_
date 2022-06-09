#include "libre.h"
Adafruit_ST7789 tft = Adafruit_ST7789( TFT_CS, TFT_DC, TFT_RST);
//WiFiUDP ntpUDP;
//NTPClient timeClient(ntpUDP, "europe.pool.ntp.org", -14400, 60000);
#define lim 30
const char* ssid = "Familia Juchani";
const char* password = "8884992sc";
int hora_ = 1, minuto_ = 2, duracion_ = 3;
String ss[13] = {};
int c = 0, cc = 0, b,enc,prev_enc;
int add_hora[lim] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,20, 21, 22, 23, 24, 25, 26, 27, 28, 29};
int add_minuto[lim] = { 30, 31, 32, 33, 34, 35, 36, 37, 38, 39,40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59};
int add_duracion[lim] = {60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79,80,81,82,83,84,85,86,87,88,89};
int add_estado[lim] = {90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109,110, 111, 112, 113, 114, 115, 116, 117, 118, 119};
int hora[lim], minuto[lim], duracion[lim], estado[lim];
void barrido();
void set_hora();
int reg_hora,reg_minuto,reg_duracion,reg_rep,reg_addr;
String dia;
int dia_,mes,ann;
void setup()   {
//  EEPROM.begin();
    EEPROM.begin(EEPROM_SIZE);//esp8266
  // EEPROM.commit();
  //WiFi.begin(ssid, password);
  //timeClient.begin();
  for (int i = 0; i < lim; i++) {
    hora[i] = EEPROM.read(add_hora[i]);
    minuto[i] = EEPROM.read(add_minuto[i]);
    duracion[i] = EEPROM.read(add_duracion[i]);
    estado[i] = EEPROM.read(add_estado[i]);
  }
   
 
  tft.init(240, 240, SPI_MODE2);    // SPI_MODE3 es esp32
  barrido(1);
  pinMode(b1, INPUT_PULLUP);
  pinMode(b2, INPUT_PULLUP);
  pinMode(enter, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
  pinMode(en_p,OUTPUT);
  digitalWrite(buzzer, 1);
  digitalWrite(en_p, 1);
  tft.setRotation(0);
  if (! rtc.begin()) {
  tft.setCursor(30, 18);             // move cursor to position (28, 27) pixel
  tft.print("ERROR");
    while (1) delay(10);
  }
 
  if (rtc.lostPower()) {
      rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
  // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  barrido();
}
void loop() {
 // ArduinoOTA.handle();
 // ntp_con();
 rtc_act();
  bot(lim-1,0);
  if (!digitalRead(enter)) {
  set_hora(c);
  }
  //capa_1();
  front();
  b++;
  cc++;
  delay(1);
  barrido(1);
  dormir();
}

/*
void ntp_con() {
  timeClient.update();
  hora_ = timeClient.getHours();
  minuto_ = timeClient.getMinutes();
}*/

void rtc_act(){
  DateTime now = rtc.now();
  hora_ = now.hour();
  minuto_ = now.minute();
  ann=now.year();
   mes=now.month();
   dia_=now.day();
  dia=daysOfTheWeek[now.dayOfTheWeek()];
  alarma();
}
