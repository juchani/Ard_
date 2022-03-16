/// documentación

#include <Wire.h>
#define led 13
void setup() {
    Wire.begin();
  Wire.setClock(3800);
  Serial.begin(9600);
  pinMode(led,OUTPUT);
}

void loop() {
  
    Wire.beginTransmission(0x01);
  byte error = Wire.endTransmission();
  if (error == 0)
    {
      digitalWrite(led,1);
    Serial.println("presionado");

    }
   else{
      digitalWrite(led,0);
   }
  
  delay(500);

  
  

}
