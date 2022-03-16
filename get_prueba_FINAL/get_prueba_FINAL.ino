#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <SoftwareSerial.h>
SoftwareSerial rs232(0, 2);
const char* ssid = "Insertec-AP";
const char* password = "INSERTEC2016.";
String url = "http://clinica.solucionespymes.com/apic/savedata?list=FREND";
int buzzer = 12;
int led = 13;
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
    bip(50, 1);
  }
  digitalWrite(led, 1);
  bip(250, 1);

}

void loop()
{
  updateSerial();

  delay(2);


}

void updateSerial()
{
  if (rs232.available())
  {
    Serial.println(".....................");

    String cero[20] = rs232.readStringUntil(':');
    Serial.println(cero[0]);
    cero[0].remove(0, 30);
    cero[1].remove(0, 1);
    cero[1].replace(" ", "|");
    cero[1].replace("-", "");
    cero[3].remove(2, 20);
    cero[4].remove(0, 1);
    cero[4].remove(cero[4].length() - 8, cero[4].length());
    //cero[4].replace(" ", "");
    cero[5].remove(cero[5].length() - 9, cero[5].length());
    cero[5].replace(" ", "");
    cero[6].remove(cero[6].length() - 9, cero[6].length());
    cero[6].replace(" ", "");
    cero[7].remove(cero[7].length() - 10, cero[7].length());
    cero[7].replace(" ", "");
    cero[8].remove(cero[8].length() - 4, cero[8].length());
    cero[8].replace(" ", "");
    cero[9].remove(cero[9].length() - 16, cero[9].length());
    cero[9].replace(" ", "");
    cero[10].remove(cero[10].length() - 14, cero[10].length());
    cero[10].replace(" ", "");
    String lista = '|' + cero[4] + '|' + cero[5] + '|' + cero[6] + '|' + cero[7] + '|' + cero[8] +  "|COVID-19 igG$COVID-19 igM|" + cero[10] + '$' + cero[11] + '|' + '|' + '|' + '|' + cero[1] + cero[2] + cero[3] + '|' + "1.0";
    lista.replace("\n", "");
    //lista.replace(" ", "");
    lista.replace("\r", "");
    Serial.println(lista);
    enviar(lista);
  }

}

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




void bip (int t, int v) {
  int i = 0;
  while (i < v) {
    digitalWrite(buzzer, 1);
    delay(t);
    digitalWrite(buzzer, 0);
    delay(t);
    i++;
  }
}
