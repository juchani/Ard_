int bt[] = {2, 3, 4, 5, 6, 7, 8,9,10};
int led[] = {44, 42, 40, 38, 36, 34};
bool estatus1, estatus2, estatus3, estatus4, estatus5, estatus6, estatus7, estatus8;
int modo = 1;
int t;
void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 7; i++) {
    pinMode(led[i], OUTPUT);
  }
  for (int i = 0; i < 8; i++) {
    pinMode(bt[i], INPUT_PULLUP);
  }
}
void loop() {
  if (!digitalRead(bt[0]) == 1) {
    modo = 1;
    estatus1 = !estatus1;
    delay(500);

  }
  else if (!digitalRead(bt[1]) == 1) {
    modo = 2;
    estatus2 = !estatus2;
    delay(500);
  }
  else if (!digitalRead(bt[2]) == 1) {
    modo = 3;
    estatus3 = !estatus3;
    delay(500);
  }
  else if (!digitalRead(bt[3]) == 1) {
    modo = 4;
    estatus4 = !estatus4;
    delay(500);
  }
  else if (!digitalRead(bt[4]) == 1) {
    modo = 5;
    estatus5 = !estatus5;
    delay(500);
  }
  else if (!digitalRead(bt[5]) == 1) {
    modo = 6;
    estatus6 = !estatus6;
    delay(500);
  }
  else if (!digitalRead(bt[6]) == 1) {
    modo = 7;
    estatus7 = !estatus7;
    delay(500);
  }
  else if (!digitalRead(bt[7]) == 1) {
    modo = 8;
    estatus8 = !estatus8;
    delay(500);
  }
  Serial.print(modo);
  Serial.print('\t');

  t = map(analogRead(A0), 0, 1023, 100, 30);
  Serial.println(t);
  secuencia(modo);
  delay(t);
  for (int i = 0; i < 7; i++) {
    digitalWrite(led[i], 0);
  }
  delay(t);


}



void secuencia(int mod) {
  if (mod == 1 && estatus1 == 1) {
    digitalWrite(led[0], 1);
    digitalWrite(led[1], 1);
    digitalWrite(led[2], 1);
    digitalWrite(led[3], 1);
  }
  else if (mod == 2 && estatus2 == 1) {
    for (int i = 0; i < 7; i++) {
      digitalWrite(led[i], 1);
    }
  }
  else if (mod == 3 && estatus3 == 1) {
    digitalWrite(led[0], 1);
  }
  else if (mod == 4 && estatus4 == 1) {
    digitalWrite(led[1], 1);
  }
  else if (mod == 5 && estatus5 == 1) {
    digitalWrite(led[2], 1);
  }
  else if (mod == 6 && estatus6 == 1) {
    digitalWrite(led[3], 1);
  }
  else if (mod == 7 && estatus7 == 1) {
    digitalWrite(led[4], 1);
  }
  else if (mod == 8 && estatus8 == 1) {
    digitalWrite(led[5], 1);
  }
}
