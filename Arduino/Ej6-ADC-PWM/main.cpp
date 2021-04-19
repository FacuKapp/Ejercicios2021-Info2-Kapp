/* Realizar la medición de un sensor conectado al ADC y producir una variación proporcional en la salida PWM. Ejemplos:
• Potenciómetro que regule el brillo de un LED, la velocidad de un motor o ventilador.
• LDR que regule el brillo de un LED.
• Sensor de temperatura que regules la velocidad de un ventilador. */

#include <Arduino.h>

#define Sensor A0                   //Pin lectura sensor analogica
#define Led 4                       //Pin Led salida analogica (PWM)

int LecturaSensor = 0;              //Variable para guardar el valor de la lectura

void setup()
{
    pinMode( Sensor, INPUT );       //Sensor como entrada, aunque no hace falta
    pinMode( Led, OUTPUT );         //Led como salida
}


void main()
{
    LecturaSensor = analogRead( Sensor );           //Lectura del valor de la entrada

    LecturaSensor = (LecturaSensor/4);              ///Ya que la entrada analogica toma valores de 0 a 1023
    ;                                               //y la salida PWM solo de 0 a 255
    analogWrite( Led, LecturaSensor );              //Escritura en la salida PWM
}