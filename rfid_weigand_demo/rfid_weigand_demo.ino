#include <Wiegand.h>
#define PIN_D0 21
#define PIN_D1 12

Wiegand wiegand;
Modbus slave(1, 0, TXEN);
volatile int id;
unsigned int au16data[16];//0=a,1=b,2=enable,3=error
int c = 0;
void setup() {
  slave.begin( 19200 );
  wiegand.onReceive(receivedData, "Card readed: ");
  wiegand.onReceiveError(receivedDataError, "Card read error: ");
  wiegand.onStateChange(stateChanged, "State changed: ");
  wiegand.begin(Wiegand::LENGTH_ANY, true);
  pinMode(PIN_D0, INPUT);
  pinMode(PIN_D1, INPUT);
  attachInterrupt(digitalPinToInterrupt(PIN_D0), pinStateChanged, CHANGE);
  attachInterrupt(digitalPinToInterrupt(PIN_D1), pinStateChanged, CHANGE);
  pinStateChanged();
}


void loop() {
  noInterrupts();
  wiegand.flush();
  interrupts();

  if (c > 1000) {

  }
  slave.poll( au16data, 16 );
  delay(1);
  c++;
}


void pinStateChanged() {
  wiegand.setPin0State(digitalRead(PIN_D0));
  wiegand.setPin1State(digitalRead(PIN_D1));
}

void stateChanged(bool plugged, const char* message) {

}

void receivedData(uint8_t* data, uint8_t bits, const char* message) {
  uint8_t bytes = (bits + 7) / 8;
  String demo, a, b, c, d, e;

  for (int i = 0; i < bytes; i++) {
    demo = demo + String(data[i] >> 4, 16);
    demo = demo + String(data[i] & 0xF, 16);
  }
  c = String(demo[0]) + String(demo[1]);
  d = String(demo[2]) + String(demo[3]);
  e = String(demo[4]) + String(demo[5]);
  unsigned int m = hexToDec(demo);
  demo = hexToDec(demo);
  for (int i = 0; i < demo.length(); i++) {
    if (i <= ((demo.length() - 1) / 2)) {
      a = a + demo[i];
    }
    else {
      b = b + demo[i];
    }
  }
  au16data[0] = 152;
  au16data[1] = 2; //b.toInt();
 


}

// Notifies when an invalid transmission is detected
void receivedDataError(Wiegand::DataError error, uint8_t* rawData, uint8_t rawBits, const char* message) {

  uint8_t bytes = (rawBits + 7) / 8;
  for (int i = 0; i < bytes; i++) {
    //   Serial.print(rawData[i] >> 4, 16);
    //  Serial.print(rawData[i] & 0xF, 16);

  }


}

unsigned long hexToDec(String hexString) {

  unsigned long decValue = 0;
  long nextInt;

  for (int i = 0; i < hexString.length(); i++) {

    nextInt = int(hexString.charAt(i));
    if (nextInt >= 48 && nextInt <= 57) nextInt = map(nextInt, 48, 57, 0, 9);
    if (nextInt >= 65 && nextInt <= 70) nextInt = map(nextInt, 65, 70, 10, 15);
    if (nextInt >= 97 && nextInt <= 102) nextInt = map(nextInt, 97, 102, 10, 15);
    nextInt = constrain(nextInt, 0, 15);
    decValue = (decValue * 16) + nextInt;
  }

  return decValue;
}
