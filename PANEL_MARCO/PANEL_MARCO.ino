#include <WiFi.h>
#include <ESPmDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
TaskHandle_t Task1;
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
  ///////////CONFIGURACION IP/////////
  byte in1 = 192;
  byte in2 = 168;
  byte ih1 = 0;
  byte ih2 = 200;
  IPAddress gateway(192, 168, 1, 1);
  IPAddress subnet(255, 255, 255, 0);
  IPAddress ip(in1, in2, ih1, ih2);
  WiFi.setSleep(false);
  WiFi.mode(WIFI_STA);
  //
  WiFi.config(ip, gateway, subnet);
  WiFi.begin("Familia Juchani", "8884992sc");
  //WiFi.begin("Insertec-AP", "Omicron22.");
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("Connection Failed! Rebooting...");
    delay(5000);
    ESP.restart();
  }

  otta();
  ArduinoOTA.begin();
  Serial.println("Ready");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  ArduinoOTA.handle();
}
