

int retardo=2;          // Tiempo de retardo en milisegundos (Velocidad del Motor)
int dato_rx;            // valor recibido en grados
int numero_pasos = 0;   // Valor en grados donde se encuentra el motor
String leeCadena;       // Almacena la cadena de datos recibida

void setup() {                
Serial.begin(9600);     // inicializamos el puerto serie a 9600 baudios
pinMode(11, OUTPUT);    // Pin 11 conectar a IN4
pinMode(10, OUTPUT);    // Pin 10 conectar a IN3
pinMode(9, OUTPUT);     // Pin 9 conectar a IN2
pinMode(8, OUTPUT);     // Pin 8 conectar a IN1
}

void loop() {
     paso_der();
      
 
}  ///////////////////// Fin del Loop ///////////////////////////

void paso_der(){         // Pasos a la derecha
 digitalWrite(11, LOW); 
 digitalWrite(10, LOW);  
 digitalWrite(9, HIGH);  
 digitalWrite(8, HIGH);  
   delay(retardo); 
 digitalWrite(11, LOW); 
 digitalWrite(10, HIGH);  
 digitalWrite(9, HIGH);  
 digitalWrite(8, LOW);  
   delay(retardo); 
 digitalWrite(11, HIGH); 
 digitalWrite(10, HIGH);  
 digitalWrite(9, LOW);  
 digitalWrite(8, LOW);  
  delay(retardo); 
 digitalWrite(11, HIGH); 
 digitalWrite(10, LOW);  
 digitalWrite(9, LOW);  
 digitalWrite(8, HIGH);  
  delay(retardo);  
}

void paso_izq() {        // Pasos a la izquierda
 digitalWrite(11, HIGH); 
 digitalWrite(10, HIGH);  
 digitalWrite(9, LOW);  
 digitalWrite(8, LOW);  
  delay(retardo); 
 digitalWrite(11, LOW); 
 digitalWrite(10, HIGH);  
 digitalWrite(9, HIGH);  
 digitalWrite(8, LOW);  
  delay(retardo); 
 digitalWrite(11, LOW); 
 digitalWrite(10, LOW);  
 digitalWrite(9, HIGH);  
 digitalWrite(8, HIGH);  
  delay(retardo); 
 digitalWrite(11, HIGH); 
 digitalWrite(10, LOW);  
 digitalWrite(9, LOW);  
 digitalWrite(8, HIGH);  
  delay(retardo); 
}
        
void apagado() {         // Apagado del Motor
 digitalWrite(11, LOW); 
 digitalWrite(10, LOW);  
 digitalWrite(9, LOW);  
 digitalWrite(8, LOW);  
 }
