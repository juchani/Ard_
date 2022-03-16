#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#define max_dist 100
#define buzzer 12
int led[]={2,3,4};
const int trigPin = 9;
const int echoPin = 10;
long duracion;
int control_led;
int distancia;
int ultimaDistancia = 0;
LiquidCrystal_I2C lcd(0x27,16,2);
void setup() 
{
  pinMode(buzzer,OUTPUT); 
  pinMode(led[0],OUTPUT);
  pinMode(led[1],OUTPUT);
  pinMode(led[2],OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}
void loop() 
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duracion = pulseIn(echoPin, HIGH);
  distancia = (duracion * 0.034) / 2;

  if(distancia >2 && distancia < max_dist)
  {
    control_led=map(distancia,0,40,0,3);
    bip(control_led+1);
    digitalWrite(led[control_led-1],LOW);
    digitalWrite(led[control_led+1],LOW);    
    digitalWrite(led[control_led],HIGH);
    Serial.print(distancia);
    Serial.print("    ");
    Serial.print("El led "); 
    Serial.print(control_led);           
    Serial.println(" esta encendido"); 
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Distancia: "); // Prints string "Distance" on the LCD
    lcd.print(distancia);
    lcd.print(" cm");
    ultimaDistancia = distancia;
  }
  delay(50);
}




void bip(int t){
t=50*t;
digitalWrite(buzzer,HIGH);
delay(t);
digitalWrite(buzzer,LOW);
delay(t);
}