void front(){
 // tft.fillRect(0, 79, tft.width(), 2, ST77XX_BLUE);
 // tft.fillRect(0, 173, tft.width(), 2, ST77XX_BLUE);

/*  tft.setTextWrap(true);                        // turn off text wrap option
  tft.setTextColor(ST77XX_WHITE, ST77XX_BLACK);  // set text color to white and black background
  tft.setTextSize(6);                 // text size = 2
  tft.setCursor(30, 18);             // move cursor to position (28, 27) pixel
  tft.print(str_num(hora_));
  tft.print(":");
  tft.println(str_num(minuto_));
  tft.setTextSize(4);
  tft.println(str_num(c));
//  tft.setCursor(0, 90);             // move cursor to position (28, 27) pixel
  tft.print(str_num(hora[c]));
  tft.print(":");
  tft.println(str_num(minuto[c]));
  tft.print("D: ");
  tft.println(str_num(duracion[c]));
  tft.print("R: ");
  tft.println(str_num( estado[c]));
//  tft.fillScreen(ST77XX_WHITE);
/*  tft.setTextFont(7);
  tft.setTextSize(1);
  tft.setTextColor(TFT_WHITE);
  tft.setCursor(25, 5);
  tft.print(hora_);
  tft.print(":");
  tft.println(minuto_);
  tft.setTextSize(1);
  tft.setTextFont(4);
  tft.print(c);
  tft.print(" ");
  tft.print(hora[c]);
  tft.print(":");
  tft.print(minuto[c]);
  tft.print(" ");
  tft.println(duracion[c]);*/
}
void capa_1(){
/*  tft.setTextWrap(true);                        // turn off text wrap option
  tft.setTextColor(ST77XX_WHITE, ST77XX_BLACK);  // set text color to white and black background
  tft.setTextSize(6);                 // text size = 2
  tft.setCursor(30, 30);             // move cursor to position (28, 27) pixel
  tft.print(str_num(c));
  tft.print(":");
  tft.println(str_num(0));  */
}

String str_num(int n){
  String num;
 if(n<10){
  num="0"+String(n);
   
 }
 else{
  num=String(n);
 }
 return num;
}
