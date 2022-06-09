int led[]={2,3,4,5,6,7,8,9,10};
int buzzer=12;
void setup() {
  Serial.begin(9600);
for(int i=0;i<9;i++){
 pinMode(led[i],OUTPUT); 
}
pinMode(buzzer,OUTPUT);
}

void loop() {
int n=map(analogRead(A0),0,1023,0,9);
Serial.println(n);
if(n>7){
  digitalWrite(buzzer,HIGH);
  delay(100);
  digitalWrite(buzzer,LOW);
  delay(100);
}
 digitalWrite(led[n],HIGH);
delay(100);
for(int i=0;i<9;i++){
 digitalWrite(led[i],LOW); 
}

}
