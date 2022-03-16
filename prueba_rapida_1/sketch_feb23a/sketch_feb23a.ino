//ide
//Entrono de Desarrollo Integrado 
bool a=true; //binario 1=1,HIGH,TRUE  0=0,LOW,FALSE
int b=3;// enteros 
float c=2.3;// decimales
byte d=30;//0-255
char e="d";//caracter
String f="palabra";//palabras

void setup() {
//UART =receptor,transmisor,asincrono universal
//comunicacion serial
Serial.begin(9600);//Serial.begin(velaocidad de transmicion=baudios) 
}

void loop() {
  a=!a; //! =negación
 // asignación =
 //comparacion ==  resultado true=1,false=0
//  b=b+1;//suma 
Serial.println(b==3);
delay(1000);//pausa(tiempo milisegundos) 1000ms=1s
}
