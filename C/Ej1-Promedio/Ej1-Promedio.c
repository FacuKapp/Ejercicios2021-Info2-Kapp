#include <stdio.h>

/* Ej1-Promedio: Escriba un programa que calcule e imprima el promedio de varios enteros.
Debe pedir al usuario que primero ingrese los números que desea uno a uno. Cuando haya
ingresado los números deseados debe ingresar el valor 9999, para así proceder al cálculo. */

#define LimiteNumeros 200
#define NumeroFin 9999

void IngresaNumeros( int Numeros[] );

void CalculoPromedio( int Numeros[], float *Promedio );

int main ()
{
    int Numeros[LimiteNumeros];             //Guarda los numeros ingresados
    int CantNumeros = 0;                    //Cantidad de numeros a ingresar
    float Promedio = 0;                     //Variable que guarda el resultado del promedio


    printf("Prog. para calcular el promedio de N numeros enteros ingresados por teclado \n");
    printf("----------------------------------------------------------------------------- \n");

    IngresaNumeros( Numeros );                   //Ingreso de numeros

    CalculoPromedio( Numeros, &Promedio );       //Calculo del promedio de los numeros ingresados

    printf("----------------------------------------------------------------------------- \n");
    printf("El promedio de los numeros ingresados es: %f", Promedio);       //Muestreo del resultado

}

void IngresaNumeros( int Numeros[] )
{
    int i = 0;                              //Contador

    do
    {
        printf("DEDE INGRESAR ALMENOS 1 NUMERO \n");
        printf("Ingrese el %d%c numero: ", (i+1), 248);        //Ingreso del i-esimo numero
        scanf("%d", &Numeros[i]);

    }while( Numeros[i] == 9999 );                               //El ciclo se produce mientras no ingrese ningun numero
    
    i++;                                                        //Incremento el contador y la posicion del arreglo
    
    do
    {
        printf("Ingrese el %d%c numero: ", (i+1), 248);        //Ingreso del i-esimo numero
        scanf("%d", &Numeros[i]);
        i++;                                                   //Incrementa el contador, o la posicion del arreglo

    }while( Numeros[i-1] != NumeroFin );                       //Se produce el ciclo hasta que se ingrese el 9999

}

void CalculoPromedio( int Numeros[], float *Promedio )
{
    int i = 0;              //Contador

    do
    {
        *Promedio = *Promedio + Numeros[i];         //Suma de los numeros ingresados
        i++;                                        //Incremento del contador y la posicion del arreglo

    }while( Numeros[i] != NumeroFin  );             //Se produce el ciclo hasta que el numero ingresado

    *Promedio = (*Promedio / i);                    //Divide la suma por la cantidad de numeros ingresados

}