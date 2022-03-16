#define A1 5
#define A2 6
#define B1 9
#define B2 10
#define s1 2
#define s2 3
#define pinecho 12
#define pintrigger 11
#define velocidad 255
int tiempo, distancia;
int c;
void setup() {
Serial.begin(9600);
  pinMode(pinecho, INPUT);
  pinMode(pintrigger, OUTPUT);
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

while(ultra()<15){
parar();
}
if (digitalRead(s1)==1){
derecha();
} // adelante();
else if(digitalRead(s2)==1){
  izquierda();
}
else{
  adelante();

}
c++;
delay(1);
}

void adelante() {
  analogWrite(A2, 50);
  analogWrite(B1, 50);
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
int ultra()
{
  digitalWrite(pintrigger, LOW);
  delayMicroseconds(2);
  digitalWrite(pintrigger, HIGH);
  // EL PULSO DURA AL MENOS 10 uS EN ESTADO ALTO
  delayMicroseconds(10);
  digitalWrite(pintrigger, LOW);

  // MEDIR EL TIEMPO EN ESTADO ALTO DEL PIN "ECHO" EL PULSO ES PROPORCIONAL A LA DISTANCIA MEDIDA
  tiempo = pulseIn(pinecho, HIGH);

  // LA VELOCIDAD DEL SONIDO ES DE 340 M/S O 29 MICROSEGUNDOS POR CENTIMETRO
  // DIVIDIMOS EL TIEMPO DEL PULSO ENTRE 58, TIEMPO QUE TARDA RECORRER IDA Y VUELTA UN CENTIMETRO LA ONDA SONORA
  distancia = tiempo / 29;
distancia=distancia/2;
if(distancia>1 and distancia<100){
return(distancia);
}
  
}
