#include <stdio.h>

/* Definir una estructura complejo que conste de dos miembros en coma flotante llamados real e imaginario.
Declarar una variable x como una estructura del tipo complejo y asignar los valores iniciales 1.3 y -2.2 a los miembros x.real y x.imaginario, respectivamente.
Declarar una variable puntero, px, que apunte a una estructura del tipo complejo. Escribir expresiones para los miembros de la estructura en términos de la variable puntero.
Declarar un array unidimensional de 100 elementos, llamado cx, cuyos elementos sean estructuras del tipo complejo. Escribir expresiones para los miembros del elemento decimoctavo del array. */

#define Pos 17                                      //Posicion a guardar del array cX
#define Posicion "DECIMOCTAVA"                      //Posicion a guardar del array, palabra

struct Complejo                                     //Estructura complejo, con 2 flotantes
{
    float Real;
    float Imaginario;
} X = { 1.3, -2.2 }, *pX = &X, cX[100], *pcX = &cX[Pos]; //variable X={inicializada}, puntero de X, arreglo cX, puntero de cX

void MuestreoNumeros(struct Complejo *ptr);         //Funcion para mostrar los numeros cargados en el arreglo

void IngresoNumeros(struct Complejo *ptr);          //Funcion para ingresar numeros a la estructura, segun el puntero

int main()
{
    MuestreoNumeros(pX);
    IngresoNumeros(pX);
    MuestreoNumeros(pX);
    printf("------------------------------------------------------------ \n");
    printf("AHORA LOS NUMEROS INGRESADOS SE GUARDARAN EN LA POSICION %s DEL ARREGLO cX \n", Posicion);
    printf("------------------------------------------------------------ \n");
    IngresoNumeros(pcX);
    MuestreoNumeros(pcX);
}

void MuestreoNumeros(struct Complejo *ptr)
{
    printf("------------------------------------------------------------ \n");
    printf("Los valores tomados son: \n");
    printf("Real: %.2f \n", ptr->Real);
    printf("Imaginario: %.2f \n", ptr->Imaginario);
    printf("------------------------------------------------------------ \n");
}

void IngresoNumeros(struct Complejo *ptr)
{
    printf("Ingrese nuevos valores para: \n");
    printf("Real: ");
    scanf("%f", &ptr->Real);
    printf("Imaginario: ");
    scanf("%f", &ptr->Imaginario);
}