
#include <Wire.h>
#include <ACROBOTIC_SSD1306.h>

void setup()
{
  Wire.begin();	
  oled.init();                      // Initialze SSD1306 OLED display
  oled.clearDisplay();              // Clear screen
  oled.setTextXY(0,0);              // Set cursor position, start of line 0
  oled.putString("ACROBOTIC");
  oled.setTextXY(1,0);              // Set cursor position, start of line 1
  oled.putString("industries");
  oled.setTextXY(2,0);              // Set cursor position, start of line 2
  oled.putString("Pasadena,");
  oled.setTextXY(2,10);             // Set cursor position, line 2 10th character
  oled.putString("CA");
}

void loop()
{
}
