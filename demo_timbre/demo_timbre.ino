#include "libre.h"
Adafruit_ST7789 tft = Adafruit_ST7789( TFT_CS, TFT_DC, TFT_RST);
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "europe.pool.ntp.org", -14400, 60000);

const char* ssid = "Familia Juchani";
const char* password = "8884992sc";
int hora_ = 1, minuto_ = 2, duracion_ = 3;
String ss[13] = {};
int c = 0, cc = 0, b,enc;
int add_hora[20] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
int add_minuto[20] = {20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39};
int add_duracion[20] = {40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59};
int add_estado[20] = {60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79};
int hora[20], minuto[20], duracion[20], estado[20];
void barrido();
void set_hora();
int reg_hora,reg_minuto,reg_duracion,reg_rep,reg_addr;
void setup()   {
  EEPROM.begin(EEPROM_SIZE);
  // EEPROM.commit();
  WiFi.begin(ssid, password);
  timeClient.begin();
  for (int i = 0; i < 20; i++) {
    hora[i] = EEPROM.read(add_hora[i]);
    minuto[i] = EEPROM.read(add_minuto[i]);
    duracion[i] = EEPROM.read(add_duracion[i]);
    estado[i] = EEPROM.read(add_estado[i]);
  }
  demo_ota();
  Serial.begin(9600);
  Serial.println("Ready");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  tft.init(240, 240, SPI_MODE3);    // init ST7789 display 240x240 pixel
  barrido(1);
  pinMode(b1, INPUT);
  pinMode(b2, INPUT);
  pinMode(enter, INPUT);
  tft.setRotation(0);
  barrido();
}
void loop() {
  ArduinoOTA.handle();
  ntp_con();
  bot(19);
  if (digitalRead(enter)) {
  set_hora(c);
  }
  front();
  b++;
  delay(1);
  barrido(1);
}


void ntp_con() {
  timeClient.update();
  hora_ = timeClient.getHours();
  minuto_ = timeClient.getMinutes();
}
