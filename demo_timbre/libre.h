
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <SPI.h>
#include <EEPROM.h>
#include <NTPClient.h>
#include <WiFi.h> // for WiFi shield
#include <WiFiUdp.h>
#include <ESPmDNS.h>
#include <ArduinoOTA.h>

#define EEPROM_SIZE 100
#define b1 35
#define b2 32
#define enter 34
#define TFT_CS        -1 // PyBadge/PyGamer display control pins: chip select
#define TFT_RST       15 // Display reset
#define TFT_DC        4 // Display data/command select
