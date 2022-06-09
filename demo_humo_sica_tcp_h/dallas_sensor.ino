void ds() {
  sensor_1.requestTemperatures();
  uid16data[5] = sensor_1.getTempCByIndex(0)*100;
  sensor_2.requestTemperatures();
  uid16data[6] = sensor_2.getTempCByIndex(0)*100;
  sensor_3.requestTemperatures();
  uid16data[7] = sensor_3.getTempCByIndex(0)*100;
  ds_id();  
  }
