#include <TFT_eSPI.h>
#include <SPI.h>
#include <SoftwareSerial.h>
#define led 33
String texto;
SoftwareSerial rs232(26, 27);
TFT_eSPI tft = TFT_eSPI();
bool est;
String st[2] = {"ENCENDIDO", "APAGADO"};

void setup(void) {

  //tft.init();
  //tft.setRotation(1);
  rs232.begin(9600);
  Serial.begin(9600);
 // pinMode(led, OUTPUT);
}

void loop() {
  /*tft.fillScreen(TFT_BLACK);
  tft.setCursor(0, 10, 2);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(1);
  tft.println(rs());*/
  rs();
}


String rs()
{
//  rs232.listen();
  if (rs232.available())
  {
    texto += (char)rs232.read();
    Serial.println(texto);
  }
  return texto;
}
