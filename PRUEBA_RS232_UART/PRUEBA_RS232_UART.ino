#include <SoftwareSerial.h>
SoftwareSerial rs232(27, 26);//rx-tx
void setup() {
 Serial.begin(9600);//
  rs232.begin(9600);//RS232
}

void loop() {
 rs232.println("HOLA MUNDO");

}
