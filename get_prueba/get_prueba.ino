#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
 
// Sustituir por los datos de vuestro WiFi
const char* ssid = "Insertec-AP";
const char* password = "INSERTEC2016.";
String url = "http://clinica.solucionespymes.com/apic/savedata?list=FREND|12418373|3350141|124|WVPIO5JU|302063|COVID-19%20IgG$COVID-19%20IgM|Positive%20(55.17)$Negative%20(0.25)||0|2|20130905|133450|1.0.0.0";

void setup()
{
   Serial.begin(115200);
   delay(10);
 
   // Conectar WiFi
   WiFi.begin(ssid, password);
   while (WiFi.status() != WL_CONNECTED) 
      delay(500);
}
 
void loop()
{
   HTTPClient http;
   WiFiClient client;
 
   if (http.begin(client, url)) //Iniciar conexión
   {
      Serial.print("[HTTP] GET...\n");
      int httpCode = http.GET();  // Realizar petición
 
      if (httpCode > 0) {
         Serial.printf("[HTTP] GET... code: %d\n", httpCode);
 
         if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
            String payload = http.getString();   // Obtener respuesta
            Serial.println(payload);   // Mostrar respuesta por serial
         }
      }
      else {
         Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }
 
      http.end();
   }
   else {
      Serial.printf("[HTTP} Unable to connect\n");
   }
 
   delay(10000);
} 
