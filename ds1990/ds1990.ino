#include <OneWire.h>
#include <ModbusRtu.h>
#define TXEN  4 

Modbus slave(1,0,TXEN);
OneWire ibutton (8);
byte demo[20];//lista
uint16_t au16data[16] ={};

void setup() {
slave.begin( 19200 ); // baud-rate at 19200
}


void loop() {
  
 if (!ibutton.search (demo)) {
    ibutton.reset_search();
   // delay(200);   
  }
au16data[0]=comparar(demo);
slave.poll(au16data, 16 );
 
}

int comparar(byte array1[])
{ int suma=0;
 for (int a=0;a<8;a++){
  suma=suma+int(array1[a]);
 }
  
 for(int r=0;r<8;r++){
  demo[r]=0;
 }
 return suma;
 suma=0;
}
