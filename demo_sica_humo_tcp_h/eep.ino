void guardar() {
  reg_id_new = mb.Hreg(S_HREG);
  if (reg_id_new == reg_id) {
    
  }
else{
  if(reg_id_new>19){
    EEPROM.writeUInt(add_reg, reg_id_new );
    EEPROM.commit();
     delay(1000);
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(100);
    ESP.restart();
    }
    
}
}
