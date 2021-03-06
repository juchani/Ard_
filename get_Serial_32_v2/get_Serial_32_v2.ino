#include <WiFi.h>
#include <HTTPClient.h>
#include <SoftwareSerial.h>

SoftwareSerial rs232(27, 26);//0,2
const char* ssid = "Insertec-AP";
const char* password = "INSERTEC2016.";
String url = "http://clinica.solucionespymes.com/apic/savedata?list=FREND";
unsigned long lastTime = 0;
unsigned long timerDelay = 5000;
String texto = "",E;
String item_code, test_result,test_unit,ref_max,ref_min,date_time,ver="1.0.0.0";

int buzzer = 12;
int led = 13;
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
      //Serial.print(i);
      if (cero[i].indexOf("t?") > -1 && i == 0) {
        // Serial.print(" inicio");
        error = 0;
      }

      if (cero[i].indexOf("t?") > -1 && i > 0) {
        Serial.print(" error");
        error = 1;
      }
      if (cero[i].length() == 0) {
        cero[i] = "°";
      }

      //Serial.print(cero[i]);
      //Serial.print('\t');
      //Serial.println(cero[i].length());


    }

    if (error == 0) {
      //ITEM CODE
      for (int c = 10; c < 16; c++) {
        if (cero[c] != "°") {
          item_code = item_code + "$" + decoder(cero[c], 0, c);
          test_result = test_result + "$" + decoder(cero[c], 1, c);
          item_code.trim();
          test_result.trim();

        }
        //FECHA-HORA
        date_time=decoder(cero[2], 1, 2);
        date_time.trim();
        date_time.replace("-","");
        date_time.replace(":","");
        date_time.replace(" ","|");
        //DATOS REG
        for(int t=3;t<8;t++){
          E=E+"|"+decoder(cero[t],1,t);
        }
        
      }
      test_result.remove(0,1);
      item_code.remove(0, 1);
      test_result.replace(" ","%20");
      item_code.replace(" ","%20");
      Serial.print(E);
      Serial.print('\t');
      Serial.print(item_code);
      Serial.print('\t');
      Serial.print(test_result);
      Serial.print('\t');
      Serial.print(date_time);
      item_code = "";
      test_result="";
      date_time="";
      E="";
      //Serial.print(decoder(cero[i], 0, i));
    }
    for (int i; i < 20; i++) {
      cero[i] = "";
    }

  }

}


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
  if (est == 0) {
    d.remove( n - 1, d.length());
  }

  if (d.indexOf("$@  @")) {
    d.trim();
    //d = "|" + d;
    return d;
  }


}



void envio(String enlace) {
  if ((millis() - lastTime) > timerDelay) {
    if (WiFi.status() == WL_CONNECTED) {
      HTTPClient http;
      String serverPath = url + enlace;
      http.begin(serverPath.c_str());
      int httpResponseCode = http.GET();
      if (httpResponseCode > 0) {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
        String payload = http.getString();
        Serial.println(payload);
      }
      else {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
      }
      http.end();
    }
    else {
      Serial.println("WiFi Disconnected");
    }
    lastTime = millis();
  }
}
