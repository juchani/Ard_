#ifdef ESP8266
#include <ESP8266WiFi.h>
#else //ESP32
#include <WiFi.h>
#endif
#include <ModbusIP_ESP8266.h>
#include <Wiegand.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 17

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);



#define PIN_D0 21
#define PIN_D1 22

Wiegand wiegand;
volatile int id;
unsigned int au16data[16];//0=a,1=b,2=enable,3=error
unsigned int data_ = 0;
//Modbus Registers Offsets
const int SENSOR_HREG = 100;
const int SENSOR_HREG_1 = 110;

//ModbusIP object
ModbusIP mb;

long ts;

void setup() {
  Serial.begin(9600);

  WiFi.begin("Insertec-AP", "Omicron22.");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.begin(9600);
  wiegand.onReceive(receivedData, "Card readed: ");
  wiegand.onReceiveError(receivedDataError, "Card read error: ");
  wiegand.onStateChange(stateChanged, "State changed: ");
  wiegand.begin(Wiegand::LENGTH_ANY, true);
  pinMode(PIN_D0, INPUT);
  pinMode(PIN_D1, INPUT);
  attachInterrupt(digitalPinToInterrupt(PIN_D0), pinStateChanged, CHANGE);
  attachInterrupt(digitalPinToInterrupt(PIN_D1), pinStateChanged, CHANGE);
  pinStateChanged();

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  mb.server();		//Start Modbus IP
  // Add SENSOR_IREG register - Use addIreg() for analog Inputs
  mb.addHreg(SENSOR_HREG);
  mb.addHreg(SENSOR_HREG_1);
  sensors.begin();
  ts = millis();
}

void loop() {
  noInterrupts();
  wiegand.flush();
  interrupts();
  mb.task();
  if (millis() > ts + 100) {
    ts = millis();
    mb.Hreg(SENSOR_HREG,ds_sensor() );
    // mb.Hreg(SENSOR_HREG_1,678);
  }
  delay(10);
}
