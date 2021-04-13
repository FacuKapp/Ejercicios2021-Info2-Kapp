#include <stdio.h>
#include <math.h>

/* modifique el programa para repetir sus pasos para tasas de interés del 5 por ciento, 6 por ciento,
8 por ciento, 9 por ciento, y 10 por ciento. Utilice un for para crear un ciclo que varíe la tasa de
interés. */

#define CantTasas 5
#define CantAnios 10

int main()
{
    double Monto;                                           //Monto del deposito
    double Principal = 1000;                                //Monto principar ingresado
    // Tasas                    5%    6%   8%   9%   10%
    double Tasas[CantTasas] = { .05, .06, .08, .09, .10 };
    int Anio;                                               //Contador de años
    int i;                                                  //Contador para las tasas

    printf("Prog. para calcular el interes de un monto durante 10 anios y mostrarlo \n");
    printf("----------------------------------------------------------------------------- \n");

    for( i = 0; i < CantTasas; i++ )                                //Calcula el monto del deposito para cada tasa
    {
        printf("--------------- Tasa %.1f%c ------------------\n", (Tasas[i]*100), '%');       //Separador intereses

        printf(" Anio        Monto del deposito \n");     //Encabezado de la tabla
        for( Anio = 1; Anio <= CantAnios; Anio++)                   //Calcula el monto del deposito para cada año
        {
            Monto = Principal * pow(( 1 + Tasas[i]), Anio);         //Calculo del monto para el año y el interes indicado

            printf(" %d     %21.2f \n", Anio, Monto);                //Muestra cada linea de la tabla
        }
    }
}