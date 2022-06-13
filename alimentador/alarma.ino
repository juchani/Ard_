void alarma() {
  enc=minuto_;
  
  if(enc!=enc_prev){
    
  for (int adr = 0; adr < 3; adr++) {
    if (hora[adr] == hora_ && minuto_ == minuto[adr]) {
     dispensador_comida(duracion[adr]);
     dispensador_agua(duracion[adr]);
    }

  }
  Firebase.setInt(firebaseData, "TEMP/sensor1", t);
  delay(100);
  Firebase.setInt(firebaseData, "HUM/sensor1", h);
 // Firebase.end(firebaseData);
  enc_prev=enc;
  
  }
}
