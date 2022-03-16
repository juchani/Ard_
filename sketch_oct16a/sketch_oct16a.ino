#include <Wire.h>
#define boton 3

void setup() {
pinMode(boton,INPUT);
Wire.begin(0xa0);
}

void loop() {
  if(digitalRead(boton)){
    Wire.beginTransmission(0xa0);
    Wire.write(0xff);
    //Wire.write(1);
    Wire.endTransmission();
  }
}
