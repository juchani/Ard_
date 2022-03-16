#include <WiFi.h>
#include <HTTPClient.h>
#include <SoftwareSerial.h>

SoftwareSerial rs232(27, 26);//rx-tx
const char* ssid = "Insertec-AP";/////red
const char* password = "INSERTEC2016.";//////////pasword
String url = "http://clinica.solucionespymes.com/apic/savedata?list=FREND";
unsigned long lastTime = 0;
unsigned long timerDelay = 5000;
String texto = "", E;
String item_code, test_result, test_unit, ref_max, ref_min, date_time, ver = "1.0.0.0";
String total[8] = {E, item_code, test_result, test_unit, ref_max, ref_min, date_time, ver};
int buzzer = 12,led = 13;
int vacio=0,limite=0;
String fecha;
bool error = 0;
void setup()
{
  Serial.begin(9600);
  rs232.begin(9600);
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());

  Serial.println("Timer set to 5 seconds (timerDelay variable), it will take 5 seconds before publishing the first reading.");

  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);
  delay(10);
  digitalWrite(led, 0);
}

void loop()
{


  updateSerial();

  delay(10);
}


String li(bool n, String l) {
  l.trim();
  if (n == 0) {
    l = l + "|";
  }
  else {
    l = "|" + l + "|";
  }
  return l;
}
