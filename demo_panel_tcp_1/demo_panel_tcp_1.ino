#ifdef ESP8266
#include <ESP8266WiFi.h>
#else //ESP32
#include <WiFi.h>//#include <ESP32Ping.h>//
#endif
#include <ModbusIP_ESP8266.h>
#include <ESPmDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include <Arduino.h>

#include "AiEsp32RotaryEncoder.h"
#include "Arduino.h"

#define ROTARY_ENCODER_A_PIN 22
#define ROTARY_ENCODER_B_PIN 23
#define ROTARY_ENCODER_BUTTON_PIN 13
#define ROTARY_ENCODER_VCC_PIN -1 
#define ROTARY_ENCODER_STEPS 1

AiEsp32RotaryEncoder rotaryEncoder = AiEsp32RotaryEncoder(ROTARY_ENCODER_A_PIN, ROTARY_ENCODER_B_PIN, ROTARY_ENCODER_BUTTON_PIN, ROTARY_ENCODER_VCC_PIN, ROTARY_ENCODER_STEPS);





int retardo = 3;        // Tiempo de retardo en milisegundos (Velocidad del Motor)
int dato_rx;            // valor recibido en grados
int numero_pasos = 7;   // Valor en grados donde se encuentra el motor
String leeCadena;       // Almacena la cadena de datos recibida

IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

int uid16data[20];//0=a,1=b,2=enable,3=error
int M1_HREG = 1;
int M2_HREG = 2;
int E1_HREG = 3;
int E2_HREG = 4;
int ST1_HREG = 5;
int ST2_HREG = 6;
int in4 = 32;
int in3 = 33;
int in2 = 25;
int in1 = 26;
/*
int in4 = 5;
int in3 = 4;
int in2 = 2;
int in1 = 15;
*/
ModbusIP mb;
TaskHandle_t tcp_loop;
long ts;
void tcp0code( void * pvParameters );
///// DATOS DE ENCODER
//45° 198 2559
//90°  398 5110
//135° 598 7679
//180° 798 10239
//225° 998 12799
//270° 1202 15359
//315° 1401 17919
//359° 1598 20423
//360° 1604 20479

void rotary_loop()
{
    if (rotaryEncoder.encoderChanged())
    {
        Serial.print("Value: ");
        Serial.println(rotaryEncoder.readEncoder());
        uid16data[2]=rotaryEncoder.readEncoder();
        uid16data[6]=map(rotaryEncoder.readEncoder(),0,1606,0,360);
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

//////
void setup() {
  Serial.begin(9600);
  Serial2.begin(9600);
  ////////ENCODER//////////
    rotaryEncoder.begin();
    rotaryEncoder.setup(readEncoderISR);
    bool circleValues = false;
    rotaryEncoder.setBoundaries(-1000, 3000, circleValues); //minValue, maxValue, circleValues true|false (when max go to min and vice versa)
    rotaryEncoder.disableAcceleration();                    //acceleration is now enabled by default - disable if you dont need it
  ////////DUAL CORE//////
  xTaskCreatePinnedToCore(
    tcp0code,   /* Task function. */
    "tcp_",     /* name of task. */
    10000,       /* Stack size of task */
    NULL,        /* parameter of the task */
    1,           /* priority of the task */
    &tcp_loop,      /* Task handle to keep track of created task */
    0);
  //////////CONFIGURACION M1
  pinMode(in1, OUTPUT);    // Pin 11 conectar a IN4
  pinMode(in2, OUTPUT);    // Pin 10 conectar a IN3
  pinMode(in3, OUTPUT);     // Pin 9 conectar a IN2
  pinMode(in4, OUTPUT);     // Pin 8 conectar a IN1


  ///////////CONFIGURACION IP/////////
  byte in1 = 192;
  byte in2 = 168;
  byte ih1 = 0;
  byte ih2 = 201;

  IPAddress ip(in1, in2, ih1, ih2);

  WiFi.setSleep(false);
  WiFi.mode(WIFI_STA);
  //
  WiFi.config(ip, gateway, subnet);
  WiFi.begin("Familia Juchani", "8884992sc");
  //WiFi.begin("Insertec-AP", "Omicron22.");
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("Connection Failed! Rebooting...");
    delay(5000);
    ESP.restart();
  }
  otta();
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  mb.server();
  mb.addHreg(M1_HREG);
  mb.addHreg(M2_HREG);
  mb.addHreg(E1_HREG);
  mb.addHreg(E2_HREG);
  mb.addHreg(ST1_HREG);
  mb.addHreg(ST2_HREG);
  ts = millis();

}


void loop() {
 // ArduinoOTA.handle();
  motor_1();
  rotary_loop();
  uid16data[1] = mb.Hreg(M1_HREG);
  


}
