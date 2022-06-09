int at1(int limite) {
  int l = s1.read();
  if (l > limite) {
    for (int i = l; i > limite; i--) {
      s1.write(i);
      delay(vel);
    }
  }
  if (l < limite) {
    for (int i = l; i < limite; i++) {
      s1.write(i);
      delay(vel);
    }
  }
}

int at2(int limite) {
  int l = s2.read();
  if (l > limite) {
    for (int i = l; i > limite; i--) {
      s2.write(i);
      delay(vel);
    }
  }
  if (l < limite) {
    for (int i = l; i < limite; i++) {
      s2.write(i);
      delay(vel);
    }
  }
}

int at3(int limite) {
  int l = s3.read();
  if (l > limite) {
    for (int i = l; i > limite; i--) {
      s3.write(i);
      delay(vel);
    }
  }
  if (l < limite) {
    for (int i = l; i < limite; i++) {
      s3.write(i);
      delay(vel);
    }
  }
}
void tester(){
  Serial.print("S1 :");
  Serial.print(s1.read());
  Serial.print(" S2 :");
  Serial.print(s2.read());
  Serial.print(" S3 :");
  Serial.print(s3.read());
  Serial.print(" S4 :");
  Serial.println(s4.read());
}
