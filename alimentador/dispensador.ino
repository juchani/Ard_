
void reserva_comida() {
  digitalWrite(trig3, LOW);
  delayMicroseconds(2);
  digitalWrite(trig3, HIGH);
  // EL PULSO DURA AL MENOS 10 uS EN ESTADO ALTO
  delayMicroseconds(10);
  digitalWrite(trig3, LOW);

  // MEDIR EL TIEMPO EN ESTADO ALTO DEL PIN "ECHO" EL PULSO ES PROPORCIONAL A LA DISTANCIA MEDIDA
  int tiempo = pulseIn(echo3, HIGH);

  // LA VELOCIDAD DEL SONIDO ES DE 340 M/S O 29 MICROSEGUNDOS POR CENTIMETRO
  // DIVIDIMOS EL TIEMPO DEL PULSO ENTRE 58, TIEMPO QUE TARDA RECORRER IDA Y VUELTA UN CENTIMETRO LA ONDA SONORA
  int dist = tiempo / 29;
  if (dist > 2 && dist < 100) {
    fr_comida = dist;
    if (dist > res_comida) {
      lcd.setCursor(0, 0);
      lcd.print("RESERVA  ");
      lcd.setCursor(0, 1);
      lcd.print("COMIDA");
      M2.write(90);
      delay(2000);
    }
    else {
      M2.write(0);
    }


  }
  //  S2.write(90);
}
void reserva_agua() {
  digitalWrite(trig4, LOW);
  delayMicroseconds(2);
  digitalWrite(trig4, HIGH);
  // EL PULSO DURA AL MENOS 10 uS EN ESTADO ALTO
  delayMicroseconds(10);
  digitalWrite(trig4, LOW);

  // MEDIR EL TIEMPO EN ESTADO ALTO DEL PIN "ECHO" EL PULSO ES PROPORCIONAL A LA DISTANCIA MEDIDA
  int tiempo = pulseIn(echo4, HIGH);

  // LA VELOCIDAD DEL SONIDO ES DE 340 M/S O 29 MICROSEGUNDOS POR CENTIMETRO
  // DIVIDIMOS EL TIEMPO DEL PULSO ENTRE 58, TIEMPO QUE TARDA RECORRER IDA Y VUELTA UN CENTIMETRO LA ONDA SONORA
  int dist = tiempo / 29;
  if (dist > 2 && dist < 100) {
    fr_agua = dist;
    if (dist > res_agua) {
      lcd.setCursor(0, 0);
      lcd.print("RESERVA  ");
      lcd.setCursor(0, 1);
      lcd.print("AGUA");
      digitalWrite(m1, 1);
      delay(2000);
    }
    else {
      digitalWrite(m1, 0);
    }


  }
}
void dispensador_comida(int d) {
  digitalWrite(trig1, LOW);
  delayMicroseconds(2);
  digitalWrite(trig1, HIGH);
  // EL PULSO DURA AL MENOS 10 uS EN ESTADO ALTO
  delayMicroseconds(10);
  digitalWrite(trig1, LOW);

  // MEDIR EL TIEMPO EN ESTADO ALTO DEL PIN "ECHO" EL PULSO ES PROPORCIONAL A LA DISTANCIA MEDIDA
  int tiempo = pulseIn(echo1, HIGH);

  // LA VELOCIDAD DEL SONIDO ES DE 340 M/S O 29 MICROSEGUNDOS POR CENTIMETRO
  // DIVIDIMOS EL TIEMPO DEL PULSO ENTRE 58, TIEMPO QUE TARDA RECORRER IDA Y VUELTA UN CENTIMETRO LA ONDA SONORA
  int dist = tiempo / 29;
  Serial.println(dist);
  if (dist > 2 && dist < 100) {
    Serial.println("lim");
    if (dist > desp_comida) {
      Serial.println("sec");
      lcd.setCursor(0, 0);
      lcd.print("DISPENSADOR  ");
      lcd.setCursor(0, 1);
      lcd.print("COMIDA");
      M1.write(90);
      delay(d * 1000);
      M1.write(0);
    }



  }

}
void dispensador_agua(int d) {
  digitalWrite(trig2, LOW);
  delayMicroseconds(2);
  digitalWrite(trig2, HIGH);
  // EL PULSO DURA AL MENOS 10 uS EN ESTADO ALTO
  delayMicroseconds(10);
  digitalWrite(trig2, LOW);

  // MEDIR EL TIEMPO EN ESTADO ALTO DEL PIN "ECHO" EL PULSO ES PROPORCIONAL A LA DISTANCIA MEDIDA
  int tiempo = pulseIn(echo2, HIGH);

  // LA VELOCIDAD DEL SONIDO ES DE 340 M/S O 29 MICROSEGUNDOS POR CENTIMETRO
  // DIVIDIMOS EL TIEMPO DEL PULSO ENTRE 58, TIEMPO QUE TARDA RECORRER IDA Y VUELTA UN CENTIMETRO LA ONDA SONORA
  int dist = tiempo / 29;
  Serial.println(dist);
  if (dist > 2 && dist < 100) {
    Serial.println("lim");
    if (dist > desp_agua) {
      Serial.println("sec");
      lcd.setCursor(0, 0);
      lcd.print("DISPENSADOR  ");
      lcd.setCursor(0, 1);
      lcd.print("AGUA");
      digitalWrite(m2, 1);
      delay(d * 1000);
      digitalWrite(m2, 0);
    }
  }

}
