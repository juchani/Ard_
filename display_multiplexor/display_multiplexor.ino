//**************************************************************************************
//*                               RUTINA DE DISPLAY                                    *
//*                                     INICIO                                         *
//**************************************************************************************
//Display 7 Segmentos Cátodo Común
byte cero=  B00111111;
byte uno=   B00000110;
byte dos=   B01011011;
byte tres=  B01001111;
byte cuatro=B01100110;
byte cinco= B01101101;
byte seis=  B01111100;
byte siete= B00000111;
byte ocho=  B01111111;
byte nueve= B01101111;
 
//Delcaración de Los Pines del Display
byte a=2;
byte b=3;
byte c=4;
byte d=5;
byte e=6;
byte f=7;
byte g=8;
byte dp=9;
// Declaración de los Pines de los Transistores
byte t1=10;
byte t2=11;
byte t3=12;
byte t4=13;
 
// Variables del display
byte UnidadMil= 0;
byte Centena=  0;
byte Decena=  0;
byte Unidad=  1;
// lista de numeros impares 
byte lista[]={1,3,5,7,9};
const int Retardo = 10;


//Función que coloca en el puerto de salida los bits comenzando
// desde el pin ini hasta el pin fin
void puerto(int bits,int ini,int fin){
  for(int i=ini;i<=fin;i++)
  {
    digitalWrite(i,bitRead(bits,i-ini));
  }
}
 
//Función encargada de la multiplexación
void mostrar( ) //Rutina mostrar
{
   //Rutina de Multiplexación
   for(int i=10;i<=13;i++){
  switch (i) {
  case 10:
    //Muestra Unidad
     //escribe el valor
     switch (Unidad) {
   case 0: //CERO   
     puerto(cero,a,dp);
     digitalWrite(i,HIGH);  //Enciende el display de unidades
     delay(Retardo);               //Retardo de 1 milisegundos
     digitalWrite(i,LOW);   //Apaga el display de unidades
     break;
     case 1: //UNO   
     puerto(uno,a,dp);
     digitalWrite(i,HIGH);  //Enciende el display de unidades
     delay(Retardo);               //Retardo de 1 milisegundos
     digitalWrite(i,LOW);   //Apaga el display de unidades
     break;
     case 2: //DOS   
     puerto(dos,a,dp);
     digitalWrite(i,HIGH);  //Enciende el display de unidades
     delay(Retardo);               //Retardo de 1 milisegundos
     digitalWrite(i,LOW);   //Apaga el display de unidades
     break;
     case 3: //TRES   
     puerto(tres,a,dp);
     digitalWrite(i,HIGH);  //Enciende el display de unidades
     delay(1);               //Retardo de 1 milisegundos
     digitalWrite(i,LOW);   //Apaga el display de unidades
     break;
     case 4: //CUATRO   
     puerto(cuatro,a,dp);
     digitalWrite(i,HIGH);  //Enciende el display de unidades
     delay(Retardo);               //Retardo de 1 milisegundos
     digitalWrite(i,LOW);   //Apaga el display de unidades
     break;
     case 5: //CINCO   
     puerto(cinco,a,dp);
     digitalWrite(i,HIGH);  //Enciende el display de unidades
     delay(Retardo);               //Retardo de 1 milisegundos
     digitalWrite(i,LOW);   //Apaga el display de unidades
     break;
     case 6: //SEIS   
     puerto(seis,a,dp);
     digitalWrite(i,HIGH);  //Enciende el display de unidades
     delay(Retardo);               //Retardo de 1 milisegundos
     digitalWrite(i,LOW);   //Apaga el display de unidades
     break;
     case 7: //SIETE   
     puerto(siete,a,dp);
     digitalWrite(i,HIGH);  //Enciende el display de unidades
     delay(Retardo);               //Retardo de 1 milisegundos
     digitalWrite(i,LOW);   //Apaga el display de unidades
     break;
     case 8: //OCHO   
     puerto(ocho,a,dp);
     digitalWrite(i,HIGH);  //Enciende el display de unidades
     delay(Retardo);               //Retardo de 1 milisegundos
     digitalWrite(i,LOW);   //Apaga el display de unidades
     break;
     case 9: //NUEVE   
     puerto(nueve,a,dp);
     digitalWrite(i,HIGH);  //Enciende el display de unidades
     delay(Retardo);               //Retardo de 1 milisegundos
     digitalWrite(i,LOW);   //Apaga el display de unidades
     break;
     } 
    break;
  case 11:
    //Muestra Decenas
     //escribe el valor
     switch (Decena) {
   case 0: //CERO   
     puerto(cero,a,dp);
     digitalWrite(i,HIGH);  //Enciende el display de unidades
     delay(Retardo);               //Retardo de 1 milisegundos
     digitalWrite(i,LOW);   //Apaga el display de unidades
     break;
     case 1: //UNO   
     puerto(uno,a,dp);
     digitalWrite(i,HIGH);  //Enciende el display de unidades
     delay(Retardo);               //Retardo de 1 milisegundos
     digitalWrite(i,LOW);   //Apaga el display de unidades
     break;
     case 2: //DOS   
     puerto(dos,a,dp);
     digitalWrite(i,HIGH);  //Enciende el display de unidades
     delay(Retardo);               //Retardo de 1 milisegundos
     digitalWrite(i,LOW);   //Apaga el display de unidades
     break;
     case 3: //TRES   
     puerto(tres,a,dp);
     digitalWrite(i,HIGH);  //Enciende el display de unidades
     delay(Retardo);               //Retardo de 1 milisegundos
     digitalWrite(i,LOW);   //Apaga el display de unidades
     break;
     case 4: //CUATRO   
     puerto(cuatro,a,dp);
     digitalWrite(i,HIGH);  //Enciende el display de unidades
     delay(Retardo);               //Retardo de 1 milisegundos
     digitalWrite(i,LOW);   //Apaga el display de unidades
     break;
     case 5: //CINCO   
     puerto(cinco,a,dp);
     digitalWrite(i,HIGH);  //Enciende el display de unidades
     delay(Retardo);               //Retardo de 1 milisegundos
     digitalWrite(i,LOW);   //Apaga el display de unidades
     break;
     case 6: //SEIS   
     puerto(seis,a,dp);
     digitalWrite(i,HIGH);  //Enciende el display de unidades
     delay(Retardo);               //Retardo de 1 milisegundos
     digitalWrite(i,LOW);   //Apaga el display de unidades
     break;
     case 7: //SIETE   
     puerto(siete,a,dp);
     digitalWrite(i,HIGH);  //Enciende el display de unidades
     delay(Retardo);               //Retardo de 1 milisegundos
     digitalWrite(i,LOW);   //Apaga el display de unidades
     break;
     case 8: //OCHO   
     puerto(ocho,a,dp);
     digitalWrite(i,HIGH);  //Enciende el display de unidades
     delay(Retardo);               //Retardo de 1 milisegundos
     digitalWrite(i,LOW);   //Apaga el display de unidades
     break;
     case 9: //NUEVE   
     puerto(nueve,a,dp);
     digitalWrite(i,HIGH);  //Enciende el display de unidades
     delay(Retardo);               //Retardo de 1 milisegundos
     digitalWrite(i,LOW);   //Apaga el display de unidades
     break;
     } 
    break;
  case 12:
    //Muestra Centena
     //escribe el valor
     switch (Centena) {
   case 0: //CERO   
     puerto(cero,a,dp);
     digitalWrite(i,HIGH);  //Enciende el display de unidades
     delay(Retardo);               //Retardo de 1 milisegundos
     digitalWrite(i,LOW);   //Apaga el display de unidades
     break;
     case 1: //UNO   
     puerto(uno,a,dp);
     digitalWrite(i,HIGH);  //Enciende el display de unidades
     delay(Retardo);               //Retardo de 1 milisegundos
     digitalWrite(i,LOW);   //Apaga el display de unidades
     break;
     case 2: //DOS   
     puerto(dos,a,dp);
     digitalWrite(i,HIGH);  //Enciende el display de unidades
     delay(Retardo);               //Retardo de 1 milisegundos
     digitalWrite(i,LOW);   //Apaga el display de unidades
     break;
     case 3: //TRES   
     puerto(tres,a,dp);
     digitalWrite(i,HIGH);  //Enciende el display de unidades
     delay(Retardo);               //Retardo de 1 milisegundos
     digitalWrite(i,LOW);   //Apaga el display de unidades
     break;
     case 4: //CUATRO   
     puerto(cuatro,a,dp);
     digitalWrite(i,HIGH);  //Enciende el display de unidades
     delay(Retardo);               //Retardo de 1 milisegundos
     digitalWrite(i,LOW);   //Apaga el display de unidades
     break;
     case 5: //CINCO   
     puerto(cinco,a,dp);
     digitalWrite(i,HIGH);  //Enciende el display de unidades
     delay(Retardo);               //Retardo de 1 milisegundos
     digitalWrite(i,LOW);   //Apaga el display de unidades
     break;
     case 6: //SEIS   
     puerto(seis,a,dp);
     digitalWrite(i,HIGH);  //Enciende el display de unidades
     delay(Retardo);               //Retardo de 1 milisegundos
     digitalWrite(i,LOW);   //Apaga el display de unidades
     break;
     case 7: //SIETE   
     puerto(siete,a,dp);
     digitalWrite(i,HIGH);  //Enciende el display de unidades
     delay(Retardo);               //Retardo de 1 milisegundos
     digitalWrite(i,LOW);   //Apaga el display de unidades
     break;
     case 8: //OCHO   
     puerto(ocho,a,dp);
     digitalWrite(i,HIGH);  //Enciende el display de unidades
     delay(Retardo);               //Retardo de 1 milisegundos
     digitalWrite(i,LOW);   //Apaga el display de unidades
     break;
     case 9: //NUEVE   
     puerto(nueve,a,dp);
     digitalWrite(i,HIGH);  //Enciende el display de unidades
     delay(Retardo);               //Retardo de 1 milisegundos
     digitalWrite(i,LOW);   //Apaga el display de unidades
     break;
     } 
    break;
  case 13:
    //Muestra Unidad de Mil
     //escribe el valor
     switch (UnidadMil) {
   case 0: //CERO   
     puerto(cero,a,dp);
     digitalWrite(i,HIGH);  //Enciende el display de unidades
     delay(Retardo);               //Retardo de 1 milisegundos
     digitalWrite(i,LOW);   //Apaga el display de unidades
     break;
     case 1: //UNO   
     puerto(uno,a,dp);
     digitalWrite(i,HIGH);  //Enciende el display de unidades
     delay(Retardo);               //Retardo de 1 milisegundos
     digitalWrite(i,LOW);   //Apaga el display de unidades
     break;
     case 2: //DOS   
     puerto(dos,a,dp);
     digitalWrite(i,HIGH);  //Enciende el display de unidades
     delay(Retardo);               //Retardo de 1 milisegundos
     digitalWrite(i,LOW);   //Apaga el display de unidades
     break;
     case 3: //TRES   
     puerto(tres,a,dp);
     digitalWrite(i,HIGH);  //Enciende el display de unidades
     delay(Retardo);               //Retardo de 1 milisegundos
     digitalWrite(i,LOW);   //Apaga el display de unidades
     break;
     case 4: //CUATRO   
     puerto(cuatro,a,dp);
     digitalWrite(i,HIGH);  //Enciende el display de unidades
     delay(Retardo);               //Retardo de 1 milisegundos
     digitalWrite(i,LOW);   //Apaga el display de unidades
     break;
     case 5: //CINCO   
     puerto(cinco,a,dp);
     digitalWrite(i,HIGH);  //Enciende el display de unidades
     delay(Retardo);               //Retardo de 1 milisegundos
     digitalWrite(i,LOW);   //Apaga el display de unidades
     break;
     case 6: //SEIS   
     puerto(seis,a,dp);
     digitalWrite(i,HIGH);  //Enciende el display de unidades
     delay(Retardo);               //Retardo de 1 milisegundos
     digitalWrite(i,LOW);   //Apaga el display de unidades
     break;
     case 7: //SIETE   
     puerto(siete,a,dp);
     digitalWrite(i,HIGH);  //Enciende el display de unidades
     delay(Retardo);               //Retardo de 1 milisegundos
     digitalWrite(i,LOW);   //Apaga el display de unidades
     break;
     case 8: //OCHO   
     puerto(ocho,a,dp);
     digitalWrite(i,HIGH);  //Enciende el display de unidades
     delay(Retardo);               //Retardo de 1 milisegundos
     digitalWrite(i,LOW);   //Apaga el display de unidades
     break;
     case 9: //NUEVE   
     puerto(nueve,a,dp);
     digitalWrite(i,HIGH);  //Enciende el display de unidades
     delay(Retardo);               //Retardo de 1 milisegundos
     digitalWrite(i,LOW);   //Apaga el display de unidades
     break;
     } 
    break;
  }
     }

}
 
 
//Configura todos los pines como Salidas
void setup() {
    pinMode(a,OUTPUT);
    pinMode(b,OUTPUT);
    pinMode(c,OUTPUT);
    pinMode(d,OUTPUT);
    pinMode(e,OUTPUT);
    pinMode(f,OUTPUT);
    pinMode(g,OUTPUT);
    pinMode(dp,OUTPUT);
    pinMode(t1,OUTPUT);
    pinMode(t2,OUTPUT);
    pinMode(t3,OUTPUT);
    pinMode(t4,OUTPUT);
  digitalWrite(t1,LOW);
  digitalWrite(t2,LOW);
  digitalWrite(t3,LOW);
  digitalWrite(t4,LOW); 
  Serial.begin(9600);
  }

//**************************************************************************************
//*                               RUTINA DE DISPLAY                                    *
//*                                     FIN                                            *
//**************************************************************************************


//**************************************************************************************
//*                               PROGRAMA PRINCIPAL                                   *
//*                                     INICIO                                         *
//**************************************************************************************
 
//Programa Principal
void loop() {

for(int d=0;d<10;d++){  
  for(int i=0;i<5;i++){
  for(int r=0;r<10;r++){
Unidad= lista[i];
mostrar( );

  }
  if(Centena==2&&Decena>4&&Unidad>4){
Centena=0;
Decena=0;
Unidad=0;
i=-1;
}

  }
//  byte Centena=  0;
Decena++;
if(Decena>9){
Decena=0;

}
}
Centena++;
}


//**************************************************************************************
//*                               PROGRAMA PRINCIPAL                                   *
//*                                     FIN                                            *
//**************************************************************************************
