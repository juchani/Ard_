void set_hora(int addr) {
  reg_hora = 0, reg_minuto = minuto_, reg_duracion = 0, reg_rep = 0;
  reg_addr = addr;
  barrido();
  b = 0;
  c = hora_;
  while (1 == 1) {
    rtc_act();
    bot(23, 1);
    tft.setTextWrap(true);                        // turn off text wrap option
    tft.setTextColor(ST77XX_WHITE, ST77XX_BLACK);  // set text color to white and black background
    tft.setTextSize(6);                 // text size = 2
    tft.setCursor(30, 30);
    tft.setTextColor(ST77XX_GREEN, ST77XX_BLACK);
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
    rtc_act();
    bot(59, 1);
    tft.setTextWrap(true);                        // turn off text wrap option
    tft.setTextColor(ST77XX_WHITE, ST77XX_BLACK);  // set text color to white and black background
    tft.setTextSize(6);                 // text size = 2
    tft.setCursor(30, 30);             // move cursor to position (28, 27) pixel
    tft.print(str_num(reg_hora));
    tft.print(":");
    tft.setTextColor(ST77XX_GREEN, ST77XX_BLACK);
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
    rtc_act();
    bot(5, 1);
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
    tft.setTextColor(ST77XX_GREEN, ST77XX_BLACK);
    tft.println(str_num(c));
    tft.setTextColor(ST77XX_WHITE, ST77XX_BLACK);
    tft.print("R: ");
    tft.println(str_num(reg_rep));
    if (!digitalRead(enter)) {
      // set_minutos();
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
    rtc_act();
    bot(4, 1);
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
    tft.setTextColor(ST77XX_GREEN, ST77XX_BLACK);
    tft.println(str_num(c));
    tft.setTextColor(ST77XX_WHITE, ST77XX_BLACK);
    if (!digitalRead(enter)) {
      // set_minutos();
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
    rtc_act();
    bot(2, 1);
    String resp[] = {"SI", "NO","PROBAR"};
    tft.setTextWrap(true);                        // turn off text wrap option
    tft.setTextColor(ST77XX_WHITE, ST77XX_BLACK);  // set text color to white and black background
    tft.setTextSize(2);                 // text size = 2
    tft.setCursor(40, 30);
    tft.setTextColor(gris, ST77XX_BLACK);
    tft.println("GUARDAR DATOS:");
    tft.setTextColor(ST77XX_WHITE, ST77XX_BLACK);
    tft.println(" ");
    tft.setTextSize(4);
    tft.print("  ");
    tft.print(str_num(reg_hora));
    tft.print(":");
    tft.println(str_num(reg_minuto));
    tft.println(" ");
    tft.print("D: ");
    tft.println(str_num(reg_duracion));
    tft.print("R: ");
    tft.println(str_num(reg_rep));
    
    if (c == 0) {
      tft.print("    ");
      tft.setTextColor(ST77XX_WHITE, ST77XX_GREEN);
      tft.print(resp[c]);
      tft.setTextColor(ST77XX_WHITE, ST77XX_BLACK);
      tft.print("    ");
    }
    else if(c==1) {
      tft.print("    ");
      tft.setTextColor(ST77XX_WHITE, ST77XX_RED);
      tft.print(resp[c]);
      tft.setTextColor(ST77XX_WHITE, ST77XX_BLACK);
      tft.print("    ");
    }
    else if(c==2) {
      
      tft.print("  ");
      tft.setTextColor(ST77XX_WHITE, gris);
      tft.print(resp[c]);
    }

    
    if (!digitalRead(enter) && c == 0) {
      EEPROM.write(add_hora[reg_addr], reg_hora);
      EEPROM.write(add_minuto[reg_addr], reg_minuto);
      EEPROM.write(add_duracion[reg_addr], reg_duracion);
      EEPROM.write(add_estado[reg_addr], reg_rep);
      EEPROM.commit();
      barrido();
      tft.setTextSize(2);                 // text size = 2
      tft.setCursor(30, 90);
      tft.setTextColor(ST77XX_GREEN, ST77XX_BLACK);
      tft.println("DATOS GUARDADOS");
      delay(1000);
      ESP.restart();
    }
    if (!digitalRead(enter) && c == 1) {
      barrido();
      tft.setTextSize(2);                 // text size = 2
      tft.setCursor(10, 90);
      tft.setTextColor(ST77XX_RED, ST77XX_BLACK);
      tft.println("DATOS NO GUARDADOS");
      delay(1000);
      ESP.restart();
    }
    if (!digitalRead(enter) && c == 2) {
      rep_duracion(reg_duracion,reg_rep);
      barrido();
    }
    b++;
    delay(1);
    barrido(1);

  }
}
