#include "LIB.h"
TaskHandle_t Task1;
const char* ssid = "Familia Juchani";
const char* password = "8884992sc";
void tcp0code( void * pvParameters );
void setup() {
  Serial.begin(9600);
  //////////////DUAL CORE////////////

  xTaskCreatePinnedToCore(
    Task1code,   /* Task function. */
    "Task1",     /* name of task. */
    10000,       /* Stack size of task */
    NULL,        /* parameter of the task */
    1,           /* priority of the task */
    &Task1,      /* Task handle to keep track of created task */
    0);          /* pin task to core 0 */
  IPAddress gateway(192, 168, 1, 1);
  IPAddress subnet(255, 255, 255, 0);
  IPAddress ip(192, 168, 0, 200);
  WiFi.setSleep(false);
  WiFi.mode(WIFI_STA);
  WiFi.config(ip, gateway, subnet);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("Connection Failed! Rebooting...");
    delay(5000);
   ESP.restart();
  }

  otta ();
  //LCD
  lcd.begin();
  lcd.backlight();
  pinMode(bt1, INPUT);
  pinMode(bt2, INPUT);
  pinMode(bt3, INPUT);
  //ULTRASONICO
  pinMode(echo1, INPUT);
  pinMode(echo2, INPUT);
  pinMode(echo3, INPUT);
  pinMode(echo4, INPUT);
  pinMode(trig1, OUTPUT);
  pinMode(trig2, OUTPUT);
  pinMode(trig3, OUTPUT);
  pinMode(trig4, OUTPUT);
  Serial.println("Ready");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  dht.begin();

  //S1.attach(32);
  //S1.attach(33);
  if (! rtc.begin()) {
    //  while (1) delay(10);
  }
  //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  if (rtc.lostPower()) {
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
  lcd.setCursor(0, 0);
  lcd.print("HOLA MUNDO");
  delay(1000);
}

void loop() {
  rtc_act();
  pantalla();

}

void rtc_act() {
  DateTime now = rtc.now();
  hora_ = now.hour();
  minuto_ = now.minute();
  // alarma();
}

void pantalla() {
  lcd.setCursor(0, 0);
  lcd.print(hora_);
  lcd.print(parpadeo[st]);
  lcd.print(minuto_);
  delay(500);
  st=!st;
  //lcd.clear();

}
void reserva_comida() {

  S2.write(90);
}
void dispensador_comida() {
  S1.write(90);
}
int menu_1(){
  
}
