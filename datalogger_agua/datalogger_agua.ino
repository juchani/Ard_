//librerias
#include <Wire.h>
#include <OneWire.h>
#include <Adafruit_SH110X.h>
//configuracion de pantalla
#define i2c_Address 0x3C //initialize with the I2C addr 0x3C Typically eBay OLED's
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET -1

#define filtro 100 // filtro :la cantidad de veces que suma y promedia el valor de la intensidad de luz dispersada

Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
OneWire  ds(3); //pin del sensor de temperatura
double calc_NTU(double volt); //funcion para calcular la luz dispersa
double NTU = 0.0;             //variable donde se almacena el IDL
int tt;                       //variable donde se almacena la temperatura
void setup()   {
  Serial.begin(9600);               //inicia la comunicacion serial
  display.begin(i2c_Address, true); // inicia la pantalla
  display.setRotation(2);           // estableca la orientacion de la pantalla
}


void loop() {
  //----------filtro---------------
  // hace una lectura de n veces y luego la promedia(ayuda a reducir el ruido)
  for (int i = 0; i < filtro; i++) {
    int sensorValue = analogRead(A0);            //lectura la señal analogica
    float voltage = sensorValue * (5.0 / 1024.0);//convierte la señal en voltaje
    NTU = NTU + calc_TU(voltage);                //se calcula el IDL y se suma
    delay(10);
  }
  ds_sensor();                                   //se obtiene la temperatura 
  NTU = NTU / filtro;                            //se promedia los valores del idl
  //-----------pantalla-----------
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SH110X_WHITE);
  display.setCursor(30, 0);
  display.println("Temperatura");
  display.setCursor(40, 10);
  display.setTextSize(2);
  display.print(tt);
  display.println(" C");
  display.setTextSize(1);
  display.println("      Turbiedad");
  display.setTextSize(2);
  display.print("  ");
  display.print(int(NTU));
  display.println(" ILD");

  display.display();
  delay(500);
  // display.clearDisplay();
}

double calc_TU(double volt)
{

  double NTU_val;

  NTU_val = -(1120.4 * volt * volt) + (5742.3 * volt) - 4352.9;

  return NTU_val;


}

void ds_sensor() {
  byte i;
  byte present = 0;
  byte type_s;
  byte data[12];
  byte addr[8];
  float celsius;

  if ( !ds.search(addr)) {
    ds.reset_search();
    delay(250);
    return;
  }

  
  ds.reset();
  ds.select(addr);
  ds.write(0x44, 1);        // inicia la conversion

  delay(750);     // espera  750ms 
  

  present = ds.reset();
  ds.select(addr);
  ds.write(0xBE);         // lee el Scratchpad (es como una eeprom)


  for ( i = 0; i < 9; i++) {          
    data[i] = ds.read();

  }

  int16_t raw = (data[1] << 8) | data[0];

  if (type_s) {
    raw = raw << 3; // 9 bit resolution default
    if (data[7] == 0x10) {
      // "count remain" gives full 12 bit resolution
      raw = (raw & 0xFFF0) + 12 - data[6];
    }
  }
  else {
    byte cfg = (data[4] & 0x60);
  
    if (cfg == 0x00) raw = raw & ~7;  // 9 bit resolution, 93.75 ms
    else if (cfg == 0x20) raw = raw & ~3; // 10 bit res, 187.5 ms
    else if (cfg == 0x40) raw = raw & ~1; // 11 bit res, 375 ms
    //// default is 12 bit resolution, 750 ms conversion time
  }
  celsius = (float)raw / 16.0;
  tt = celsius;



}
