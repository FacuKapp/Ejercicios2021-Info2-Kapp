/* Realizar la medición de un sensor conectado al ADC y producir una variación proporcional en la salida PWM. Ejemplos:
• Potenciómetro que regule el brillo de un LED, la velocidad de un motor o ventilador.
• LDR que regule el brillo de un LED.
• Sensor de temperatura que regules la velocidad de un ventilador. */

#include <Arduino.h>

#define Sensor A0                   //Pin lectura sensor analogica
#define Motor 5                       //Pin Led salida analogica (PWM)

int LecturaSensor = 0;              //Variable para guardar el valor de la lectura

void setup()
{
    pinMode( Sensor, INPUT );       //Sensor como entrada, aunque no hace falta
    pinMode( Motor, OUTPUT );         //Led como salida
}

void loop()
{
    LecturaSensor = analogRead( Sensor );           //Lectura del valor de la entrada

    LecturaSensor = (LecturaSensor/4);              ///Ya que la entrada analogica toma valores de 0 a 1023
    ;                                               //y la salida PWM solo de 0 a 255
    analogWrite( Motor, LecturaSensor );            //Escritura en la salida PWM
}