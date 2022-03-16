String dato = "Dato : 12 ";
String a,b;
void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);

}

void loop() {

  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
  Serial.println(dato);
  a,b=decoder(dato);
  Serial.println(a);
  Serial.println(b);
  
}

String decoder(String d) {
String d1=d;
int n=d.indexOf(":");
d.remove(0,n+1);
d1.remove(n-1,d1.length());
return d,d1;
}
