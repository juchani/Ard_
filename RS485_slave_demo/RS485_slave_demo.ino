#include <ModbusRtu.h>
#define TXEN	4 
uint16_t au16data[16] = {
  32, 1415, 9265, 4, 2, 7182, 28182, 8, 0, 0, 0, 0, 0, 0, 1, -1 };
Modbus slave(1,0,TXEN); // this is slave @1 and RS-485
void setup() {
  slave.begin( 19200 ); // baud-rate at 19200
  
}

void loop() {
 au16data[0]=analogRead(A0);
  slave.poll( au16data, 16 );
  
}
