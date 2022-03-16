#define A1 5
#define A2 6
#define B1 9
#define B2 10
#define s1 2
#define s2 3
#define velocidad 255
void setup() {
Serial.begin(9600);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(B1, OUTPUT);
  pinMode(B2, OUTPUT);
  pinMode(s1, INPUT);
  pinMode(s2, INPUT); 
  attachInterrupt(digitalPinToInterrupt(s1),parar,RISING);
  attachInterrupt(digitalPinToInterrupt(s2),parar,RISING);
}

void loop() {
  Serial.println(digitalRead(s1));
//  adelante();
if (digitalRead(s1)==1){
derecha();
} // adelante();
else if(digitalRead(s2)==1){
  izquierda();
}
else{
  adelante();
delay(100);
parar();
delay(50);
}
}

void adelante() {
  digitalWrite(A2, 0);
  digitalWrite(B1, 0);
   digitalWrite(A1, 1);
  digitalWrite(B2, 1);
}

void derecha(){
  digitalWrite(B2,1);
  digitalWrite(B1,0); 
  digitalWrite(A1,1);
  digitalWrite(A2,1);  
}
void izquierda(){
  digitalWrite(A1,1);
  digitalWrite(A2,0); 
  digitalWrite(B1,1);
  digitalWrite(B2,1);      
}
void parar(){
  digitalWrite(A1, 1);
  digitalWrite(B2, 1);
digitalWrite(A2, 1);
  digitalWrite(B1, 1);  
}