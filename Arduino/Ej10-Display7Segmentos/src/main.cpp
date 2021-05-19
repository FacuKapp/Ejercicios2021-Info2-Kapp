#include <Arduino.h>

/* Crear un programa que desplace el led encendido de un display 7 segmentos para recorrer cada uno de los segmentos en orden (a,b … g, punto). Utilizar el acceso directo a los registros de salida del microcontrolador y las operaciones a nivel de bits. */

#define TIEMPO 1000

void setup() {
  // put your setup code here, to run once:

  DDRD = B11111111;           //Coloca todo el puerto D como salida (8 pines)
}

void loop() {
  // put your main code here, to run repeatedly:

  int i = 0;          //Contador

  for(i = 7; i >= 0; i--)             //Por la conexion el el Tinkercad, inicia del 7 al 0
  {
    PORTD = B00000000;				        //Apaga todo el puerto D completo
    PORTD = PORTD | (1<<i);           //Mueve el bit en 1 por cada vuelta del for
    delay(TIEMPO);                    //Espera un tiempo
  }
}