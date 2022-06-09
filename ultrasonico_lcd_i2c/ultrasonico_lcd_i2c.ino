#include <LCD_I2C.h>

LCD_I2C lcd(0x27, 16, 2);
#define buzzer 5
const int Trigger = 3;   //Pin digital 2 para el Trigger del sensor
const int Echo = 2;   //Pin digital 3 para el Echo del sensor
int led_;
int led[] = {7, 8, 9, 10, 11, 12};
void setup() {
  lcd.begin();
  lcd.backlight();
  Serial.begin(9600);//iniciailzamos la comunicación
  pinMode(Trigger, OUTPUT); //pin como salida
    pinMode(buzzer, OUTPUT); //pin como salida
  pinMode(Echo, INPUT);  //pin como entrada
  digitalWrite(Trigger, LOW);//Inicializamos el pin con 0
  for (int i = 0; i < 6; i++) {
    pinMode(led[i], OUTPUT);
  }
}

void loop()
{

  long t; //timepo que demora en llegar el eco
  long d; //distancia en centimetros

  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(Trigger, LOW);
  t = pulseIn(Echo, HIGH); //obtenemos el ancho del pulso
  d = t / 59;           //escalamos el tiempo a una distancia en cm
 lcd.setCursor(0, 1);
 lcd.print("distancia ");
 lcd.print(d);
 lcd.print("cm");
  if (d > 0 && d < 30) {
    led_ = map(d, 0, 30, 0, 7);
    n_led(led_);
    if(d<10){
      lcd.setCursor(3, 0);
 lcd.print("alarma");
      digitalWrite(buzzer,HIGH);
      delay(d*10);
      digitalWrite(buzzer,LOW);
      delay(d*10);
    }
  }
  else {
    n_led(6);
  }

  Serial.print("Distancia: ");
  Serial.print(d);      //Enviamos serialmente el valor de la distancia
  Serial.print("cm");
  Serial.println();
  delay(100);          //Hacemos una pausa de 100ms
  lcd.clear();
}

void n_led(int n) {
  for (int i = 0; i < 6; i++) {
    digitalWrite(led[i], LOW);
  }
  for (int i = 0; i < n; i++) {
    digitalWrite(led[i], HIGH);
  }
}
