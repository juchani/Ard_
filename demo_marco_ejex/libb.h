#include <WiFi.h>
#include <ESPmDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include <WiFi.h>
#include <ModbusIP_ESP8266.h>
#include "AiEsp32RotaryEncoder.h"
#include "Arduino.h"

//VARIABLES
#define VT_PIN 34
#define AT_PIN 35

int enc;
int ang;


//Modbus Registers Offsets
const int X_HREG = 100;
const int AZ_HREG = 101;
const int Z_HREG = 102;
const int G_HREG = 103;
const int H_HREG = 104;
const int ENC_HREG = 105;
const int ANG_HREG = 106;
const int Y_HREG = 107;
const int LDR_HREG = 108;
const int C_HREG = 109;
const int V_HREG = 110;

int x = 10, az = 360, z, g, h, old_az;

//ModbusIP object
ModbusIP mb;


long ts;
const char* ssid = "Familia Juchani";
const char* password = "8884992sc";
//Encoder
#define ROTARY_ENCODER_A_PIN 22
#define ROTARY_ENCODER_B_PIN 23
#define ROTARY_ENCODER_BUTTON_PIN 13
#define ROTARY_ENCODER_VCC_PIN -1
#define ROTARY_ENCODER_STEPS 1

AiEsp32RotaryEncoder rotaryEncoder = AiEsp32RotaryEncoder(ROTARY_ENCODER_A_PIN, ROTARY_ENCODER_B_PIN, ROTARY_ENCODER_BUTTON_PIN, ROTARY_ENCODER_VCC_PIN, ROTARY_ENCODER_STEPS);

void rotary_loop()
{
  if (rotaryEncoder.encoderChanged())
  {
    Serial.print("Value: ");
    Serial.println(rotaryEncoder.readEncoder());
    enc = rotaryEncoder.readEncoder();

    ang = map(rotaryEncoder.readEncoder(), 0, 1606, 1, 360);
    // if(){

    // }
  }
  if (rotaryEncoder.isEncoderButtonClicked())
  {
    //     rotary_onButtonClick();
  }
}

void IRAM_ATTR readEncoderISR()
{
  rotaryEncoder.readEncoder_ISR();
}
