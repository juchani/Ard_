#include "RTClib.h"
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <SPI.h>
#include <EEPROM.h>
//#include <NTPClient.h>
#include <WiFi.h> // for WiFi shield
#include <WiFiUdp.h>
#include <ESPmDNS.h>
#include <ArduinoOTA.h>

#define EEPROM_SIZE 200
#define b1 34
#define b2 35
#define enter 32 
#define buzzer 33
//#define buzzer 25
#define TFT_CS        -1 // PyBadge/PyGamer display control pins: chip select
#define TFT_RST       4 // Display reset
#define TFT_DC        16 // Display data/command select
RTC_DS3231 rtc;
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
