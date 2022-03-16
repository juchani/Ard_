#define led 14
bool st;
void setup() {
pinMode(led,OUTPUT);
}

void loop() {
digitalWrite(led,st);
delay(1000);
st=!st;
}
