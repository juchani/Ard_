int ds_sensor(){
int  tempC = sensors.getTempCByIndex(0)*100;
if(tempC != DEVICE_DISCONNECTED_C) 
  {
    return tempC;
  } 
  else
  {
    return -1;
  }
   
}
