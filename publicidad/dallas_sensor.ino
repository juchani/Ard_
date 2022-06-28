void ds() {
  uid16data[7]=dht2.readTemperature();
  uid16data[8]= dht2.readHumidity();
   if (isnan(uid16data[8]) || isnan(uid16data[7]) ) {
    sensor_2.requestTemperatures();
  uid16data[7] = sensor_2.getTempCByIndex(0)*100;
    return;
  }
  sensor_1.requestTemperatures();
  uid16data[5] = sensor_1.getTempCByIndex(0)*100;
  sensor_3.requestTemperatures();
  uid16data[9] = sensor_3.getTempCByIndex(0)*100;  
  delay(500);
  }
