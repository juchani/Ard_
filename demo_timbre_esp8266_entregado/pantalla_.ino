void front(){
 // tft.fillRect(0, 79, tft.width(), 2, ST77XX_BLUE);
 // tft.fillRect(0, 173, tft.width(), 2, ST77XX_BLUE);

  tft.setTextWrap(true);                        // turn off text wrap option
  tft.setTextColor(ST77XX_WHITE, ST77XX_BLACK);  // set text color to white and black background
  tft.setTextSize(6);                 // text size = 2
  tft.setCursor(30, 18);             // move cursor to position (28, 27) pixel
  tft.print(str_num(hora_));
  tft.print(":");
  tft.println(str_num(minuto_));
  tft.setTextSize(1);
  tft.println(" ");
  tft.setTextSize(2);
  tft.setTextColor(gris, ST77XX_BLACK);
  tft.println("   "+dia+", "+str_num(dia_)+" de "+mes_[mes]);
  tft.println(" ");
  tft.setTextColor(ST77XX_WHITE, ST77XX_BLACK);
  tft.setTextSize(4);
  //tft.println(" ");
  tft.print("Dir: ");
  tft.setTextColor(ST77XX_GREEN, ST77XX_BLACK);
  tft.println(str_num(c));
  
  //tft.setTextSize(4); 
  if(hora[c]>5 && hora[c] <20){
  tft.setTextColor(gris, ST77XX_BLACK);  
  }
  else{
    tft.setTextColor(ST77XX_RED, ST77XX_BLACK);
  }
  tft.print("  ");
  tft.print(str_num(hora[c]));
  tft.print(":");
  tft.println(str_num(minuto[c]));
  tft.setTextColor(ST77XX_WHITE, ST77XX_BLACK);
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
  tft.setTextWrap(true);                        // turn off text wrap option
  tft.setTextColor(ST77XX_WHITE, ST77XX_BLACK);  // set text color to white and black background
  tft.setTextSize(6);                 // text size = 2
  tft.setCursor(30, 30);             // move cursor to position (28, 27) pixel
  tft.print(str_num(c));
  tft.print(":");
  tft.println(str_num(0));  
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
void descanzo(bool encendido){
  if(encendido==1){
 digitalWrite(en_p, 1);
  }
  else{
 digitalWrite(en_p, 0);
  }
}

void dormir(){
  if(cc>100){
    descanzo(0);
  }
}

void despertar(){
    descanzo(1);
    cc=0;
}
