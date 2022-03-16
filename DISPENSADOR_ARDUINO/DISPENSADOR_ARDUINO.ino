#include <LCD_I2C.h>
LCD_I2C lcd(0x27);
#define motor 3
#define buzzer 2
#define LED_ROJO 9
#define LED_VERDE 8
byte velocidad = 200;
float tempC;
int tempPin = 0;
const int Trigger = 4;  //Pin digital 4 para el Trigger del sensor
const int Echo = 5;     //Pin digital 5 para el Echo del sensor

void setup() {
  Serial.begin(9600);  //iniciailzamos la comunicación
  lcd.begin();
  lcd.backlight();
  pinMode(Trigger, OUTPUT);    //pin como salida
  pinMode(Echo, INPUT);        //pin como entrada
  digitalWrite(Trigger, LOW);  //Inicializamos el pin con 0
  pinMode(motor, OUTPUT);      //pin como salida
  pinMode(buzzer, OUTPUT);     //pin como salida
  pinMode(LED_ROJO, OUTPUT);   //pin como salida
  pinMode(LED_VERDE, OUTPUT);  //pin como salida
}

void loop() {

  long t;  //timepo que demora en llegar el eco
  long d;  //distancia en centimetros

  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);  //Enviamos un pulso de 10us
  digitalWrite(Trigger, LOW);

  t = pulseIn(Echo, HIGH);  //obtenemos el ancho del pulso
  d = t / 59;               //escalamos el tiempo a una distancia en cm
  if (d < 8) {
    digitalWrite(LED_VERDE,HIGH);
    digitalWrite(buzzer,HIGH);
encendido(100);
  }
  else {
    digitalWrite(LED_VERDE,LOW);
    digitalWrite(buzzer,LOW);
    apagado();
  }

  temperatura();
  /*
  Serial.print("Distancia: ");
  Serial.print(d);      //Enviamos serialmente el valor de la distancia
  Serial.print("cm");
  Serial.println();
  delay(100);          //Hacemos una pausa de 100ms
  */
 delay(300);
    lcd.clear();
}

void encendido(int t){
lcd.setCursor(2, 1);
    lcd.print("DISPENSANDO...");
analogWrite(motor,velocidad);
delay(t);
}


void apagado(){
analogWrite(motor,0);
}

void sonido(int t){
digitalWrite(buzzer,1);
delay(t);
digitalWrite(buzzer,0);

}


void temperatura(){
   tempC = analogRead(tempPin); 

    // Convierte el valor a temperatura
    tempC = (5.0 * tempC * 100.0)/1024.0; 

    // Envia el dato al puerto serial
    Serial.print(tempC);
    Serial.print(" grados Celsius\n");
    lcd.setCursor(0, 0);
    lcd.print("TEMPERATURA ");
    lcd.print(int(tempC));
    lcd.print(" C"); 
     
    if(tempC>36){
      digitalWrite(LED_ROJO,HIGH);
      sonido(150);
    }
    else{
    digitalWrite(LED_ROJO,LOW);
    
    }
}