float Sensibilidad=0.100;
void setup() { 
  Serial.begin(9600);
}

void loop() {
  float voltajeSensor= analogRead(34)*(5 / 4094.0); //lectura del sensor   
  float I=(voltajeSensor-0.5)/Sensibilidad; //Ecuación  para obtener la corriente
  Serial.print("Voltaje: ");
  Serial.println(voltajeSensor); 
  delay(200);     
}
