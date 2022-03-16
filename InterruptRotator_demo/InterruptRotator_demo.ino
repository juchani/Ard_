
#include <Arduino.h>
#include <RotaryEncoder.h>

#define PIN_IN1 2
#define PIN_IN2 3

RotaryEncoder *encoder = nullptr;


void checkPosition()
{
  encoder->tick(); // just call tick() to check the state.
}




void setup()
{
  Serial.begin(9600);
  while (!Serial)
    ;
  Serial.println("InterruptRotator example for the RotaryEncoder library.");

  // setup the rotary encoder functionality

  // use FOUR3 mode when PIN_IN1, PIN_IN2 signals are always HIGH in latch position.
  // encoder = new RotaryEncoder(PIN_IN1, PIN_IN2, RotaryEncoder::LatchMode::FOUR3);

  // use FOUR0 mode when PIN_IN1, PIN_IN2 signals are always LOW in latch position.
  // encoder = new RotaryEncoder(PIN_IN1, PIN_IN2, RotaryEncoder::LatchMode::FOUR0);

  // use TWO03 mode when PIN_IN1, PIN_IN2 signals are both LOW or HIGH in latch position.
  encoder = new RotaryEncoder(PIN_IN1, PIN_IN2, RotaryEncoder::LatchMode::TWO03);

  // register interrupt routine
  attachInterrupt(digitalPinToInterrupt(PIN_IN1), checkPosition, CHANGE);
  attachInterrupt(digitalPinToInterrupt(PIN_IN2), checkPosition, CHANGE);
} // setup()


// Read the current position of the encoder and print out when changed.
void loop()
{
  static int pos = 0;

  encoder->tick(); // just call tick() to check the state.

  int newPos = encoder->getPosition();
  if (pos != newPos) {
 /*   Serial.print("pos:");
    Serial.print(newPos);
    Serial.print(" dir:");
    Serial.println((int)(encoder->getDirection()));*/
    pos = newPos;
  }
int angulo=map(pos,0,19,0,180);
Serial.println(angulo);
   
} 
