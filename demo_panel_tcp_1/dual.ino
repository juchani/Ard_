void tcp0code( void * pvParameters ) {
  while (1) {
    mb.task();
      ArduinoOTA.handle();
    if (millis() > ts + 1000) {
      ts = millis();
      if(mb.Hreg(ST1_HREG)>-1 && mb.Hreg(ST1_HREG)<100){
      uid16data[5] = mb.Hreg(ST1_HREG);  
      }
        Serial2.println(uid16data[5]);
      mb.Hreg(M1_HREG, uid16data[1] );
      mb.Hreg(M2_HREG, uid16data[2]);
      mb.Hreg(E1_HREG, uid16data[3]);
      mb.Hreg(E2_HREG, uid16data[4] );
      mb.Hreg(ST1_HREG, uid16data[5] );
      mb.Hreg(ST2_HREG, uid16data[6] );
      // mb.Hreg(SENSOR_HREG_1,678);
    }
    delay(1);

  }
}
