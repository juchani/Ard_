#include <Servo.h>
Servo s1;
Servo s2;
Servo s3;
Servo s4;
Servo s5;
int servo1;
int servo2;
int servo3;
int servo4;
int servo5;
void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  s1.attach(8);
  s2.attach(9);
  s3.attach(10);
  s4.attach(11);
  s5.attach(12);
}


void loop() {
  long tiempo = millis(); //tiempo antes de iniciar la lectura
  int V_EMG = sensor_m(300); //lectura de emg
  tiempo = millis() - tiempo; //milisegundos que duró la lectura

  Serial.println(V_EMG);
  if (V_EMG > 70) {
    servo1 = 180;
    servo2 = 180;
    servo3 = 180;
    servo4 = 180;
    servo5 = 180;
    delay(100);
  }
  else {
servo1 = 0;
    servo2 = 0;
    servo3 = 0;
    servo4 = 0;
    servo5 = 0;
  }
  mano(servo1, servo2, servo3, servo4, servo5);
  //delay(100);

}




int sensor_m(int n)
{
  long suma = 0;
  for (int i = 0; i < n; i++)
  {
    suma = suma + analogRead(A0);
  }
  float adc = suma / n;

  return (adc);
}

void mano(byte v1, byte v2, byte v3, byte v4, byte v5) {
  s1 .write(v1);
  s2 .write(v2);
  s3 .write(v3);
  s4 .write(v4);
  s5 .write(v5);
  delay(25);
}
