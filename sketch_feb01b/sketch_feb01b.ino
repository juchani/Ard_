
int servo =12;
void setup() {
 pinMode (servo, OUTPUT);
 Serial.begin(9600);
}

void loop() {

 //  {==[=======> (180°) <=======]==}
 for (int Hz =0; Hz < 50 ;Hz++){      // repetimos la instruccion 50 veces
digitalWrite (servo,HIGH); 
delayMicroseconds(2300);               // llevamos a 180°
digitalWrite (servo,LOW);
delay(18);
Serial.println(Hz);
 }
delay(1000);                          // retardo

/*// {==[=======> (90°) <=======]==}
 for (int Hz =0; Hz < 50 ;Hz++){     // repetimos la instruccion 50 veces
digitalWrite (servo,HIGH);
delayMicroseconds(1500);                // llevamos a 90°
digitalWrite (servo,LOW);
delay(19);
Serial.println(Hz);
 }
delay(1000);
*/
// {==[=======> (0°) <=======]==}
 for (int Hz =0; Hz < 50 ;Hz++){      // repetimos la instruccion 50 veces
digitalWrite (servo,HIGH);
delayMicroseconds(700);                // llevamos a 0°
digitalWrite (servo,LOW);
delay(20);
Serial.println(Hz);  
 }
 delay(1000);
}
