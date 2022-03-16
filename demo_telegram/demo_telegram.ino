#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pin = Adafruit_PWMServoDriver();

// Datos para conexión wifi
#define WIFI_SSID "control relay"
#define WIFI_PASSWORD "12345678"
// Telegram BOT Token (Get from Botfather)
#define BOT_TOKEN "2034661532:AAHMxy18pBN8TvZaYYXF8xaTZXQPpA2Oc-U"
// definimos los pines 
int conversor[]={0,4096};
bool estado_1;
bool estado_2;
bool estado_3;
bool estado_4;
bool estado_5;
bool estado_6;
bool estado_7;
bool estado_8;
bool estado_9;
bool estado_10;
// variables de estados 
String estados[]={"Encendido","Apagado"};
String mensaje;
const unsigned long BOT_MTBS = 10; // mean time between scan messages

X509List cert(TELEGRAM_CERTIFICATE_ROOT);
WiFiClientSecure secured_client;
UniversalTelegramBot bot(BOT_TOKEN, secured_client);
unsigned long bot_lasttime; // last time messages' scan has been done

const int ledPin = LED_BUILTIN;
int ledStatus = 0;

void handleNewMessages(int numNewMessages)
{
  Serial.print("handleNewMessages ");
  Serial.println(numNewMessages);

  for (int i = 0; i < numNewMessages; i++)
  {
    String chat_id = bot.messages[i].chat_id;
    String text = bot.messages[i].text;

    String from_name = bot.messages[i].from_name;
    if (text == "/Relay1")
    {
      estado_1=!estado_1;
      pin.setPWM(0, conversor[estado_1], conversor[!estado_1]);
      mensaje="El relay 1 esta "+estados[estado_1] ;
      bot.sendMessage(chat_id, mensaje, "");
    }
    if (text == "/Relay2")
    {
      estado_2=!estado_2;
      pin.setPWM(1, conversor[estado_2], conversor[!estado_2]);
      mensaje="El relay 2 esta " + estados[estado_2] ;
      bot.sendMessage(chat_id, mensaje, "");
    }
    if (text == "/Relay3")
    {
      estado_3=!estado_3;
      pin.setPWM(2, conversor[estado_3], conversor[!estado_3]);
      mensaje="El relay 3 esta " + estados[estado_3] ;
      bot.sendMessage(chat_id, mensaje, "");
    }
    if (text == "/Relay4")
    {
      estado_4=!estado_4;
      pin.setPWM(3, conversor[estado_4], conversor[!estado_4]);
      mensaje="El relay 4 esta " + estados[estado_4] ;
      bot.sendMessage(chat_id, mensaje, "");
    }
    if (text == "/Relay5")
    {
      estado_5=!estado_5;
      pin.setPWM(4, conversor[estado_5], conversor[!estado_5]);
      mensaje="El relay 5 esta " + estados[estado_5] ;
      bot.sendMessage(chat_id, mensaje, "");
    }
    if (text == "/Relay6")
    {
      estado_6=!estado_6;
      pin.setPWM(5, conversor[estado_6], conversor[!estado_6]);
      mensaje="El relay 6 esta " + estados[estado_6] ;
      bot.sendMessage(chat_id, mensaje, "");
    }
    if (text == "/Relay7")
    {
      estado_7=!estado_7;
      pin.setPWM(6, conversor[estado_7], conversor[!estado_7]);
      mensaje="El relay 7 esta " + estados[estado_7] ;
      bot.sendMessage(chat_id, mensaje, "");
    }
    if (text == "/Relay8")
    {
      estado_8=!estado_8;
      pin.setPWM(7, conversor[estado_8], conversor[!estado_8]);
      mensaje="El relay 8 esta " + estados[estado_8] ;
      bot.sendMessage(chat_id, mensaje, "");
    }
    if (text == "/Relay9")
    {
      estado_9=!estado_9;
      pin.setPWM(8, conversor[estado_9], conversor[!estado_9]);
      mensaje="El relay 9 esta " + estados[estado_9] ;
      bot.sendMessage(chat_id, mensaje, "");
    }
    if (text == "/Relay10")
    {
      estado_10=!estado_10;
      pin.setPWM(9, conversor[estado_10], conversor[!estado_10]);
      mensaje="El relay 10 esta " + estados[estado_10] ;
      bot.sendMessage(chat_id, mensaje, "");
    }

    if (text == "/status")
    {
      String st = "Bienvenido al sistema de control, " + from_name + ".\n";
      st += "Estos son los estados de todos los relays.\n\n";
      st += "/Relay_1 : esta "+estados[estado_1]+"\n";
      st += "/Relay_2 : esta "+estados[estado_2]+"\n";
      st += "/Relay_3 : esta "+estados[estado_3]+"\n";
      st += "/Relay_4 : esta "+estados[estado_4]+"\n";
      st += "/Relay_5 : esta "+estados[estado_5]+"\n";
      st += "/Relay_6 : esta "+estados[estado_6]+"\n";      
      st += "/Relay_7 : esta "+estados[estado_7]+"\n";
      st += "/Relay_8 : esta "+estados[estado_8]+"\n";
      st += "/Relay_9 : esta "+estados[estado_9]+"\n";
      st += "/Relay_10 : esta "+estados[estado_10]+"\n";
      bot.sendMessage(chat_id, st, "Markdown");      
    }

    if (text == "/start")
    {
      String welcome = "Bienvenido al sistema de control, " + from_name + ".\n";
      welcome += "Estos son los comandos que puedes usar.\n\n";
      welcome += "/Relay_1 : Cambia el estado del relay\n";
      welcome += "/Relay_2 : Cambia el estado del relay\n";
      welcome += "/Relay_3 : Cambia el estado del relay\n";
      welcome += "/Relay_4 : Cambia el estado del relay\n";
      welcome += "/Relay_5 : Cambia el estado del relay\n";
      welcome += "/Relay_6 : Cambia el estado del relay\n";
      welcome += "/Relay_7 : Cambia el estado del relay\n";
      welcome += "/Relay_8 : Cambia el estado del relay\n";
      welcome += "/Relay_9 : Cambia el estado del relay\n";
      welcome += "/Relay_10 : Cambia el estado del relay\n";
      welcome += "/status : Muestra todos los estados de todos los relays\n";
      bot.sendMessage(chat_id, welcome, "Markdown");
    }
  }
}


void setup()
{
Serial.begin(115200);
Serial.println();
pin.begin();
pin.setPWMFreq(1000);  // Set to whatever you like, we don't use it in this demo!
estado_1=1;
estado_2=1;
estado_3=1;
estado_4=1;
estado_5=1;
estado_6=1;
estado_7=1;
estado_8=1;  
estado_9=1;
estado_10=1;
pin.setPWM(0, conversor[estado_1], conversor[!estado_1]);
pin.setPWM(1, conversor[estado_2], conversor[!estado_2]);
pin.setPWM(2, conversor[estado_3], conversor[!estado_3]);
pin.setPWM(3, conversor[estado_4], conversor[!estado_4]);
pin.setPWM(4, conversor[estado_5], conversor[!estado_5]);
pin.setPWM(5, conversor[estado_6], conversor[!estado_6]);
pin.setPWM(6, conversor[estado_7], conversor[!estado_7]);
pin.setPWM(7, conversor[estado_8], conversor[!estado_8]);    
pin.setPWM(8, conversor[estado_9], conversor[!estado_9]);
pin.setPWM(9, conversor[estado_10], conversor[!estado_10]);

  configTime(0, 0, "pool.ntp.org");      // get UTC time via NTP
  secured_client.setTrustAnchors(&cert); // Add root certificate for api.telegram.org
  Serial.print("Connecting to Wifi SSID ");
  Serial.print(WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.print("\nWiFi connected. IP address: ");
  Serial.println(WiFi.localIP());

  // Check NTP/Time, usually it is instantaneous and you can delete the code below.
  Serial.print("Retrieving time: ");
  time_t now = time(nullptr);
  while (now < 24 * 3600)
  {
    Serial.print(".");
    delay(100);
    now = time(nullptr);
  }
  Serial.println(now);

  
}

void loop()
{
 // if (millis() - bot_lasttime > BOT_MTBS)
 // {
    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);

    while (numNewMessages)
    {
      Serial.println("got response");
      handleNewMessages(numNewMessages);
      numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    }

    //bot_lasttime = millis();
 // }
}