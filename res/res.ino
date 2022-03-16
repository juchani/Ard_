String letra="los niños juegan";//cadena de caracteres   

void setup() {
Serial.begin(9600);
letra.remove(0,3);
Serial.println(letra);
delay(10);

}

void loop() {

}
