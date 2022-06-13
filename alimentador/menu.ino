
int menu_1() {
  if (digitalRead(b1) == 0) {
    ind++;
  }
  if (digitalRead(b2) == 0) {
    bucle=1;
    menu_2();
    delay(500);
  }
  if (digitalRead(b3) == 0) {
    ind--;
  }

  if (ind > limite_c) {
    ind = limite_c;
  }
  if (ind < 0) {
    ind = 0;
  }
}

void menu_2() {
  int i = hora[ind];
  int lin = 23;
  while (bucle) {
    pantalla_1(i);
    if (digitalRead(b1) == 0) {
      i++;
    }
    if (digitalRead(b2) == 0) {
      hora[ind]=i;
      menu_3();
      delay(500);
    }
    if (digitalRead(b3) == 0) {
      i--;
    }

    if (i > lin) {
      i = lin;
    }
    if (i < 0) {
      i = 0;
    }
  }
}
void menu_3() {
  int i = minuto[ind];
  int lin = 59;
  while (bucle) {
    pantalla_2(i);
    if (digitalRead(b1) == 0) {
      i++;
    }
    if (digitalRead(b2) == 0) {
       minuto[ind]=i;
       menu_4();
      delay(500);
    }
    if (digitalRead(b3) == 0) {
      i--;
    }

    if (i > lin) {
      i = lin;
    }
    if (i < 0) {
      i = 0;
    }
  }
}

void menu_4() {
  int i = duracion[ind];
  int lin = 5;
  while (bucle) {
    pantalla_3(i);
    if (digitalRead(b1) == 0) {
      i++;
    }
    if (digitalRead(b2) == 0) {
       duracion[ind]=i;
       bucle=0;
       //menu_4();
      delay(500);
    }
    if (digitalRead(b3) == 0) {
      i--;
    }

    if (i > lin) {
      i = lin;
    }
    if (i < 0) {
      i = 0;
    }
  }
}
