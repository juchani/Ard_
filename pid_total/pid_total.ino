#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display
///////////////////////ENTRADA-SALIDA///////////////////////
int sharp1 = A0;
int sharp2 = A1;
Servo myservo;
///////////////////////////////////////////////////////


////////////////////////Variables///////////////////////
int Read = 0;
float distancia = 0.0;
float elapsedTime, time, timePrev;        //Variables para el control de tiempo
float distance_previous_error, distance_error;
int period = 50;  //tiempo de muestreo
///////////////////////////////////////////////////////


///////////////////PID///////////////////////
float kp = 8; //proporcional
float ki = 0.9; //integral
float kd = 420; //derivativo
float distance_setpoint = 16;           //
float PID_p, PID_i, PID_d, PID_total;
///////////////////////////////////////////////////////



void setup() {

  Serial.begin(9600);
  myservo.attach(7);  // 
  myservo.write(125); //
  pinMode(sharp1, INPUT);
  pinMode(sharp2, INPUT);
  time = millis();
  lcd.init();                      // 
  lcd.backlight();

}

void loop() {


  if (millis() > time + period)
  {
    distance_setpoint = sensor2(300);
    time = millis();
    distancia = sensor1(300);
    Serial.print(distance_setpoint);
    Serial.print("  ");
    Serial.print(distancia);
    Serial.print("  ");
    Serial.println(PID_total + 30);
//    lcd,clear();
    lcd.setCursor(0, 0);
    lcd.print("SHARP 1: ");
    lcd.print(int(distancia));
    lcd.print(" cm");
    lcd.setCursor(0, 1);
    lcd.print("Set Point: ");
    lcd.print(int(distance_setpoint));
    lcd.print(" cm");
    // lcd.setCursor(0, 1);
    // lcd.print("*** second line.");
    distance_error = distance_setpoint - distancia;
    PID_p = kp * distance_error;
    float dist_diference = distance_error - distance_previous_error;
    PID_d = kd * ((distance_error - distance_previous_error) / period);

    if (-3.1 < distance_error && distance_error < 3.1)
    {
      PID_i = PID_i + (ki * distance_error);
    }
    else
    {
      PID_i = 0;
    }

    PID_total = PID_p + PID_i + PID_d;
    PID_total = map(PID_total, -150, 150, 0, 150);//

    if (PID_total < 20) {
      PID_total = 20;
    }
    if (PID_total > 160) {
      PID_total = 160;
    }

    myservo.write(PID_total + 30);
    distance_previous_error = distance_error;
  }
}











int sensor1(int n)
{
  long sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum = sum + analogRead(sharp1);
  }
  float adc = sum / n;
  float distance_cm = 28940.1 * pow(adc, -1.16);
  return (distance_cm/2);
}

int sensor2(int j)
{
  long sum = 0;
  for (int i = 0; i < j; i++)
  {
    sum = sum + analogRead(sharp2);
  }
  float adc = sum / j;
  float distance_cm = 28940.1 * pow(adc,-1.15);//-1.126
 // float distance_cm = 28940.1 * pow(adc, -1.16);
  return (distance_cm/2);
}
