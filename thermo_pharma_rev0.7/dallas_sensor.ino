
void sensor_1() {
  uid16data[11] = 1;
  float h = dht1.readHumidity();
  float t = dht1.readTemperature();
  if (isnan(h) || isnan(t)) {
    ds1.requestTemperatures();
    t = ds1.getTempCByIndex(0);
    if (t == -127) {
      uid16data[11] = 0;
    }


  }
  uid16data[5] = int(t * 10);
  uid16data[6] = h;


  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.println(F("°C "));
}

void sensor_2() {
  uid16data[12] = 1;
  float h = dht2.readHumidity();
  float t = dht2.readTemperature();
  if (isnan(h) || isnan(t)) {
    ds2.requestTemperatures();
    t = ds2.getTempCByIndex(0);
    if (t == -127) {
      uid16data[12] = 0;
   }
   
   
  }
  uid16data[7] = int(t * 10);
  uid16data[8] = h;

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.println(F("°C "));
}

void sensor_3() {

  uid16data[13] = 1;
  float h = dht3.readHumidity();

  float t = dht3.readTemperature();


  if (isnan(h) || isnan(t)) {

    ds3.requestTemperatures();
    t = ds3.getTempCByIndex(0);
    if (t == -127) {
      uid16data[13] = 0;
    }
    else {
      digitalWrite(led3, LOW);
    }
  }
  else {
    digitalWrite(led3, HIGH);
  }

  uid16data[9] = int(t * 10);
  uid16data[10] = h ;

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.println(F("°C \n"));
}
