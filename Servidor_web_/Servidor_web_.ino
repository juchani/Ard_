#include <SPI.h>
#include <MFRC522.h>
#include <EEPROM.h>
#define RST_PIN	4    //Pin 9 para el reset del RC522
#define SS_PIN	15   //Pin 10 para el SS (SDA) del RC522
MFRC522 mfrc522(SS_PIN, RST_PIN); ///Creamos el objeto para el RC522
//#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#include "config.h"  // Sustituir con datos de vuestra red
#include "Server.hpp"
#include "ESP8266_Utils.hpp"
#define led 2
byte ActualUID[4]; //almacenará el código del Tag leído
byte Usuario1[4]= {0x9A, 0xA7, 0x73, 0x82} ; //código del usuario 1
bool acceso=0;
void setup(void) 
{
SPI.begin();        //Iniciamos el Bus SPI
	mfrc522.PCD_Init(); // Iniciamos el MFRC522
  clase1="OFF";
  clase2="OFF";
  EEPROM.begin(512);  
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  pinMode(0,OUTPUT);
  pinMode(5,OUTPUT);
  digitalWrite(0,HIGH);
  digitalWrite(5,HIGH);
  ConnectWiFi_STA();
  InitServer();
acceso= EEPROM.read(1);
}
 


void loop()
{
  server.handleClient();
  if ( mfrc522.PICC_IsNewCardPresent()) 
        {  
  		//Seleccionamos una tarjeta
            if ( mfrc522.PICC_ReadCardSerial()) 
            {
                  // Enviamos serialemente su UID
                  Serial.print(F("Card UID:"));
                  for (byte i = 0; i < mfrc522.uid.size; i++) {
                          Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
                          Serial.print(mfrc522.uid.uidByte[i], HEX);   
                          ActualUID[i]=mfrc522.uid.uidByte[i];          
                  } 
                  Serial.print("     ");                 
                  //comparamos los UID para determinar si es uno de nuestros usuarios  
                  if(compareArray(ActualUID,Usuario1)){
                    Serial.println("Acceso concedido...");
                    EEPROM.write(1, !acceso);
                    acceso=!acceso;

                  }
                  else{
                    Serial.println("Acceso denegado...");
                  }
                    
                  
                  // Terminamos la lectura de la tarjeta tarjeta  actual
                  mfrc522.PICC_HaltA();
          
            }}

digitalWrite(led,!acceso);
}

//Función para comparar dos vectores
 boolean compareArray(byte array1[],byte array2[])
{
  if(array1[0] != array2[0])return(false);
  if(array1[1] != array2[1])return(false);
  if(array1[2] != array2[2])return(false);
  if(array1[3] != array2[3])return(false);
  return(true);
}