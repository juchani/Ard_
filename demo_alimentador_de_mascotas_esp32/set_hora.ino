void barrido();
void set_hora(int addr) {
  reg_hora = 0, reg_minuto =minuto_, reg_duracion = 0, reg_rep = 0;
  reg_addr = addr;
  barrido();
  b = 0;
  c = hora_;
  while (1 == 1) {
    bot(23, 1);
    tft.setTextWrap(true);                        // turn off text wrap option
    tft.setTextColor(ST77XX_WHITE, ST77XX_BLACK);  // set text color to white and black background
    tft.setTextSize(6);                 // text size = 2
    tft.setCursor(30, 30);
    tft.setTextColor(ST77XX_WHITE, ST77XX_GREEN);
    tft.print(str_num(c));
    tft.setTextColor(ST77XX_WHITE, ST77XX_BLACK);
    tft.print(":");
    tft.println(str_num(reg_minuto));
    tft.println(" ");
    tft.setTextSize(4);
    tft.setCursor(0, 90);             // move cursor to position (28, 27) pixel
    tft.print("D: ");
    tft.println(str_num(reg_duracion));
    tft.print("R: ");
    tft.println(str_num(reg_rep));
    delay(1);
    barrido(1);
    if (!digitalRead(enter)) {
      delay(300);
      reg_hora = c;
      set_minutos();
    }
    b++;
  }
}


void set_minutos() {
  barrido();
  c = minuto_;
  b = 0;
  while (1 == 1) {
    bot(60, 1);
    tft.setTextWrap(true);                        // turn off text wrap option
    tft.setTextColor(ST77XX_WHITE, ST77XX_BLACK);  // set text color to white and black background
    tft.setTextSize(6);                 // text size = 2
    tft.setCursor(30, 30);             // move cursor to position (28, 27) pixel
    tft.print(str_num(reg_hora));
    tft.print(":");
    tft.setTextColor(ST77XX_WHITE, ST77XX_GREEN);
    tft.println(str_num(c));
    tft.setTextColor(ST77XX_WHITE, ST77XX_BLACK);
    tft.println(" ");
    tft.setTextSize(4);
    tft.setCursor(0, 90);             // move cursor to position (28, 27) pixel
    tft.print("D: ");
    tft.println(str_num(reg_duracion));
    tft.print("R: ");
    tft.println(str_num(reg_rep));
    if (!digitalRead(enter)) {
       delay(300);
      reg_minuto = c;
      set_duracion();

    }
    b++;
    delay(1);
    barrido(1);

  }
}
//reg_duracion,reg_rep
void set_duracion() {
  barrido();
  c = 0;
  b = 0;
  while (1 == 1) {
    bot(10, 1);
    tft.setTextWrap(true);                        // turn off text wrap option
    tft.setTextColor(ST77XX_WHITE, ST77XX_BLACK);  // set text color to white and black background
    tft.setTextSize(6);                 // text size = 2
    tft.setCursor(30, 30);             // move cursor to position (28, 27) pixel
    tft.print(str_num(reg_hora));
    tft.print(":");
    tft.println(str_num(reg_minuto));
    tft.println(" ");
    tft.setTextSize(4);
    tft.setCursor(0, 90);             // move cursor to position (28, 27) pixel
    tft.print("D: ");
    tft.setTextColor(ST77XX_WHITE, ST77XX_GREEN);
    tft.println(str_num(c));
    tft.setTextColor(ST77XX_WHITE, ST77XX_BLACK);
    tft.print("R: ");
    tft.println(str_num(reg_rep));
    if (!digitalRead(enter)) {
      // set_minutos();
       delay(300);
      reg_duracion = c;
      set_repeticion();
    }
    b++;
    delay(1);
    barrido(1);

  }
}
void set_repeticion() {
  barrido();
  c = 0;
  b = 0;
  while (1 == 1) {
    bot(10, 1);
    tft.setTextWrap(true);                        // turn off text wrap option
    tft.setTextColor(ST77XX_WHITE, ST77XX_BLACK);  // set text color to white and black background
    tft.setTextSize(6);                 // text size = 2
    tft.setCursor(30, 30);             // move cursor to position (28, 27) pixel
    tft.print(str_num(reg_hora));
    tft.print(":");
    tft.println(str_num(reg_minuto));
    tft.println(" ");
    tft.setTextSize(4);
    tft.setCursor(0, 90);             // move cursor to position (28, 27) pixel
    tft.print("D: ");

    tft.println(str_num(reg_duracion));
    tft.print("R: ");
    tft.setTextColor(ST77XX_WHITE, ST77XX_GREEN);
    tft.println(str_num(c));
    tft.setTextColor(ST77XX_WHITE, ST77XX_BLACK);
    if (!digitalRead(enter)) {
      // set_minutos();
       delay(300);
      reg_rep = c;
      validacion();
    }
    b++;
    delay(1);
    barrido(1);

  }
}
//reg_hora=0,reg_minuto=0,reg_duracion=0,reg_rep=0;
void validacion() {
  barrido();
  c = 0;
  b = 0;
  while (1 == 1) {
    bot(1, 1);
    String resp[] = {"SI", "NO"};
    tft.setTextWrap(true);                        // turn off text wrap option
    tft.setTextColor(ST77XX_WHITE, ST77XX_BLACK);  // set text color to white and black background
    tft.setTextSize(2);                 // text size = 2
    tft.setCursor(0, 30);             // move cursor to position (28, 27) pixel
    tft.print("DESEA ALMACENAR LOS SIGUIENTES DATOS:");
    tft.print(reg_hora);
    tft.print(":");
    tft.println(str_num(reg_minuto));
    tft.println(" ");
    tft.setTextSize(4);
    tft.setCursor(0, 90);             // move cursor to position (28, 27) pixel
    tft.print("D: ");
    tft.println(str_num(reg_duracion));
    tft.print("R: ");
    tft.println(str_num(reg_rep));
    if (c == 0) {
      tft.setTextColor(ST77XX_WHITE, ST77XX_GREEN);
    }
    else {
      tft.setTextColor(ST77XX_WHITE, ST77XX_RED);
    }
    tft.println(resp[c]);
    if (!digitalRead(enter)&&c==0) {
       delay(300);
      EEPROM.write(add_hora[reg_addr], reg_hora);
      EEPROM.write(add_minuto[reg_addr], reg_minuto);
      EEPROM.write(add_duracion[reg_addr], reg_duracion);
      EEPROM.write(add_estado[reg_addr], reg_rep);
      EEPROM.commit();
      tft.println("      OK      ");
      ESP.restart();
    }
    if (!digitalRead(enter)&&c==1) {
      tft.println("      OK      ");
      ESP.restart();
       delay(300);
    }
    b++;
    delay(1);
    barrido(1);

  }
}
