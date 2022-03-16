#include "RTClib.h"
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <SPI.h>
#include <EEPROM.h>
//#include <NTPClient.h>
//#include <WiFi.h> // for WiFi shield
//#include <WiFiUdp.h>
//#include <ESPmDNS.h>
//#include <ArduinoOTA.h>

#define EEPROM_SIZE 150
#define b1 2
#define b2 3//2
#define enter 12
#define buzzer 0
#define en_p 1
#define TFT_CS        -1 // PyBadge/PyGamer display control pins: chip select
#define TFT_RST       15 // Display reset
#define TFT_DC        16 // Display data/command select
#define gris 0x3fb73b
RTC_DS3231 rtc;
char daysOfTheWeek[7][12] = {"DOM", "LUN", "MAR", "MIE", "JUE", "VIE", "SAB"};
String mes_[]{"","ENE","FEB","MAR","ABR","MAY","JUN","JUL","AGO","SEP","OCT","NOV","DIC"};
