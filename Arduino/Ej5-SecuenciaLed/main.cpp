/* Prender secuencialmente 3 leds. En todo momento habrá encendido solamente 1 led.
Utilizar 2 pulsadores para controlar el sentido de encendido. Por ejemplo:
Pulsador A: led1 > led2 > led3 > led1 > …
Pulsador B: led1 > led3 > led2 > led1 > … */

#include <Arduino.h>

#define Puls_A 11                   //Pines Pulsadores
#define Puls_B 12

#define NumLeds 3                   //Cantidad de leds
int Leds[NumLeds] = { 8, 7, 6 };    //Pines Leds

#define Tiempo 500                 //Tiempo Led encendido

bool Sentido = 0;          //Contador para secuencia      0 = Incremento   1 = Decremento
int i = 0;                 //Contador global para la funcion de secuencia

void SecuenciaLed( bool *Sentido );          //Funcion para prender leds

void setup() {
  // put your setup code here, to run once:

  pinMode( Puls_A, INPUT_PULLUP );          //Pulsadores como entradas
  pinMode( Puls_B, INPUT_PULLUP );          //Pullup, activacion de resistencias internas
  pinMode( Leds[0], OUTPUT );                 //Leds como salidas
  pinMode( Leds[1], OUTPUT );
  pinMode( Leds[2], OUTPUT );
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if((digitalRead(Puls_A) == 0) && (Sentido == 1))            //Pulsador secuencia ascendente
  {
    delay(200);                             //Delay por rebote
    Sentido = !Sentido;                     //Se invierte el sentido
  }

  if((digitalRead(Puls_B) == 0) && (Sentido == 0))            //Pulsador secuencia descendente
  {
    delay(200);                             //Delay por rebote
    Sentido = !Sentido;                     //Se invierte el sentido
  }

  SecuenciaLed(&Sentido);                   //Ejecucion de secuencia
  
}

void SecuenciaLed( bool *Sentido )
{
  switch(*Sentido)                          //Dependiendo del sentido
  {
    case 0:                                 //Sentido secuencial Ascendente
      
      i++;                                  //Incremento el contador
      if( i == NumLeds ) i = 0;             //Verifica que no se sobrepase
      digitalWrite(Leds[i], HIGH);          //Enciende el led, espera, y lo apaga
      delay(Tiempo);
      digitalWrite(Leds[i], LOW);

      break;

     case 1:                                 //Sentido secuencial Descendente
      
      digitalWrite(Leds[i], HIGH);          //Enciende el led, espera, y lo apaga
      delay(Tiempo);
      digitalWrite(Leds[i], LOW);
      if( i == 0 ) i = NumLeds;             //Verifica que no se sobrepase
      i--;                                  //Decrementa el contador

      break;
  }
}