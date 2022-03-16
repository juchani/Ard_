#include <Servo.h>
Servo myservo;
int piso[4] = {4, 5, 2, 3};
int st1[4];
void setup() {
  Serial.begin(9600);
  pinMode(piso[0], INPUT_PULLUP);
  pinMode(piso[1], INPUT_PULLUP);
  pinMode(piso[2], INPUT_PULLUP);
  pinMode(piso[3], INPUT_PULLUP);

  myservo.attach(8);
}
void loop() {
  if (digitalRead(piso[0]) == 0) {
  myservo.attach(8);
    myservo.write(140);
    delay(500);
    myservo.detach();
    delay(500);
  }
  if (digitalRead(piso[3]) == 0) {
    myservo.write(10);
    delay(15);
  }
  if(digitalRead(piso[1])==0){
    myservo.write(90);
   delay(15);
    }
  Serial.print(" ");
  Serial.print(digitalRead(piso[1]));
  Serial.print(" ");
  Serial.print(digitalRead(piso[2]));
  Serial.print(" ");
  Serial.println(digitalRead(piso[3]));
  //myservo.write(180);
  // delay(15);
}
