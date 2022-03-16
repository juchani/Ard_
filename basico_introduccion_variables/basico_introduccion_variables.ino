//  Lenguaje de bajo nivel  legos 
//  Lenguaje de alto nivel ladrillos
//  IDE: ES EL PROGRAMA DONDE SE ESCRIBE EL CODIGO
//  IDE: compilacion(conversion del lenguaje de programacion a binario)
//  IDE: enviar el archivo al microcontrolador
//  lenguaje de alto nivel c++
/////////variables: son letras-palabras las cuales tienen la capacidad de almacenar valores
//  sintaxis
//  tipo_de_variable nombre_de_la_variable 
//  variabable = valor

//  int solo numeros enteros
//  float almacena decimales
//  bool  almacena numeros binarios
//  byte almacena numeros enteros de 0 a 255
//  char almacena un caracter
//  String almacena cadena de caracteres  
String numero="hola \n \teste es un string";

void setup() {
Serial.begin(9600);


}

void loop() {
Serial.println(numero);  

}
