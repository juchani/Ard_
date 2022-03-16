void buscando() {
  tft.fillScreen(TFT_BLACK);
  tft.setCursor(50, 50, 2);//(n,y,x)
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(2);
  tft.print("BUSCANDO");
  tft.fillRoundRect(40, 90, cargando, 5, 1, TFT_WHITE);
  //170
  if (cargando > 140) {
    cargando = 0;
  }
  cargando += 10;
}
void error() {
  tft.fillScreen(TFT_RED);
  tft.setCursor(40, 60, 2);//(n,y,x)
  tft.setTextColor(TFT_RED, TFT_RED);
  tft.fillRoundRect(30, 50, 180, 35, 18, TFT_WHITE);
  tft.setTextSize(1);
  tft.print("Error de conexion de red");
}
void conectado() {
  tft.fillScreen(0x075C01);
  tft.setCursor(40, 60, 2);//(n,y,x)
  tft.setTextColor(TFT_BLACK, TFT_WHITE);
  tft.fillRoundRect(30, 50, 170, 35, 18, TFT_WHITE);
  tft.setTextSize(1);
  tft.print("CONECTADO A ");
  tft.print(ssid);
}
