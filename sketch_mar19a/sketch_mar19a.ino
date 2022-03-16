String g="hola",f="";

void setup() {
  Serial.begin(9600);
}

void loop() {
Serial.print(sizeof(g));
Serial.println(sizeof(f));  
}
