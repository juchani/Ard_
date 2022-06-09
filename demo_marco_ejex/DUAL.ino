void Task1code( void * pvParameters ) {
  while (1) {
    ArduinoOTA.handle();
    mb.task();
    az = mb.Hreg(AZ_HREG);
    x = mb.Hreg(X_HREG);
    //Read each two seconds
    if (millis() > ts + 2000) {
      ts = millis();
      if (mb.Hreg(Y_HREG) > -1 && mb.Hreg(Y_HREG) < 100) {
        Serial2.println(mb.Hreg(Y_HREG));
      }
      int cc;
      int vv=map(analogRead(VT_PIN),0,2733,0,116);
//      int cc=map(analogRead(AT_PIN),0,);

      //Setting raw value (0-1024)
      mb.Hreg(X_HREG, x );
      mb.Hreg(AZ_HREG, az);
      mb.Hreg(Z_HREG, z);
      mb.Hreg(G_HREG, g);
      mb.Hreg(H_HREG, h);
      mb.Hreg(ENC_HREG, enc);
      mb.Hreg(ANG_HREG, ang);
      mb.Hreg(LDR_HREG, analogRead(39));
      mb.Hreg(C_HREG, analogRead(AT_PIN));
      mb.Hreg(V_HREG,vv);
      mb.Hreg(C_HREG,cc);

    }

    delay(10);

  }

}
