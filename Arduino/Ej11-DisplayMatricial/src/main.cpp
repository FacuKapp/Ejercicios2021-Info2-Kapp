#include <Arduino.h>

/* Crear un programa que desplace el led encendido de un display matricial para recorrer cada led en orden. Utilizar el acceso directo a los registros de salida del microcontrolador y las operaciones a nivel de bits. */

#define TIEMPO 500            //Tiempo delay

void setup() {
  // put your setup code here, to run once:

  DDRB = DDRB | B011111;              //Coloca como salidas los pines del 8 al 12, dejando igual al 13, del puerto B
  DDRD = DDRD | B01111100;            //Coloca como salida los pines del 2 al 6, dejando iguales al 0, 1 y 7

}

void loop() {
  // put your main code here, to run repeatedly:

  int i = 0;            //Contador de columnas
  int j = 0;            //Contador de filas

  for( j = 4; j >= 0; j-- )              //Contador para las filas
  {
    for( i = 6; i >= 2; i-- )             //Contador para las columnas
    {
      PORTB = PORTB & B100000;            //Coloca los pines de la matriz del puerto B a 0 (anodos)
      PORTD = PORTD | B01111100;          //Coloca los pines de la matriz del puerto D a 1 (catodos)

      PORTB = PORTB | (1<<j);             //Coloca un 1 en la fila correspondiente
      PORTD = PORTD & (~(1<<i));          //Coloca un 0 en la columna correspondiente
      
      delay(TIEMPO);                      //Lo mantiene encendido un tiempo
    }
  }
}