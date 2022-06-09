#ifdef ESP8266
#include <ESP8266WiFi.h>
#else //ESP32
#include <WiFi.h>//#include <ESP32Ping.h>//
#endif
#include <ModbusIP_ESP8266.h>
#include <Wiegand.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 13
#define PIN_D0 37
#define PIN_D1 38
#define LED_STD 12
#define RL 21
OneWire ds(ONE_WIRE_BUS);
Wiegand wiegand;
volatile int id;
unsigned int uid16data[16];//0=a,1=b,2=enable,3=error
unsigned int data_ = 65000;
//Modbus Registers Offsets
const int UID1_HREG = 100;
const int UID2_HREG = 101;
const int FCODE_HREG = 102;
const int EN_ISTS = 103;
const int DS_HREG = 105;
const int RL_COIL = 106;
bool en_wg;
ModbusIP mb;
TaskHandle_t tcp_loop;
long ts;
void setup() {
  Serial.begin(9600);
  xTaskCreatePinnedToCore(
    tcp0code,   /* Task function. */
    "tcp_",     /* name of task. */
    10000,       /* Stack size of task */
    NULL,        /* parameter of the task */
    1,           /* priority of the task */
    &tcp_loop,      /* Task handle to keep track of created task */
    0);
//WiFi.mode(WIFI_STA);
  WiFi.begin("Insertec-AP", "Omicron22.");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  //  Serial.begin(9600);

  WiFi.setSleep(false);

  wiegand.onReceive(receivedData, "Card readed: ");
  wiegand.onReceiveError(receivedDataError, "Card read error: ");
  wiegand.onStateChange(stateChanged, "State changed: ");
  wiegand.begin(Wiegand::LENGTH_ANY, true);
  pinMode(PIN_D0, INPUT);
  pinMode(PIN_D1, INPUT);
  pinMode(LED_STD, OUTPUT);
  pinMode(RL, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(PIN_D0), pinStateChanged, CHANGE);
  attachInterrupt(digitalPinToInterrupt(PIN_D1), pinStateChanged, CHANGE);
  pinStateChanged();

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  mb.server();		//Start Modbus IP
  mb.addHreg(UID1_HREG);
  mb.addHreg(UID2_HREG);
  mb.addHreg(FCODE_HREG);
  mb.addHreg(DS_HREG);
  mb.addIsts(EN_ISTS);
  mb.addCoil(RL_COIL);
  ts = millis();
}


void loop() {
  noInterrupts();
  wiegand.flush();
  interrupts();
  ds_sensor();
  digitalWrite(LED_STD, en_wg);
  digitalWrite(RL, mb.Coil(RL_COIL));
  //  mb.task();
}
