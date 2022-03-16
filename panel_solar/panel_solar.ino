
int dia =30;
float lat=-31.41;
float lon=-64.10;
int hora=10;
int gtm=-3;
void setup() {
 Serial.begin(9600);

}

void loop() {
 float b=0.98630*(dia-81);
 float lstm=15*gtm;
 float bv;
while(b>180){
b=b-180;
bv=b;
}
 bv=50* M_PI / 180;
 double a=9.87*sin(bv*2);
 double e=7.53*cos(bv);
 double c=1.5*sin(bv);
// double et=a;//+e+c; 
 double et=9.87*sin(bv*2)+(7.53*cos(bv))+(1.5*sin(bv));
 float tc=4*(lon-lstm)+(et*(M_PI/180));
 float lst=hora+(tc/60);
float w=(lst-12)* 15;
 Serial.print("B ");
 Serial.print(b);
 Serial.print(" Bv ");
 Serial.print(bv);
 Serial.print(" LSTM ");
 Serial.print(lstm);
 Serial.print(" ET ");
 Serial.print(et);
 Serial.print(" TC ");
 Serial.print(tc);
 Serial.print(" LST ");
 Serial.print(lst);
 Serial.print(" w ");
 Serial.print(w);
 
 Serial.println();
}
 