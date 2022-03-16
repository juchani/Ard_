#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

String MACadd = "20:16:11:29:70:26";
uint8_t address[6]  = {0x20, 0x16, 0x11, 0x29, 0x70, 0x26};
//uint8_t address[6]  = {0x11, 0x1D, 0xA5, 0x02, 0xC3, 0x22};
String name = "HC-05";
char *pin = "1234"; //<- standard pin would be provided by default
bool connected;

void setup() {
  Serial.begin(115200);
  
  SerialBT.begin("ESP32test", true); 
  SerialBT.setPin(pin);
  Serial.println("The device started in master mode, make sure remote BT device is on!"); 
  
  connected = SerialBT.connect(name);
  
  if(connected) {
    Serial.println("Connected Succesfully!");
  } else {
    while(!SerialBT.connected(10000)) {
      Serial.println("Failed to connect. Make sure remote device is available and in range, then restart app."); 
    }
  }
  // disconnect() may take upto 10 secs max
  if (SerialBT.disconnect()) {
    Serial.println("Disconnected Succesfully!");
  }
  // this would reconnect to the name(will use address, if resolved) or address used with connect(name/address).
  SerialBT.connect();
}

void loop() {
  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) {
    Serial.write(SerialBT.read());
  }
  delay(20);
}