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
  delay(100);
  Firebase.setInt(firebaseData, "fr_comida/sensor1",fr_comida);
  delay(100);
  Firebase.setInt(firebaseData, "fr_agua/sensor1",fr_agua);
 // Firebase.end(firebaseData);
  enc_prev=enc;
  
  }
}
