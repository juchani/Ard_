#define m1a 2
#define m1b 4
#define m2a 6
#define m2b 7
#define m3a 11
#define m3b 8
#define m4a 12
#define m4b 13

int pwm1=3;
int pwm2=5;
int pwm3=9;
int pwm4=10;

void setup() {
 Serial.begin(9600);
 pinMode(pwm1,OUTPUT); 
 pinMode(pwm2,OUTPUT); 
 pinMode(pwm3,OUTPUT); 
 pinMode(pwm4,OUTPUT);
 pinMode(m1a,OUTPUT);
 pinMode(m1b,OUTPUT);
 pinMode(m2a,OUTPUT);
 pinMode(m2b,OUTPUT);
 pinMode(m3a,OUTPUT);
 pinMode(m3b,OUTPUT);
 pinMode(m4a,OUTPUT);
 pinMode(m4b,OUTPUT);
  
}

void loop() {
  int x=analogRead(A0);
  int y=analogRead(A1);
  int z=analogRead(A2);
  int p=analogRead(A3);
//  x=map(x,0,1023,0,4);
  Serial.println(x);
  velocidad();
if(x<250){
  digitalWrite(m1a,1);
}

else if(x>800){
  digitalWrite(m1b,1);
}
else{
  digitalWrite(m1a,0);
  digitalWrite(m1b,0);
}
if(y<250){
  digitalWrite(m2a,1);
}

else if(y>800){
  digitalWrite(m2b,1);
}
else{
  digitalWrite(m2a,0);
  digitalWrite(m2b,0);
}
if(z<250){
  digitalWrite(m3a,1);
}

else if(z>800){
  digitalWrite(m3b,1);
}
else{
  digitalWrite(m3a,0);
  digitalWrite(m3b,0);
}
if(p<250){
  digitalWrite(m4a,1);
}

else if(p>800){
  digitalWrite(m4b,1);
}
else{
  digitalWrite(m4a,0);
  digitalWrite(m4b,0);
}
}



void velocidad(){
    analogWrite(pwm1,250);
    analogWrite(pwm2,250);
    analogWrite(pwm3,250);
    analogWrite(pwm4,250);
}
