void panel_sup() {
   h = dht.readHumidity();
   t = dht.readTemperature();
  
  if(h>limite_h){
    digitalWrite(ventilador,HIGH);
  }
  else{
    digitalWrite(ventilador,LOW);
  }
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
  }
  lcd.setCursor(0, 0);
  lcd.print(hora_);
  lcd.print(parpadeo[st]);
  lcd.print(minuto_);
  lcd.print("  ");
  lcd.print(t);
  lcd.print("C ");
  lcd.print(h);
  lcd.print("% ");
}

void pantalla() {
  panel_sup();
  lcd.setCursor(0, 1);
  puntero[0] = String(ind + 1);
  lcd.print(puntero[st]);
  lcd.print(" ");
  lcd.print(hora[ind]);
  lcd.print(parpadeo[0]);
  lcd.print(minuto[ind]);
  lcd.print("  ");
  lcd.print(duracion[ind]);
  lcd.print(" S");
  delay(300);
  st = !st;
  lcd.clear();

}
void pantalla_1(int g) {
  panel_sup();
  lcd.setCursor(0, 1);
  if (g > 9) {
    puntero[1] = "  ";
  }
  else {
    puntero[1] = " ";
  }
  puntero[0] = String(g);
  lcd.print(ind + 1);
  lcd.print(" ");
  lcd.print(puntero[st]);
  lcd.print(parpadeo[0]);
  lcd.print(minuto[ind]);
  lcd.print("  ");
  lcd.print(duracion[ind]);
  lcd.print(" S");
  delay(500);
  st = !st;
  lcd.clear();
}
void pantalla_2(int g) {
  panel_sup();
  lcd.setCursor(0, 1);
  if (g > 9) {
    puntero[1] = "  ";
  }
  else {
    puntero[1] = " ";
  }
  puntero[0] = String(g);
  lcd.print(ind + 1);
  lcd.print(" ");
  lcd.print(hora[ind]);
  lcd.print(parpadeo[0]);
  lcd.print(puntero[st]);
  lcd.print("  ");
  lcd.print(duracion[ind]);
  lcd.print(" S");
  delay(500);
  st = !st;
  lcd.clear();
}

void pantalla_3(int g) {
  panel_sup();
  lcd.setCursor(0, 1);
  if (g > 9) {
    puntero[1] = "  ";
  }
  else {
    puntero[1] = " ";
  }
  puntero[0] = String(g);
  lcd.print(ind + 1);
  lcd.print(" ");
  lcd.print(hora[ind]);
  lcd.print(parpadeo[0]);
  lcd.print(minuto[ind]);
  lcd.print("  ");
  lcd.print(puntero[st]);
  lcd.print(" S");
  delay(500);
  st = !st;
  lcd.clear();
}
