int IN1 = 9;
int IN2 = 10;
#include <Arduino.h>
#include <RotaryEncoder.h>

#define PIN_IN1 2
#define PIN_IN2 3

int IN3 = 11;
int IN4 = 12;
int demora = 3;
int sp = 0;
int pasos = 0;
String datos;
RotaryEncoder *encoder = nullptr;


void checkPosition()
{
  encoder->tick(); // just call tick() to check the state.
}

void setup() {
  encoder = new RotaryEncoder(PIN_IN1, PIN_IN2, RotaryEncoder::LatchMode::TWO03);
  attachInterrupt(digitalPinToInterrupt(PIN_IN1), checkPosition, CHANGE);
  attachInterrupt(digitalPinToInterrupt(PIN_IN2), checkPosition, CHANGE);
  pinMode(IN1, OUTPUT);		// todos los pines como salida
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  while (Serial.available()) {
    char c = Serial.read();
    datos += c;
  }
  if (datos.length() > 0) {
    sp = datos.toInt();
  }

  static int pos = 0;

  encoder->tick(); // just call tick() to check the state.

  int newPos = encoder->getPosition();
  if (pos != newPos) {
    pos = newPos;
  }
  int angulo_m = map(pasos, 0, 754, 0, 180);
  int angulo = map(pos, 0, 19, 0, 180);
  Serial.print(angulo);
  Serial.print(" ");
  Serial.print(angulo_m);
  Serial.print(" ");
  Serial.println(pasos);
  if (sp < (angulo + 10) && sp > (angulo - 10)) {
    if (sp == angulo_m) {
      if(sp==0){
        if (sp < pasos) {
      atras();
    }
    else if (sp > pasos) {
      adelante();
    }
      }
      detener();
      datos = "";
    }
    else if (sp < angulo_m) {
      atras();
    }
    else if (sp > angulo_m) {
      adelante();
    }
    datos = "";
  }

  else if (sp < angulo) {
    atras();
  }
  else if (sp > angulo) {
    adelante();
  }



}




void atras () {
  pasos--;
  digitalWrite(IN1, HIGH); 	// paso 1
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(demora);

  digitalWrite(IN1, LOW);	// paso 2
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(demora);

  digitalWrite(IN1, LOW);	// paso 3
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(demora);

  digitalWrite(IN1, LOW);	// paso 4
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(demora);
}

void adelante() {
  pasos++;
  digitalWrite(IN1, LOW); 	// paso 1
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(demora);

  digitalWrite(IN1, LOW);	// paso 2
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(demora);

  digitalWrite(IN1, LOW);	// paso 3
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(demora);

  digitalWrite(IN1, HIGH);	// paso 4
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(demora);
}
void detener() {
  digitalWrite(IN1, LOW);	// detiene por 5 seg.
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
