#include <WiFi.h>
#include <HTTPClient.h>
#include <SoftwareSerial.h>

SoftwareSerial rs232(27, 26);//rx-tx
void setup() {
  Serial.begin(9600);
  rs232.begin(9600);
}

void loop() {

  Serial.println(rs232.available());//muestra en el monitor serial la cantidad de bytes disponibles en el bufer serie
  buf();                        //Vacía el búfer de entrada de datos.
  delay(200);                          //espera medio segundo.
}



void buf(){
 // Serial.println(rs232.available());
  while(rs232.available()>0){
   rs232.flush();  
  }
}
