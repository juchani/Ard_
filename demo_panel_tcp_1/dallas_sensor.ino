void motor_1() {
  int x=uid16data[6];
  int az=359;//uid16data[1];
  int z;
  int g;
  if(uid16data[1]>0){
    az=uid16data[1];
  }
  if((az-x)>270){
    g=360-az;
    if(abs(g)>=2){
     z=az-359; 
    }
  }
  dato_rx = (z * 1.4222222222)*40; // Ajuste de 512 vueltas a los 360 grados
 uid16data[3]=dato_rx;
  while (dato_rx > numero_pasos) { // Girohacia la izquierda en grados
    paso_izq();
      rotary_loop();
    numero_pasos = numero_pasos + 1;
  }
  while (dato_rx < numero_pasos) { // Giro hacia la derecha en grados
    paso_der();
      rotary_loop();
    numero_pasos = numero_pasos - 1;
  }
  apagado();         // Apagado del Motor para que no se caliente
}

void paso_der() {        // Pasos a la derecha
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, HIGH);
  delay(retardo);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(retardo);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  delay(retardo);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(retardo);
}

void paso_izq() {        // Pasos a la izquierda
  digitalWrite(in1, HIGH);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  delay(retardo);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(retardo);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, HIGH);
  delay(retardo);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(retardo);
}

void apagado() {         // Apagado del Motor
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
