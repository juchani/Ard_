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
      mb.Hreg(H_HREG, analogRead(humo));
      if (digitalRead(humo)) {
      
      }
      else {

      }

      // mb.Hreg(SENSOR_HREG_1,678);
    }
    delay(1);

  }
}
