void pinStateChanged() {
  wiegand.setPin0State(digitalRead(PIN_D0));
  wiegand.setPin1State(digitalRead(PIN_D1));
}

void stateChanged(bool plugged, const char* message) {
  en_wg = plugged;
}

void receivedData(uint8_t* data, uint8_t bits, const char* message) {
  uint8_t bytes = (bits + 7) / 8;
  String demo, a, b, c, d, e;

  for (int i = 0; i < bytes; i++) {
    demo = demo + String(data[i] >> 4, 16);
    demo = demo + String(data[i] & 0xF, 16);
  }
  a = String(hexToDec(demo));

  demo = hexToDec(demo);
  Serial.println(demo);
  b = a.substring(0, (a.length() / 2));
  c = a.substring((a.length() / 2)+1);
 // uid16data[0] = b.toInt();
 // uid16data[1] = c.toInt();
uid16data[0] = 233;
uid16data[1] = 42018;


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
