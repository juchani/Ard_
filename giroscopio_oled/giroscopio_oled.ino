#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET 4         // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C  ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

Adafruit_MPU6050 mpu;



void setup() {
  Serial1.begin(9600);
  mpu.begin();
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
  delay(100);


  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    
  }


}

void loop() {
  //display.height() =y
  //display.width()=x
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  float y = a.acceleration.x;
  int y1 = map(y, 10, -10, 0, display.height());
  float x = a.acceleration.y;
  int x1 = map(x, 10, -10, 0, display.width());
  
  
  if (x1>82){
    Serial1.println("d");
  }
 else if (x1<44){
    Serial1.println("i");
  }
  else if (y1>40){
    Serial1.println("r");
  }
 else if (y1<16){
    Serial1.println("a");
  }
  else{
    Serial.println("s");    
  }
  display.clearDisplay();
  display.drawCircle(display.width() / 2, display.height() / 2, 15, SSD1306_WHITE);
  display.drawCircle(display.width() / 2, display.height() / 2, 40, SSD1306_WHITE);
  display.drawRect(0, 0, display.width(), display.height(), SSD1306_WHITE);
  display.drawLine(0, display.height() / 2, display.width(), display.height() / 2, SSD1306_WHITE);
  display.drawLine(display.width() / 2, 0, display.width() / 2, display.height(), SSD1306_WHITE);
  display.drawCircle(x1, y1, 2, SSD1306_WHITE);//circulo
  display.display();
  delay(10);


}
