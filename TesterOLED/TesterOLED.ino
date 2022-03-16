#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#define led_estatus 10
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define ONE_WIRE_BUS 4
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
int numberOfDevices; // Number of temperature devices found
DeviceAddress tempDeviceAddress; // We'll use this variable to store a found device address
String modo[]={"OFF","ON"};
String DIR;
float tempC;
void setup(void)
{
    if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
pinMode(led_estatus,OUTPUT);
  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();

  Serial.begin(9600);
  Serial.println("Dallas Temperature IC Control Library Demo");
sensors.begin();
numberOfDevices = sensors.getDeviceCount();
  Serial.print("Locating devices...");
  Serial.print("Found ");
  Serial.print(numberOfDevices, DEC);
  Serial.println(" devices.");
}

// function to print the temperature for a device
void printTemperature(DeviceAddress deviceAddress)
{
  // method 1 - slower
  //Serial.print("Temp C: ");
  //Serial.print(sensors.getTempC(deviceAddress));
  //Serial.print(" Temp F: ");
  //Serial.print(sensors.getTempF(deviceAddress)); // Makes a second call to getTempC and then converts to Fahrenheit

  // method 2 - faster
  float tempC = sensors.getTempC(deviceAddress);
  if(tempC == DEVICE_DISCONNECTED_C) 
  {
    Serial.println("Error: Could not read temperature data");
    return;
  }
  Serial.print("Temp C: ");
  Serial.println(tempC);
}

void loop(void)
{ 
  
  
  display.clearDisplay();

  display.setTextSize(1); // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print("RESOLUCION: ");
  display.print(sensors.getResolution(tempDeviceAddress));
  display.println(" BIT");
  display.print("MODO PARASITO: ");
  display.println(modo[sensors.isParasitePowerMode()]);
  display.print("ADDR: ");
  display.println(DIR);
  display.print("TEMPERATURA: ");
  display.print(tempC);
    display.print(" C");
  display.display();      // Show initial text
  delay(100);
  DIR="";
  // Loop through each device, print out address
  for(int i=0;i<numberOfDevices; i++)
  {
    // Search the wire for address
    if(sensors.getAddress(tempDeviceAddress, i))
	{
		Serial.print("Found device ");
		Serial.print(i, DEC);
		Serial.print(" with address: ");
		printAddress(tempDeviceAddress);
		Serial.println();
		
		Serial.print("Setting resolution to ");
		
		
		Serial.print("Resolution actually set to: ");
		Serial.print(sensors.getResolution(tempDeviceAddress), DEC); 
		Serial.println();
	}
  else{
		Serial.print("Found ghost device at ");
		Serial.print(i, DEC);
		Serial.print(" but could not detect address. Check power and cabling");
	}
  }
    Serial.print("Requesting temperatures...");
  sensors.requestTemperatures(); // Send the command to get temperatures
  Serial.println("DONE");
  
  Serial.print("Parasite power is: "); 
  if (sensors.isParasitePowerMode()) Serial.println("ON");
  else Serial.println("OFF");
  
  // Loop through each device, print out temperature data
  for(int i=0;i<numberOfDevices; i++)
  {
    // Search the wire for address
    if(sensors.getAddress(tempDeviceAddress, i))
	{
		// Output the device ID
		Serial.print("Temperature for device: ");
		Serial.println(i,DEC);
	 tempC = sensors.getTempC(tempDeviceAddress);
  if(tempC == DEVICE_DISCONNECTED_C) 
  {

    Serial.println("Error: Could not read temperature data");
    return;
  }
  else{
    digitalWrite(led_estatus,1);
    delay(50);
    digitalWrite(led_estatus,0);
    delay(50);
  }
  Serial.print("Temp C: ");
  Serial.println(tempC);
		// It responds almost immediately. Let's print out the data
		//printTemperature(tempDeviceAddress); // Use a simple function to print out the data
	} 
	//else ghost device! Check your power requirements and cabling
	
  }

}

// function to print a device address
void printAddress(DeviceAddress deviceAddress)
{
  for (uint8_t i = 0; i < 8; i++)
  {
    if (deviceAddress[i] < 16) Serial.print("0");
    Serial.print(deviceAddress[i], HEX);
    DIR=DIR+String(deviceAddress[i],HEX);
  }
}
