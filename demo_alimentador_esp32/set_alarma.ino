void alarma() {
  enc = minuto_;
  if (enc != prev_enc) {
    prev_enc = enc;
    for (int adr = 0; adr < lim; adr++) {
      if (hora[adr] == hora_ && minuto_ == minuto[adr]) {
        rep_duracion(duracion[adr], estado[adr]);
      }
      //    duracion[i] = EEPROM.read(add_duracion[i]);
      //    estado[i] = EEPROM.read(add_estado[i]);
    }
  }
}
void rep_duracion(int d, int r) {
  for (int rep = 0; rep < r; rep++) {
//    tft.setTextColor(ST77XX_WHITE, ST77XX_GREEN);
//    tft.setCursor(30, 18);             // move cursor to position (28, 27) pixel
//    tft.print("ON");
    digitalWrite(buzzer, HIGH);
    delay(d*1000);
//    tft.setTextColor(ST77XX_WHITE, ST77XX_RED);
//    tft.setCursor(30, 18);             // move cursor to position (28, 27) pixel
 //   tft.print("OFF");
    digitalWrite(buzzer, LOW);
    delay(1000);
  }

}
