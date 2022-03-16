#define led 3
volatile byte comando = 0;
volatile int contador = 0;

void setup(void)
{
pinMode(led,OUTPUT);
Serial.begin(9600);

  // Configurar MISO como salida esclavo (slave out)
  pinMode(MISO, OUTPUT);

  // Activa el bus SPI en modo esclavo
  SPCR |= _BV(SPE);
  // Activa las interrupciones en el bus SPI
  SPCR |= _BV(SPIE);
} 

// Rutina de servicio de interrupciones del bus SPI
ISR (SPI_STC_vect)
{
  bool c = SPDR;
  digitalWrite(led,c);
  contador=0;
  
}  

void loop(void)
{

  // Si el bus SPI no esta activo, borra el actual comando
  if (digitalRead (SS) == HIGH){
comando = 0;
  }
    if (contador>400){
      contador=0;
      digitalWrite(led,0);
    }
    contador++;
    delay(1);
}