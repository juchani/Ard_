int sensor=A0;
int buzzer=11;
void setup() {
 Serial.begin(9600);
 pinMode(sensor,INPUT_PULLUP);
 pinMode(buzzer,OUTPUT);
}

void loop() {
  Serial.println(digitalRead(sensor));
if(digitalRead(sensor)==0){
   digitalWrite(buzzer,HIGH);
   delay(50000);
}
else{
   digitalWrite(buzzer,LOW);
}
}
