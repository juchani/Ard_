#include <Wire.h>
#include <WiFi.h>
#include <WebServer.h>
#include <EEPROM.h>
#include <TFT_eSPI.h>
#include <SPI.h>
//-------------------
TFT_eSPI tft = TFT_eSPI();

//-------------------VARIABLES GLOBALES--------------------------
int contconexion = 0;
unsigned long previousMillis = 0;
String t="BUSCANDO";
int cargando;
char ssid[50];
char pass[50];

const char *ssidConf = "FREND";
const char *passConf = "12345678";

String mensaje = "";
//-----------CODIGO HTML PAGINA DE CONFIGURACION---------------
String pagina = "<!DOCTYPE html>"
                "<html>"
                "<head>"
                "<title>NanoEntek</title>"
                "<meta charset='UTF-8'>"
                "</head>"
                "<body>"
                "</form>"
                "<form action='guardar_conf' method='get'>"
                "SSID:<br><br>"
                "<input class='input1' name='ssid' type='text'><br>"
                "PASSWORD:<br><br>"
                "<input class='input1' name='pass' type='password'><br><br>"
                "<input class='boton' type='submit' value='GUARDAR'/><br><br>"
                "</form>"
                "<a href='escanear'><button class='boton'>ESCANEAR</button></a><br><br>";

String paginafin = "</body>"
                   "</html>";

//------------------------SETUP WIFI-----------------------------
void setup_wifi() {
  // Conexión WIFI
  WiFi.mode(WIFI_STA); //para que no inicie el SoftAP en el modo normal
  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED and contconexion < 50) { //Cuenta hasta 50 si no se puede conectar lo cancela
    ++contconexion;
    buscando();
    delay(250);
  }
  if (contconexion < 50) {
    conectado();
    Serial.println("WiFi conectado");
    Serial.println(WiFi.localIP());
    digitalWrite(13, HIGH);
  }
  else {
    error();
    delay(4000);
     ESP.restart();
  }
}

//--------------------------------------------------------------
WiFiClient espClient;
WebServer server(80);
//--------------------------------------------------------------








//------------------------SETUP-----------------------------
void setup() {

  pinMode(13, OUTPUT); // D7
  Wire.begin();
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);
  delay(1000);
  // Inicia Serial
  Serial.begin(115200);
  Serial.println("");

  EEPROM.begin(512);

  pinMode(35, INPUT);  //D5
  if (digitalRead(35) == 0) {

    modoconf();
  }

  leer(0).toCharArray(ssid, 50);
  leer(50).toCharArray(pass, 50);
  
  setup_wifi();
}

//--------------------------LOOP--------------------------------
void loop() {

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= 5000) { //envia la temperatura cada 5 segundos
    previousMillis = currentMillis;
    Serial.println("Funcionado...");
  }
  
}
