#include <Adafruit_Fingerprint.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <OneWire.h>
OneWire ibutton (7);
byte buffer[20];//lista
byte Usuario1[8] = {0x1,0xC6, 0x71, 0xB4, 0x1, 0x0, 0x0, 0x84} ;

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

SoftwareSerial mySerial(8, 9);

Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

#define relay1 10
#define relay2 16
#define relay3 14
#define relay4 15
#define buzzer 6
uint8_t id;
void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  Serial.begin(9600);
  finger.begin(57600);
  delay(5);
  finger.getParameters();
  finger.getTemplateCount();
  id =3;
}

void loop()  // run over and over again
{
  getFingerprintID();
  delay(50);  //don't ned to run this at full speed.
  if (!ibutton.search (buffer)) {
    ibutton.reset_search();
    delay(200);
    return;
  }
  for (int x = 0; x < 8; x++) {
    Serial.print(buffer[x], HEX);
    Serial.print(" ");
  }
  if(comparar(buffer,Usuario1)){
  bip();
  bip();
  display.clearDisplay();
  display.setTextSize(1); // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(40, 30);
  display.print("REGISTRO ");
  display.println(id);
  display.print("   COLOQUE SU HUELLA ");
  display.display();
   Serial.print("\n acceso correcto \n ");
   
   while (!  getFingerprintEnroll() ); 
 //  ESP.restart();
  }
  else{
    Serial.println("acceso denegado");
  }
}
