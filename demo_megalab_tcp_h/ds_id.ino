void ds_id(){
  pixels.clear();
    if((uid16data[5])>0){
      pixels.setPixelColor(0, pixels.Color(0, 150, 0));
      pixels.show();
      uid16data[13]=1;
      
    }
    else{
      pixels.setPixelColor(0, pixels.Color(150, 0, 0));
     pixels.show();
     uid16data[13]=0;
    }
if((uid16data[6])>0){
      pixels.setPixelColor(1, pixels.Color(0, 150, 0));
      pixels.show();
      uid16data[14]=1;
    }
    else{
      pixels.setPixelColor(1, pixels.Color(150, 0, 0));
     pixels.show();
     uid16data[14]=0;
    }
    if((uid16data[7])>0){
      pixels.setPixelColor(2, pixels.Color(0, 150, 0));
      pixels.show();
      uid16data[15]=1;
      }
    else{
     pixels.setPixelColor(2, pixels.Color(150, 0, 0));
     pixels.show();
     uid16data[15]=0;
    }
    if((uid16data[8])>0){
      pixels.setPixelColor(3, pixels.Color(0, 150, 0));
      pixels.show();
      uid16data[16]=1;
      }
    else{
     pixels.setPixelColor(3, pixels.Color(150, 0, 0));
     pixels.show();
     uid16data[16]=0;
    }
    if((uid16data[9])>0){
      pixels.setPixelColor(4, pixels.Color(0, 150, 0));
      pixels.show();
      uid16data[17]=1;
      }
    else{
     pixels.setPixelColor(4, pixels.Color(150, 0, 0));
     pixels.show();
     uid16data[17]=0;
    }
    if((uid16data[10])>0){
      pixels.setPixelColor(5, pixels.Color(0, 150, 0));
      pixels.show();
      uid16data[18]=1;
      }
    else{
     pixels.setPixelColor(5, pixels.Color(150, 0, 0));
     pixels.show();
     uid16data[18]=0;
    }
}
