#include <stdio.h>

/* Para cada una de las siguientes, escriba una sola instrucción que realice la tarea indicada.
Suponga que se definieron las variables long integer valor1 y valor2, y que valor1 se inicializó
en 200000.
a) Defina la variable ptrL para que apunte a un objeto de tipo long.
b) Asigne la dirección de la variable valor1 para que apunte a la variable ptrL.
c) Imprima el valor del objeto al que apunta ptrL.
d) Asigne a la variable valor2 el valor del objeto al que apunta ptrL.
e) Imprima el valor de valor2.
f) Imprima la dirección de valor1.
g) Imprima la dirección almacenada en ptrL. ¿El valor que se imprimió es el mismo que la dirección
de valor1? */

int main()
{
    long int valor1 = 200000;               //Variable valor1 inicializada cpn un valor
    long int valor2;                        //Variable valor 2 sin inicializar

    long int *ptrL;                         //Variable tipo puntero para archivo long int

    printf("Prog. sobre punteros \n");
    printf("------------------------------------------------------------------------------ \n");

    ptrL = &valor1;                         //Al puntero se le asigna la direccion de la variable

    printf("Valor1: %i \n", valor1);
    printf("El contenido de ptrL es: %i \n", *ptrL);

    valor2 = *ptrL;                         //Se le carga a la variable lo que contiene el puntero

    printf("Valor2: %d \n", valor2);        //Se muestra el contenido de valor2
    printf("La direccion de valor1 es: %x \n", &valor1);       //Muestra la direccion de la variable valor1
    printf("La direccion a la que apunta ptrL es: %x \n", ptrL);       //Muestra la direccion de la variable valor1

    printf("El puntero apunta a la direccion de la variable valor1");       //Muestra la direccion de la variable valor1
}