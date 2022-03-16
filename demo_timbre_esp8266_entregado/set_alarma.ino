void alarma() {
  enc = minuto_;
  int ena=1;
  if (enc != prev_enc) {
    prev_enc = enc;
    if(dia=="DOM" || dia=="SAB"){
      ena=0;
    }
    for (int adr = 0; adr < lim; adr++) {
      if (hora[adr] == hora_ && minuto_ == minuto[adr] && ena==1) {
        rep_duracion(duracion[adr], estado[adr]);
      }
      //    duracion[i] = EEPROM.read(add_duracion[i]);
      //    estado[i] = EEPROM.read(add_estado[i]);
    }
  }
}
void rep_duracion(int d, int r) {
  if (d != 0 && r != 0) {
    for (int rep = 0; rep < r; rep++) {
      barrido();
      tft.setTextSize(2);                 // text size = 2
      tft.setCursor(70, 90);
      tft.setTextColor(ST77XX_GREEN, ST77XX_BLACK);
      tft.println("ENCENDIDO");
      digitalWrite(buzzer, 0);
      delay(d * 1000);
      barrido();
      tft.setTextSize(2);                 // text size = 2
      tft.setCursor(80, 90);
      tft.setTextColor(ST77XX_RED, ST77XX_BLACK);
      tft.println("APAGADO");
      digitalWrite(buzzer, 1);
      delay(1000);
      barrido();
    }
  }


}
