#include <SoftwareSerial.h>
SoftwareSerial gsm(3, 2); //SIM800L Tx & Rx is connected to Arduino #3 & #2
String texto = "";
String sms[] = {"alarma activada", "alarma desactivada"};
bool estado = 1;
byte  c = 0;
int relay = 8;
int pir = 9;
void setup()
{
  //  delay(30000);
  Serial.begin(9600);
  Serial.println("AT");
  pinMode(relay, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(pir, INPUT);
  digitalWrite(relay, estado);
  digitalWrite(13, 1);
  delay(100);
  digitalWrite(13, 0);
}

void loop()
{
  llamada();
  digitalWrite(13, digitalRead(pir));
  if (digitalRead(pir)) {
    mensaje();
  }
  delay(500);
}

void llamada()
{
  //gsm.listen();
  while (Serial.available() > 0)
  {
    texto += (char)Serial.read();

    if (texto.indexOf("RING") > -1) {

      estado = !estado;
      delay(3000);
      Serial.println("ATH");
      digitalWrite(relay, estado);
      texto = "";
      delay(7000);

    }
  }
  
}


void mensaje() {
  Serial.println("ATA");
  delay(3000);
  Serial.println("ATH");
  delay(4000);
  Serial.println("AT+CMGF=1"); // Configuring TEXT mode
  delay(500);//          72578594
  Serial.println("AT+CMGS=\"72578594\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
  delay(500);
  Serial.println("EL SENSOR DETECTO MOVIMIENTO"); //text content
  delay(500);
  Serial.write(26);
  delay(1500);
}
