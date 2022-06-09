#define s1 10
#define s2 11
#define s3 12
#define in1 2
#define in2 3
#define in3 4
#define in4 5
int vel;
int pina = 6;
int pinb = 9;
void setup() {
  pinMode(s1, INPUT);
  pinMode(s2, INPUT);
  pinMode(s3, INPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(pina, OUTPUT);
  pinMode(pinb, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  vel = analogRead(A0);
  vel = map(vel, 0, 1023, 0, 255);
  analogWrite(pina, vel);
  analogWrite(pinb, vel);
  Serial.print(vel);
  Serial.print('\t');
  Serial.print(digitalRead(s1));
  Serial.print('\t');
  Serial.print(digitalRead(s2));
  Serial.print('\t');
  Serial.println(digitalRead(s3));
  
    if (digitalRead(s1) == 1 && digitalRead(s2) == 0 && digitalRead(s3) == 1) {
adelante();
    Serial.println("adelante");
    }
    if (digitalRead(s1) == 1 && digitalRead(s2) == 1 && digitalRead(s3) == 0) {
    izquierda();
    Serial.println("izquierda");
    }
    if (digitalRead(s1) == 0 && digitalRead(s2) == 1 && digitalRead(s3) == 1) {
    derecha();
    Serial.println("derecha");
    }
    if (digitalRead(s1) == 1 && digitalRead(s2) == 1 && digitalRead(s3) == 1) {
    stop_();
    Serial.println("stop");
    }
}




void adelante() {
  stop_();
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
void izquierda() {
  stop_();
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

}
void derecha() {
  stop_();
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

}
void stop_() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
