
#include <Wire.h>
#define b1 7
#define b2 6

void setup() {
  Serial.begin(9600);
  Serial.println("HOLA");
 pinMode(b1,INPUT);
 pinMode(b2,INPUT);
  Wire.begin(0xA0);                // unirse al bus i2c con la direccion #23
  Wire.setClock(100000);

}


void loop() {
if(digitalRead(b1)==1){
  delay(5);
Wire.beginTransmission(0xA0);
Wire.write(0x10);
Wire.endTransmission();
delay(500);
}
if(b2){
delay(5);
}
}
