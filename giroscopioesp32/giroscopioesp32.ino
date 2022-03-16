#include <Adafruit_MPU6050.h>  //libreria para el giroscopio mpu 6050
#include <Adafruit_Sensor.h>   //libreria para el uso de giroscopio
#include <Wire.h>              //libreria para usar el protocolo i2c(giroscopio)
#include <TFT_eSPI.h>          //libreria para controlar la pantalla TFT
#include <SPI.h>               //libreria para usar el protocolo SPI(pantalla)
#include <SoftwareSerial.h>    //libreria para crear un puerto uart (receptor-transmisor asincrono universal)
SoftwareSerial hc(27, 26);     //rx-tx
#define boton 35               //definimos un boton (no usado)
#define TFT_W 240              //ancho de pantalla
#define TFT_H 130              //alto de pantalla
Adafruit_MPU6050 mpu;          //creacion del objeto mpu
TFT_eSPI tft = TFT_eSPI();     //creacion del objeto para la pantalla
int contador = 0;

void setup() {
  tft.init();                 //configuracion inicial para la pantalla tft
  tft.setRotation(1);         //establece la direccion de pantalla
  tft.fillScreen(TFT_BLACK);  // establece el color de fondo
  Serial.begin(9600);         //inicia la comunicacion serial (9600 baudios)
  hc.begin(9600);             //inicia la comunicacion serial (9600 baudios)
                              /////////////////////// configuracion del mpu 6050//////////////////
  mpu.begin();
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
  delay(100);  //retraso de 100 milisegundos
}

void loop() {
  //display.height() =y
  //display.width()=x
  /////////////////////////mpu 6050/////////////////
  //se optienen los valores del giroscopio y se almacenan en a,g,tem
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
  //////////////conversion de valores/////////
  //convierte los valores en x-y para graficar en la pantalla tft
  //el rango en ambos ejes son (-10,10) tanto para los ejes x-y
  float y = a.acceleration.x;          //almacena el valor del eje x a la variable y
  int y1 = map(y, -10, 10, 0, TFT_H);  //convierte los valores de y con parametros (-10,10) a (0,alto_de_pantalla)
  float x = a.acceleration.y;          //almacena el valor del eje y a la variable x
  int x1 = map(x, -10, 10, 0, TFT_W);  //convierte los valores de x con parametros (-10,10) a (0,ancho_de_pantalla)

  Serial.print(x1);  //imprime el eje x
  Serial.print(" ");
  Serial.println(y1);  //imprime el eje x

  tft.fillCircle(TFT_W / 2, TFT_H / 2, 130, TFT_BLACK);  //crea un circulo de color negro en el centro con un diametro de 130 pixeles
  tft.fillCircle(TFT_W / 2, TFT_H / 2, 25, TFT_RED);     //crea un circulo de color rojo en el centro con un diametro de 25 pixeles
  //    tft.fillCircle(TFT_W / 2 , TFT_H / 2 , 30, TFT_BLACK);
  tft.drawLine(TFT_W / 2, 0, TFT_W / 2, TFT_H, TFT_WHITE);  //crea una linea vertical en el centro de color blanco
  tft.drawLine(1, TFT_H / 2, TFT_W, TFT_H / 2, TFT_WHITE);  //crea una linea horizontal en el centro de color blanco
  tft.fillCircle(x1, y1, 3, TFT_GREEN);                     //crea un circulo de color verde con un diametro de 3 pixeles

  if (y1 > 92) {          //si el eje y es mayor a 92
    hc.println("r");      //envia una r por el puerto uart
  } else if (y1 < 39) {   //si el eje y es menor a 39
    hc.println("a");      //envia una a por el puerto uart
  } else if (x1 > 144) {  //si el eje x es mayor a 144
    hc.println("d");      //envia una d por el puerto uart
  } else if (x1 < 96) {   //si el eje x es menor a 96
    hc.println("i");      //envia una i por el puerto uart
  } else {                //en caso que ninguna condicion se cumpla
    hc.println("s");      //envia una s por el puerto uart
  }


  delay(300);                   //retardo de 300 milisegundos
}
