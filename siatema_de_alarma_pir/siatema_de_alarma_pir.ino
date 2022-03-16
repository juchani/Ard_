//DECLARACION DE VARIABLES
bool estado;
void setup() {
pinMode(7,INPUT);//pinMode(pin,estado);estado=entrada(sensores) o salida(actuadores)
pinMode(8,OUTPUT);
Serial.begin(9600);//comunicacion Serial (UART=RECEPTOR,TRANSMISOR, ASINCRONO, UNIVERSAL)
}

void loop() {
estado=digitalRead(7);//digitalRead(pin); si hay voltaje envia un 1
digitalWrite(8,estado);//digitalWrite(pin,valor);0=nada,1=5v
Serial.println(estado);//imprime el valor de estado
delay(100);//da una pausa de 100 milisegundos
}
