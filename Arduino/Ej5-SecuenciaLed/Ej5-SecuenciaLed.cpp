#include <arduino.h>

/* Prender secuencialmente 3 leds. En todo momento habrá encendido solamente 1 led.
Utilizar 2 pulsadores para controlar el sentido de encendido. Por ejemplo:
Pulsador A: led1 > led2 > led3 > led1 > …
Pulsador B: led1 > led3 > led2 > led1 > … */

#define Puls_A 3
#define Puls_B 4

#define Led_1 6
#define Led_2 7
#define Led_3 8

void setup()
{
    pinMode( Puls_A, INPUT );
    pinMode( Puls_B, INPUT );
    pinMode( Led_1, OUTPUT );
    pinMode( Led_2, OUTPUT );
    pinMode( Led_3, OUTPUT );

}

void loop()
{

}