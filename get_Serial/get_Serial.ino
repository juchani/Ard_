#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <SoftwareSerial.h>

SoftwareSerial rs232(0, 2);
const char* ssid = "Insertec-AP";
const char* password = "INSERTEC2016.";
String url = "http://clinica.solucionespymes.com/apic/savedata?list=FREND";
String texto = "";
int buzzer = 12;
int led = 13;
String fecha;
bool error = 0;
void setup()
{
  Serial.begin(9600);
  rs232.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);
  delay(10);
  digitalWrite(led, 0);
  WiFi.mode(WIFI_STA); //para que no inicie el SoftAP en el modo normal
  // Conectar WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);

  }
  digitalWrite(led, 1);

}

void loop()
{
  updateSerial();

  delay(20);


}

void updateSerial()
{
  if (rs232.available())
  {
    //texto += (char)rs232.read();
    //if (texto.indexOf("") > -1){
    String cero[20] = rs232.readStringUntil('\n');
    for (int i; i < 20; i++) {
      // Serial.print(i);
      if (cero[i].indexOf("t?") > -1 && i == 0) {
        Serial.print(" inicio");
        error = 0;
      }

      if (cero[i].indexOf("t?") > -1 && i > 0) {
        Serial.print(" error");
        error = 1;
      }
      if (error == 0) {
        Serial.print(decoder(cero[i], 1, i));
      }
      //Serial.println(cero[i]);


    }
    for (int i; i < 20; i++) {
      cero[i] = "";
    }

  }

}
/*
  void enviar(String d) {
  HTTPClient http;
  WiFiClient client;
  d = url + d;
  if (http.begin(client, d)) //Iniciar conexión
  {
    Serial.print("[HTTP] GET...\n");
    int httpCode = http.GET();  // Realizar petición
    if (httpCode == 200) {
      bip(200, 2);
    }

    if (httpCode > 0) {
      Serial.printf("[HTTP] GET... code: %d\n", httpCode);

      if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
        String payload = http.getString();   // Obtener respuesta
        Serial.println(payload);   // Mostrar respuesta por serial

      }
    }
    else {
      bip(100, 3);
      Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());

    }

    http.end();
  }
  else {
    Serial.printf("[HTTP} Unable to connect\n");
  }
  }
*/

String decoder(String d, bool est, int c) {
  String d1 = d;
  int n = d.indexOf(":");
  d1.remove(n - 1, d1.length());

  if (c < 2 && c > 3) {
    d.replace(" ", "");
    //d.replace("\n","");
  }
  if (est == 1) {
    d.remove(0, n + 1);
  }

  if (d.indexOf("$@  @")) {
    d.trim();
    d = "|" + d;
    return d;
  }

}
