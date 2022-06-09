void tcp0code( void * pvParameters ) {
  while (1) {
    mb.task();
    if (millis() > ts + 1000) {
      ts = millis();
      Serial.print(reg_id );
      Serial.print("\t");
      Serial.println( reg_id_new );
      guardar();
      mb.Hreg(S_HREG, reg_id );
      mb.Hreg(D1_HREG, uid16data[5] );
      mb.Hreg(D2_HREG, uid16data[6]);
      mb.Hreg(D3_HREG, uid16data[7] );
      mb.Hreg(D4_HREG, uid16data[8]);
      mb.Hreg(D5_HREG, uid16data[9] );
      mb.Hreg(D6_HREG, uid16data[10]);
      mb.Hreg(DHT_T_HREG, uid16data[11]);
      mb.Hreg(DHT_H_HREG, uid16data[12]);
      mb.Hreg(H_HREG, digitalRead(humo));
      if (digitalRead(humo)) {
        pixels.setPixelColor(6, pixels.Color(0, 150, 0));
        pixels.show();
      }
      else {
        pixels.setPixelColor(6, pixels.Color(150, 0, 0));
        pixels.show();
      }

      // mb.Hreg(SENSOR_HREG_1,678);
    }
    delay(1);

  }
}
