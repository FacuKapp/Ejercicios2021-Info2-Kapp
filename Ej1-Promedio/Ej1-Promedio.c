#include <stdio.h>

/* Ej1-Promedio: Escriba un programa que calcule e imprima el promedio de varios enteros.
Debe pedir al usuario que primero ingrese los números que desea uno a uno. Cuando haya
ingresado los números deseados debe ingresar el valor 9999, para así proceder al cálculo. */

#define LimiteNumeros 200
#define NumeroFin 9999

void IngresaNumeros( int Numeros[], int *CantNumeros );

int main ()
{
    int Numeros[LimiteNumeros];             //Guarda los numeros ingresados
    int CantNumeros = 0;                    //Cantidad de numeros a ingresar
    float Promedio = 0;                     //Variable que guarda el resultado del promedio


    printf("Prog. para calcular el promedio de N numeros enteros ingresados por teclado \n");
    printf("----------------------------------------------------------------------------- \n");

    printf("Cuantos numeros desea ingresar: ");
    scanf("%d", &CantNumeros);

    IngresaNumeros( Numeros, &CantNumeros );
}

IngresaNumeros( Numeros[], *CantNumeros )
{
    int i = 0;                              //Contador

    do
    {
        scanf("%d", &Numeros[i]);
        i++;
    }
    while( Numero[i] =! NumeroFin || i < *CantNumeros );
}