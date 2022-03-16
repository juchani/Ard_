ESP8266WebServer server(80);
#include "pags.hpp" 
bool acc;

void control(){
  String s;
  acc=EEPROM.read(1);
  String led = server.arg(String("led"));
  if(led.length()>0){
    
        if (led == "1" && acc==1){
         
          int estado_led1 = digitalRead(5);
          digitalWrite(5,!estado_led1);
          estado_led1 = digitalRead(5);
          if(estado_led1==0){
            clase1="ON";
          }else{
            clase1 ="OFF";
          }

       }

        if (led == "2" && acc==1){
         
          int estado_led2 = digitalRead(0);
          digitalWrite(0,!estado_led2);
          estado_led2 = digitalRead(0);
          if(estado_led2==0){
            clase2="ON";
          }else{
            clase2 ="OFF";
          }

       }
       if (led == "3"){
         digitalWrite(0,1);
         digitalWrite(5,1);
         int estado_led1 = digitalRead(5);
          
          estado_led1 = digitalRead(5);
          if(estado_led1==0){
            clase1="ON";
          }else{
            clase1 ="OFF";
          }

          int estado_led2 = digitalRead(0);
          
          estado_led2 = digitalRead(0);
          if(estado_led2==0){
            clase2="ON";
          }else{
            clase2 ="OFF";
          }

       }


           
  }

  
  s = p_inicio();
  server.send(200, "text/html",s );
}



void InitServer()
{
   server.on("/", control);
   server.on("/action", control); 


   // Iniciar servidor
   server.begin();
   Serial.println("Servidor Iniciado");
}
