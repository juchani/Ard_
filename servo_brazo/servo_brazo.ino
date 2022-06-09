#include <Servo.h>
int vel = 5;
Servo s1;
Servo s2;
Servo s3;
Servo s4;
void setup() {
  s1.attach(5);
  s2.attach(6);
  s3.attach(7);
  s4.attach(10);
  pos_inicial();
 // delay(1000);
  peon();
 // delay(1000);
  //caballo();
  // pos_inicial();
//alfil();
}

void loop() {

}

void pos_inicial() {
  at1(90);
  at2(90);
  at3(115);
  pinza(1);
}
void peon() {
  at1(66);
  at3(67);
  at2(126);
  pinza(1);
  delay(1000);
  at1(66);
  at3(111);
  at2(133);
  pinza(1);
  delay(2000);
  at1(66);
  at2(111);
  at3(67);

  pinza(1);
}
void pinza(bool p) {
  if (p == 1) {
    s4.write(135);
  }
  else {
    s4.write(0);
  }
}
void caballo() {
  for (int i = 0; i < 2; i++) {
    at1(66);
    at3(67);
    at2(126);
    pinza(0);
    delay(1000);
    at1(66);
    at3(111);
    at2(133);
    pinza(0);
    delay(500);
    if(i==0){
    at1(66 + 15);  
    }
    if(i==1){
    at1(66 - 15);  
    }
    delay(2000);
    at1(66);
    at2(111);
    at3(67);
    pinza(0);
    delay(3000);
  }

}

void alfil(){
  for (int i = 0; i < 2; i++) {
    at1(66);
    at3(67);
    at2(126);
    pinza(0);
    delay(1000);
    at1(66);
    at3(111);
    at2(133);
    pinza(0);
    delay(50);
    if(i==0){
    at1(66 + 25);  
    }
    if(i==1){
    at1(66 - 25);  
    }
    delay(200);
    at1(66);
    at2(111);
    at3(67);
    pinza(0);
    delay(3000);
  }
}
