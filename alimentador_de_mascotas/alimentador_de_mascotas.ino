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
  //ULTRASONICO
  pinMode(echo1, INPUT);
  pinMode(echo2, INPUT);
  pinMode(echo3, INPUT);
  pinMode(echo4, INPUT);
  pinMode(trig, OUTPUT);
  Serial.println("Ready");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  if (! rtc.begin()) {
    while (1) delay(10);
  }

  if (rtc.lostPower()) {
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}

void loop() {
  rtc_act();
  lcd.setCursor(5, 0);
  lcd.print(hora_);
  lcd.print(":");
  lcd.print(minuto_); 
  lcd.setCursor(1, 1); 
  lcd.print("H1: ");
  lcd.print("8");
  lcd.print(":");
  lcd.print("30 ");
  lcd.print("D:");
  lcd.print("3 "); 
  delay(1000);
  lcd.clear();
  lcd.setCursor(5, 0);
  lcd.print(hora_);
  lcd.print(":");
  lcd.print(minuto_); 
  lcd.setCursor(1, 1); 
  lcd.print("H2: ");
  lcd.print("12");
  lcd.print(":");
  lcd.print("30 ");
  lcd.print("D:");
  lcd.print("3 "); 
  delay(1000);
  lcd.clear();
  lcd.setCursor(5, 0);
  lcd.print(hora_);
  lcd.print(":");
  lcd.print(minuto_); 
  lcd.setCursor(1, 1); 
  lcd.print("H3: ");
  lcd.print("18");
  lcd.print(":");
  lcd.print("30 ");
  lcd.print("D:");
  lcd.print("3 "); 
  delay(1000);
  lcd.clear();
}

void rtc_act() {
  DateTime now = rtc.now();
  hora_ = now.hour();
  minuto_ = now.minute();
 // alarma();
}
