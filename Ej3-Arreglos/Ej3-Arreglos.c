#include <stdio.h>
#include <stdlib.h>

/* Escriba las instrucciones para llevar a cabo cada una de las siguientes tareas:
a) Despliegue el valor del séptimo elemento del arreglo de caracteres f.
b) Introduzca un valor en el elemento 4 del arreglo de punto flotante con un solo subíndice, b.
c) Inicialice en 8 cada uno de los 5 elementos del arreglo entero g.
d) Sume los elementos del arreglo de punto flotante c, el cual contiene 100 elementos.
e) Copie el arreglo a en la primera porción del arreglo b. Suponga que double a[ 11 ], b[ 34 ]; */

void SeptimoElemento(void);
void IngresarCuartoElemento(void);
void ArregloInicializadoOcho(void);
void Suma100ElementosFlotantes(void);
void CopiaDosArreglos(void);

int main()
{
    char Opcion;

    printf("Opciones: \n");
    printf("a) Despliegue el valor del septimo elemento del arreglo de caracteres f. \n");
    printf("b) Introduzca un valor en el elemento 4 del arreglo de punto flotante con un solo subindice, b. \n");
    printf("c) Inicialice en 8 cada uno de los 5 elementos del arreglo entero g. \n");
    printf("d) Sume los elementos del arreglo de punto flotante c, el cual contiene 100 elementos. \n");
    printf("e) Copie el arreglo a en la primera porcion del arreglo b. Suponga que double a[ 11 ], b[ 34 ]; \n");

    printf("----------------------------------------------------------------------------------------------------- \n");
    printf("Ingrese a, b, c, d o e segun la accion que desee:");
    scanf("%c", &Opcion);
    printf("----------------------------------------------------------------------------------------------------- \n");

    switch (Opcion)
    {
    case 'a':
        SeptimoElemento();
        break;
    
    case 'b':
        IngresarCuartoElemento();
        break;

    case 'c':
        ArregloInicializadoOcho();
        break;

    case 'd':
        Suma100ElementosFlotantes();
        break;
    
    case 'e':
        CopiaDosArreglos();
        break;

    default:
        printf("La opcion ingresada es incorrecta \n");         //Finaliza el programa
        return 1;
        break;
    }
}

void SeptimoElemento(void)
{
    char f[30];                         //Arreglo para ingresar una palabra

    printf("Ingrese una palabra sin espacios: ");
    scanf("%s", &f);
    printf("----------------------------------------------------- \n");

    printf("El 7%c elemento del arreglo es el caracter: %c", 248, f[6]);
}

void IngresarCuartoElemento(void)
{
    float b[10] = { 5.45, 1.78, 9.07, 8.90, 0.89, 1.48, 2.99, 9.99, 0.11, 3.34 };  
                                        //Arreglo con elementos de coma flotante
    int i = 0;                          //Contador local

    printf("Ingrese un elemento, que se guardara en la posicion 4 del arreglo: ");
    scanf("%f", &b[4]);                 //Se ingresa un elemento en la posicion 4

    printf("Los 10 elementos del arreglo son: \n");
    for( i = 0; i < 10; i++ )           //Muestreo de los 10 elementos
    {
        printf("%.3f \n", b[i]);
    }
}

void ArregloInicializadoOcho(void)
{
    int g[5] = { 8, 8, 8, 8, 8 };       //Arreglo de 5 elementos, todos inicializados en 8
    int i = 0;                          //Contador local

    printf("Arreglo de 5 elementos, inicializador en 8 \n");
    for( i = 0; i < 5; i++ )            //Muestreo de los 5 elementos
    {
        printf("Elemento g[%d]: ", i);
        printf("%d \n", g[i]);
    }
}

void Suma100ElementosFlotantes(void)
{
    float c[100];                       //Arreglo de coma flotante con 100 elementos
    int i = 0;                          //Contador local
    double Suma = 0.0;                   //Suma de los elementos del arreglo

    for( i = 0; i < 100; i++ )          //Ingreso de numeros flotantes random al arreglo
    {
        c[i] = (rand() / rand())*1.5278;       //Numero random
        Suma = Suma + c[i];                 //Suma total
    }
    printf("La suma de los 100 elementos es: %.4f: ", Suma);
}
void CopiaDosArreglos(void)
{
    int i = 0;                          //Contador local
    int a[11];                          //Arreglo a
    int b[34];                          //Arreglo b

    printf("Elementos del arreglo a: { ");
    for( i = 0; i < 11; i++ )          //Ingreso de numeros random al arreglo a
    {
        a[i] = (rand() % 10);           //Numero random
        printf("%d, ", a[i]);           //Muestreo
    }

    printf("}\nElementos del arreglo b: { ");
    for( i = 0; i < 34; i++ )          //Ingreso de numeros random al arreglo b
    {
        b[i] = (rand() % 10);           //Numero random
        printf("%d, ", b[i]);           //Muestreo
    }

    printf("}\nElementos ya combinados del arreglo b: { ");
    for( i = 0; i < 34; i++ )          //Combinacion de arreglos
    {
        if( i < 11 )                    //Cambia solo los 11 numeros del arreglo a
        {
            b[i] = a[i];                //Intercambio de valores
        }
        printf("%d, ", b[i]);
    }
    printf("}");
}