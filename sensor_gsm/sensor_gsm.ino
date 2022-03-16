#include <SoftwareSerial.h>
SoftwareSerial gsm(2, 3); //SIM800L Tx & Rx is connected to Arduino #3 & #2
String texto = "";
String sms[] = {"alarma activada", "alarma desactivada"};
bool estado = 1;
byte  c = 0;
int relay = 8;
int pir = 9;
void setup()
{

  Serial.begin(9600);
  gsm.begin(9600);
  gsm.println("AT");
  pinMode(relay, OUTPUT);
  pinMode(pir, INPUT);
  digitalWrite(relay, estado);

}

void loop()
{
  llamada();
  Serial.println(digitalRead(pir));
 if(digitalRead(pir)==1){
//  mensaje();
   
 }
  
}

void llamada()
{
  while (gsm.available())
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
       delay(7000);
      
    }
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
}
