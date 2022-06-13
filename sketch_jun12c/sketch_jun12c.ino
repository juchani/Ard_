/**********************************************************************************
 * TITULO: Código ESP32 - FIREBASE
 * AUTOR: Jhimmy Astoraque Durán
 * DESCRIPCION: Este es el código del capítulo 6 de la serie ESP32 del canal
 * CANAL YOUTUBE: https://www.youtube.com/c/jadsatv
 * © 2020
 * *******************************************************************************/

#include <WiFi.h>
#include "FirebaseESP32.h"

// Credenciales wifi
#define WIFI_SSID "Familia Juchani"
#define WIFI_PASSWORD "8884992sc"

// Credenciales Proyecto Firebase
#define FIREBASE_HOST "https://espwemos-972c2-default-rtdb.firebaseio.com/"
#define FIREBASE_AUTH "ky3L8gzNDCIY8ahP0lZXaoRQbgI3qZCtxfBVhUQT"

// Firebase Data object
FirebaseData firebaseData;

// Si deseamos una ruta especifica
String nodo = "/Sensores";
bool iterar = true;


void setup() 
{
  Serial.begin(115200);
  Serial.println();

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Conectado al Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
}


void loop() 
{
    while(iterar){
        // leer datos
        Firebase.getInt(firebaseData, nodo + "/sensor1");
        Serial.println(firebaseData.intData());
        delay(250);
        Firebase.getString(firebaseData, nodo + "/sensor2");
        Serial.println(firebaseData.stringData());
        //getJSON,  getFloat

        // escribir datos
//        Firebase.setInt(firebaseData, nodo + "/sensor1", 512);       
//        Firebase.setString(firebaseData, nodo + "/sensor2", "On");
//        Firebase.setBool(firebaseData, nodo + "/iterar", false);

        // push de datos
        Firebase.pushInt(firebaseData, nodo + "/lecturas", 256);
        delay(100);
        Firebase.pushInt(firebaseData, nodo + "/lecturas", 128);
        delay(100);
        Firebase.pushInt(firebaseData, nodo + "/lecturas", 64);
        delay(100);
        Firebase.pushInt(firebaseData, nodo + "/lecturas", 32);
        
        iterar = false;
        Firebase.end(firebaseData);
    }
} // End Loop
