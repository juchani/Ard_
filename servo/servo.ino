#include <Servo.h>
Servo s1;
Servo s2;
int led = 13;
int b1 = 8;
int b2 = 9;
void setup() {
  Serial.begin(9600);
  pinMode(b1, INPUT);
  pinMode(b2, INPUT);
  s1.attach(10);
  s2.attach(11);
}

void loop() {
  Serial.println(digitalRead(b1));
  if (digitalRead(b1)==1) {
s1.write(0);
delay(3000);
  }
  else{
s1 .write(90);
delay(500);
  }
  if (digitalRead(b2)==1) {
s2.write(0);
delay(500);
  }
  else{
s2 .write(90);
delay(500);
  }

}
