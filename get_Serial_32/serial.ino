void updateSerial()
{
  if (rs232.available())
  {
    Serial.println("..");
    String cero[20] = rs232.readStringUntil('\n');
    for (int i; i < 20; i++) {
      //CONFIRMACION INICIO-FIN
      if (cero[i].indexOf("t?") > -1 && i == 0) {
        error = 0;
      }
      if (cero[i].indexOf("t?") > -1 && i > 0) {
        Serial.print(" error");
        error = 1;
        for (int e; e < 20; e++) {
          cero[e] = "";
        }
        break;
      }
      if (cero[i].length() == 0) {
        cero[i] = "°";
        vacio++;
      }

      Serial.print(i);
      Serial.print('\t');
      Serial.println(cero[i]);
      if (vacio > 1) {
        limite = i;
        vacio=0;
        break;
      }
    }

    if (error == 0) {

      //DATOS REG
      /*  for (int t = 3; t < 8; t++) {
          String inf = decoder(cero[t], 1, t);
          inf.trim();
          E += "|" + inf;
        }*/
      //ITEM CODE
      for (int c = 2; c < limite; c++) {
        if (c > 2 && c < 8) {
          String inf = decoder(cero[c], 1, c);
          inf.trim();
          E += "|" + inf;
        }
        if (cero[c] != "°" && c > 9) {
          item_code.trim();
          test_result.trim();
          item_code = item_code + "$" + decoder(cero[c], 0, c);
          test_result = test_result + "$" + decoder(cero[c], 1, c);
        }
        //FECHA-HORA
        date_time = decoder(cero[2], 1, 2);
        date_time.trim();
        date_time.replace("-", "");
        date_time.replace(":", "");
        date_time.replace(" ", "|");
      }


      E = li(0, E);
      item_code = li(0, item_code);
      test_result = li(0, test_result);
      date_time = li(0, date_time);
      ref_max = li(1, ref_max);
      ref_min = li(1, ref_min);
      test_result.remove(0, 1);
      item_code.remove(0, 1);
//      test_result.replace(" ", "%20");
//      E.replace(" ", "%20");
//      item_code.replace(" ", "%20");
      Serial.print(E);
      Serial.print(item_code);
      Serial.print(test_result);
      Serial.print(ref_max);
      Serial.print(ref_min);
      Serial.print(date_time);
      Serial.println(ver);
      String u = E + item_code + test_result + ref_max + ref_min + date_time + ver;
      Serial.print("-----------------  ");
      //Serial.println(u.indexOf("|"));
      Serial.println(u.length());
      if(u.length()>100){ //&& u.startsWith(E)
        envio(u);
        delay(500);
      }
      else{
        u="";
      }
      
      
      item_code = "";
      test_result = "";
      date_time = "";
      E = "";
      ref_max = "";
      ref_min = "";

    }
    for (int i; i < 20; i++) {
      cero[i] = "";
    }
  }
}
