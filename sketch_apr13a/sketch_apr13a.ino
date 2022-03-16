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
  gsm.begin(9600);
  gsm.println("AT");
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
  Serial.print(digitalRead(pir));
  Serial.print("  ");
  Serial.println(estado);
  digitalWrite(13, digitalRead(pir));
  if (digitalRead(pir)) {
    mensaje();
  }
  delay(500);
}

void llamada()
{
  //gsm.listen();
  while (gsm.available() > 0)
  {
    texto += (char)gsm.read();
    Serial.println(texto);
    if (texto.indexOf("RING") > -1) {
      Serial.println("aceptado");
      estado = !estado;
      delay(3000);
      gsm.println("ATH");
      digitalWrite(relay, estado);
      texto = "";
      delay(3000);

    }
  }
    while (gsm.available() > 0) {
      gsm.flush();
    }
}


void mensaje() {
  gsm.println("ATA");
  delay(3000);
  gsm.println("ATH");
  delay(4000);
  gsm.println("AT+CMGF=1"); // Configuring TEXT mode
  delay(500);//          72578594
  gsm.println("AT+CMGS=\"71066743\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
  delay(500);
  gsm.println("EL SENSOR DETECTO MOVIMIENTO"); //text content
  delay(500);
  gsm.write(26);
  delay(15000);
}
