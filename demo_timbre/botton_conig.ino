void bot(int limite) {
  if (digitalRead(b1)) {
    c++;
    if (c > limite) {
      c = limite;
    }
    barrido();
    front();
    delay(200);
  }
  if (digitalRead(b2)) {
    c--;
    if (c < 0) {
      c = 0;
    }
    barrido();
    front();
    delay(200);
  }
}

void barrido() {
  //   tft.fillScreen(TFT_BLACK);
  tft.fillScreen(ST77XX_BLACK);
  b = 0;
}
void barrido(int br) {
  if (b > 1000) {
    b = 0;
    tft.fillScreen(ST77XX_BLACK);
  }
}
