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
  PORTD = B00000000;

  for(i = 0; i <= 8; i++)
  {
    PORTD = PORTD | (1<<i);
    delay(TIEMPO);
  }
}