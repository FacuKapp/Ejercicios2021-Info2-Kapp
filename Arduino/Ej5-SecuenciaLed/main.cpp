/* Prender secuencialmente 3 leds. En todo momento habrá encendido solamente 1 led.
Utilizar 2 pulsadores para controlar el sentido de encendido. Por ejemplo:
Pulsador A: led1 > led2 > led3 > led1 > …
Pulsador B: led1 > led3 > led2 > led1 > … */

#include <Arduino.h>

#define Puls_A 11         //Pines Pulsadores
#define Puls_B 12

#define Led_1 6           //Pines Leds
#define Led_2 7
#define Led_3 8

int LedMode = 0;          //Contador para secuencia

void SecuenciaLed( int *LedMode );          //Funcion para prender leds

void setup() {
  // put your setup code here, to run once:

  pinMode( Puls_A, INPUT );                 //Pulsadores como entradas
  pinMode( Puls_B, INPUT );
  pinMode( Led_1, OUTPUT );                 //Leds como salidas
  pinMode( Led_2, OUTPUT );
  pinMode( Led_3, OUTPUT );
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if( digitalRead(Puls_A) == 1 )            //Pulsador secuencia ascendente
  {
    delay(200);                             //Delay por rebote
    LedMode++;
    if( LedMode == 3 ) LedMode = 0;         //Retorno por ascenso
  }

  if( digitalRead(Puls_B) == 1 )            //Pulsador secuencia descendente
  {
    delay(200);                             //Delay por rebote
    LedMode--;
    if( LedMode == -1 ) LedMode = 2;        //Retorno por descenso
  }
  
  SecuenciaLed(&LedMode);                   //Ejecucion de secuencia
  
}

void SecuenciaLed( int *LedMode )
{
  switch(*LedMode)
  {
    case 0:                                 //Prende solo el primer led
      digitalWrite(Led_1, LOW);
      digitalWrite(Led_2, LOW);
      digitalWrite(Led_3, HIGH);
      break;

     case 1:                                 //Prende solo el segundo led
      digitalWrite(Led_1, LOW);
      digitalWrite(Led_2, HIGH);
      digitalWrite(Led_3, LOW);
      break;

     case 2:                                 //Prende solo el tercer led
      digitalWrite(Led_1, HIGH);
      digitalWrite(Led_2, LOW);
      digitalWrite(Led_3, LOW);
      break;
    
     default:                                 //Apaga todos los leds en otro caso
      digitalWrite(Led_1, LOW);
      digitalWrite(Led_2, LOW);
      digitalWrite(Led_3, LOW);
      break;
  }
}