#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include <ACROBOTIC_SSD1306.h>
#define ONE_WIRE_BUS 4
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
int numberOfDevices; // Number of temperature devices found
DeviceAddress tempDeviceAddress; // We'll use this variable to store a found device address
String par;
void setup(void)
{
   Wire.begin();
  oled.init();  // Initialze SSD1306 OLED display
   oled.clearDisplay();   // Clear screen
  // start serial port
  Serial.begin(9600);
  Serial.println("Dallas Temperature IC Control Library Demo");

  // Start up the library
  sensors.begin();
  
  // Grab a count of devices on the wire
  numberOfDevices = sensors.getDeviceCount();
  
  // locate devices on the bus
  Serial.print("Locating devices...");
  
  Serial.print("Found ");
  Serial.print(numberOfDevices, DEC);
  Serial.println(" devices.");

  // report parasite power requirements
  Serial.print("Parasite power is: "); 
  if (sensors.isParasitePowerMode()){
Serial.println("ON");
par="ON";
  }
   
  else {
    Serial.println("OFF");
    par="OFF";
  }
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
	//	Serial.println(TEMPERATURE_PRECISION, DEC);
		
		// set the resolution to TEMPERATURE_PRECISION bit (Each Dallas/Maxim device is capable of several different resolutions)
		//sensors.setResolution(tempDeviceAddress, TEMPERATURE_PRECISION);
		
		Serial.print("Resolution actually set to: ");
		Serial.print(sensors.getResolution(tempDeviceAddress), DEC); 
		Serial.println();
	}else{
		Serial.print("Found ghost device at ");
		Serial.print(i, DEC);
		Serial.print(" but could not detect address. Check power and cabling");
	}
  }

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
  Serial.print(tempC);
  Serial.print(" Temp F: ");
  Serial.println(DallasTemperature::toFahrenheit(tempC)); // Converts tempC to Fahrenheit
}

void loop(void)
{ 

  // call sensors.requestTemperatures() to issue a global temperature 
  // request to all devices on the bus
  Serial.print("Requesting temperatures...");
  sensors.requestTemperatures(); // Send the command to get temperatures
  Serial.println("DONE");
  
  
  // Loop through each device, print out temperature data
  for(int i=0;i<numberOfDevices; i++)
  {
    // Search the wire for address
    if(sensors.getAddress(tempDeviceAddress, i))
	{
		// Output the device ID
		Serial.print("Temperature for device: ");
		Serial.println(i,DEC);
		
		// It responds almost immediately. Let's print out the data
		printTemperature(tempDeviceAddress); // Use a simple function to print out the data
	} 
	//else ghost device! Check your power requirements and cabling
	
  }

  
  oled.setTextXY(0, 0);  // Set cursor position, start of line 0
  oled.putString("TIPO:");
  oled.putString("DS18B20");
  
  oled.setTextXY(4, 0);  // Set cursor position, start of line 2
  oled.putString("SCRACHPAD");
  oled.setTextXY(5, 0);  // Set cursor position, line 2 10th character
  oled.putString("RESOLUCION: ");
  String res=String(sensors.getResolution(tempDeviceAddress));
  oled.putString(res);
  delay(20);
}

// function to print a device address
String printAddress(DeviceAddress deviceAddress)
{

  for (uint8_t i = 0; i < 8; i++)
  {
    
    if (deviceAddress[i] < 16) Serial.print("0");
    Serial.print(deviceAddress[i], HEX);
    oled.setTextXY(1, 0);  // Set cursor position, start of line 1
  oled.putString("ADR: ");
oled.putString(String(deviceAddress[i]));
  }
 
}
