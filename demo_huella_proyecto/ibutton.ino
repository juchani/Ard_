bool comparar(byte array1[], byte array2[])
{
  if (array1[0] != array2[0])return (false);
  if (array1[1] != array2[1])return (false);
  if (array1[2] != array2[2])return (false);
  if (array1[3] != array2[3])return (false);
  if (array1[4] != array2[4])return (false);
  if (array1[5] != array2[5])return (false);
  if (array1[6] != array2[6])return (false);
  if (array1[7] != array2[7])return (false);
  return (true);
}

void bip(){
  digitalWrite(buzzer,HIGH);
  delay(100);
  digitalWrite(buzzer,LOW);
  delay(100);
}


void bip_1(){
  digitalWrite(buzzer,HIGH);
  delay(1000);
  digitalWrite(buzzer,LOW);
  delay(1000);
}
