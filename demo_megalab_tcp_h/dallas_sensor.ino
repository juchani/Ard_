void ds() {
  sensor_1.requestTemperatures();
  uid16data[5] = sensor_1.getTempCByIndex(0)*100;
  sensor_2.requestTemperatures();
  uid16data[6] = sensor_2.getTempCByIndex(0)*100;
  sensor_3.requestTemperatures();
  uid16data[7] = sensor_3.getTempCByIndex(0)*100;
  sensor_4.requestTemperatures();
  uid16data[8] = sensor_4.getTempCByIndex(0)*100;
  sensor_5.requestTemperatures();
  uid16data[9] = sensor_5.getTempCByIndex(0)*100;
  sensor_6.requestTemperatures();
  uid16data[10] = sensor_6.getTempCByIndex(0)*100;
  ds_id();  
  }

  void dht_h(){
    uid16data[12] = dht.readHumidity()*100;
  // Read temperature as Celsius (the default)
  uid16data[11] = dht.readTemperature()*100;
  }
