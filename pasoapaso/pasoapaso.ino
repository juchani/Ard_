#include <Servo.h>
Servo servo1;
Servo servo2;
Servo servo3;
int retardo=5;// Tiempo de retardo en milisegundos (Velocidad del Motor)
int v1=0;
int v2=0;
int v3=0;

void setup() {   
   servo1.attach(7);
   servo2.attach(5);
   servo3.attach(6);             
Serial.begin(9600);     // inicializamos el puerto serie a 9600 baudios
pinMode(11, OUTPUT);    // Pin 11 conectar a IN4
pinMode(10, OUTPUT);    // Pin 10 conectar a IN3
pinMode(9, OUTPUT);     // Pin 9 conectar a IN2
pinMode(8, OUTPUT);     // Pin 8 conectar a IN1
}

void loop() {
  int x=analogRead(A0);
  x=map(x,0,1023,0,3);
  int y=analogRead(A1);
  y=map(y,0,1023,0,3);
  int z=analogRead(A2);
  z=map(z,0,1023,0,3);
  int p=analogRead(A3);
  p=map(p,0,1023,0,3);
Serial.print(x);
Serial.print(" ");
Serial.print(y);
Serial.print(" ");
Serial.print(z);
Serial.print(" ");
Serial.println(p);


if(x==2){
paso_izq();
}
if(x==0){
paso_der();
}
//limite servos
//servo 1
if(v1<0){
  v1=0;
}
if(v1>180){
  v1=180;
}
//servo 2
if(v2<0){
  v2=0;
}
if(v2>180){
  v2=180;
}
//servo 3
if(v3<0){
  v3=0;
}
if(v3>180){
  v3=180;
}
//eje servo
//servo 1
if(y==2){
v1++;
}
if(y==0){
v1--;
}
//servo 2
if(z==2){
v2++;
}
if(z==0){
v2--;
}
//servo 3
if(p==2){
v3++;
}
if(p==0){
v3--;
}
  servo1.write(v1);
  servo2.write(v2);
  servo3.write(v3);
  apagado();         // Apagado del Motor para que no se caliente
delay(10);
  
}  ///////////////////// Fin del Loop ///////////////////////////

void paso_der(){         // Pasos a la derecha
 digitalWrite(11, LOW); 
 digitalWrite(10, LOW);  
 digitalWrite(9, HIGH);  
 digitalWrite(8, HIGH);  
   delay(retardo); 
 digitalWrite(11, LOW); 
 digitalWrite(10, HIGH);  
 digitalWrite(9, HIGH);  
 digitalWrite(8, LOW);  
   delay(retardo); 
 digitalWrite(11, HIGH); 
 digitalWrite(10, HIGH);  
 digitalWrite(9, LOW);  
 digitalWrite(8, LOW);  
  delay(retardo); 
 digitalWrite(11, HIGH); 
 digitalWrite(10, LOW);  
 digitalWrite(9, LOW);  
 digitalWrite(8, HIGH);  
  delay(retardo);  
}

void paso_izq() {        // Pasos a la izquierda
 digitalWrite(11, HIGH); 
 digitalWrite(10, HIGH);  
 digitalWrite(9, LOW);  
 digitalWrite(8, LOW);  
  delay(retardo); 
 digitalWrite(11, LOW); 
 digitalWrite(10, HIGH);  
 digitalWrite(9, HIGH);  
 digitalWrite(8, LOW);  
  delay(retardo); 
 digitalWrite(11, LOW); 
 digitalWrite(10, LOW);  
 digitalWrite(9, HIGH);  
 digitalWrite(8, HIGH);  
  delay(retardo); 
 digitalWrite(11, HIGH); 
 digitalWrite(10, LOW);  
 digitalWrite(9, LOW);  
 digitalWrite(8, HIGH);  
  delay(retardo); 
}
        
void apagado() {         // Apagado del Motor
 digitalWrite(11, LOW); 
 digitalWrite(10, LOW);  
 digitalWrite(9, LOW);  
 digitalWrite(8, LOW);  
 }
