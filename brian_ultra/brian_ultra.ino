int pinecho = 12;
int pintrigger =11;
int  led=13;
int tiempo, distancia;

void setup() {
  Serial.begin(9600);
  pinMode(pinecho, INPUT);
  pinMode(pintrigger, OUTPUT);
  pinMode(led,OUTPUT);
  }

void loop() {
  // ENVIAR PULSO DE DISPARO EN EL PIN "TRIGGER"
  int d=promedio(10);

  // ENVIAR EL RESULTADO AL MONITOR SERIAL
  Serial.print(d);
  Serial.println(" cm");
if(analogRead<400){
  digitalWrite(led,1);

}
else{
  digitalWrite(led,0);
}

  delay(200);

}

int promedio(int n)
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
  return(distancia);
}
