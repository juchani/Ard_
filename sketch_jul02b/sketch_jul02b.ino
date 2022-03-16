void setup() {
  Serial.begin(9600);
}

void loop() {
int valor=analogRead(A0);//0 0||5v---1023
float t=map(valor,0,1023,0,5000);
Serial.println(t/10);
}
