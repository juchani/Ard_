#include "libre.h"

//WiFiUDP ntpUDP;
//NTPClient timeClient(ntpUDP, "europe.pool.ntp.org", -14400, 60000);
#define lim 20
const char* ssid = "Familia Juchani";
const char* password = "8884992sc";
int hora_ = 1, minuto_ = 2, duracion_ = 3;
String ss[13] = {};
int c = 0, cc = 0, b, enc, prev_enc;
int add_hora[lim] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
int add_minuto[lim] = {20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39};
int add_duracion[lim] = {40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59};
int add_estado[lim] = {60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79};
int hora[lim], minuto[lim], duracion[lim], estado[lim];
void barrido();
void set_hora();
int reg_hora, reg_minuto, reg_duracion, reg_rep, reg_addr;
void setup()   {
  //  EEPROM.begin();
  EEPROM.begin(EEPROM_SIZE);//esp32
  // EEPROM.commit();
  WiFi.begin(ssid, password);
  //timeClient.begin();
  for (int i = 0; i < 20; i++) {
    hora[i] = EEPROM.read(add_hora[i]);
    minuto[i] = EEPROM.read(add_minuto[i]);
    duracion[i] = EEPROM.read(add_duracion[i]);
    estado[i] = EEPROM.read(add_estado[i]);
  }
  demo_ota();
lcd.begin(); // If you are using more I2C devices using the Wire library use lcd.begin(false)
                 // this stop the library(LCD_I2C) from calling Wire.begin()
    lcd.backlight();
  //tft.init(240, 240, SPI_MODE2);    // SPI_MODE3 es esp32
  barrido(1);
  pinMode(b1, INPUT);
  pinMode(b2, INPUT);
  pinMode(enter, INPUT);
  pinMode(buzzer, OUTPUT);
//  tft.setRotation(0);
  if (! rtc.begin()) {
  //  tft.setCursor(30, 18);             // move cursor to position (28, 27) pixel
   // tft.print("ERROR");
    while (1) delay(10);
  }

  if (rtc.lostPower()) {
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
  barrido();
}
void loop() {
  // ArduinoOTA.handle();
  // ntp_con();
  rtc_act();
  bot(19, 0);
  if (!digitalRead(enter)) {
     delay(300);
    set_hora(c);
  }

  front();
  b++;
  delay(1);
  barrido(1);
}

/*
  void ntp_con() {
  timeClient.update();
  hora_ = timeClient.getHours();
  minuto_ = timeClient.getMinutes();
  }*/

void rtc_act() {
  DateTime now = rtc.now();
  hora_ = now.hour();
  minuto_ = now.minute();
  alarma();
}
