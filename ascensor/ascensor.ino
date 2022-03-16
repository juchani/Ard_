#define b1 2
#define b2 3
#define b3 4
#define b4 5
#define m1 6
#define m2 7
#define s1 8
#define s2 9
#define s3 10
#define s4 11
int teclado=2;
int piso=1;
void setup() {
  pinMode(b1,INPUT);
  pinMode(b2,INPUT);
  pinMode(b3,INPUT);
  pinMode(b4,INPUT);
  pinMode(s1,INPUT);
  pinMode(s2,INPUT);
  pinMode(s3,INPUT);
  pinMode(s4,INPUT);
  pinMode(m1,OUTPUT);
  pinMode(m2,OUTPUT);
  Serial.begin(9600);
}

void loop() {
if(digitalRead(b1)){
  teclado=1;
}
if(digitalRead(b2)){
  teclado=2;
}
if(digitalRead(b3)){
  teclado=3;
}
if(digitalRead(b4)){
  teclado=4;
}
if(digitalRead(s1)){
  piso=1;
}
if(digitalRead(s2)){
  piso=2;
}
if(digitalRead(s3)){
  piso=3;
}
if(digitalRead(s4)){
  piso=4;
}
Serial.print(teclado);
Serial.print('\t');
Serial.println(piso);
delay(10);
if(piso==teclado){
  parar();
}
if(piso>teclado){
  abajo();
}
if(piso<teclado){
  arriba();
}
}



void arriba(){
  digitalWrite(m1,LOW);
  digitalWrite(m2,HIGH);
}
void abajo(){
  digitalWrite(m1,HIGH);
  digitalWrite(m2,LOW);;
}
void parar(){
digitalWrite(m1,LOW);
digitalWrite(m2,LOW);  
  
}
