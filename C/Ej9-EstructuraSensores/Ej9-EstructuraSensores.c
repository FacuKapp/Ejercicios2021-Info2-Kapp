#include <stdio.h>

/* Crear una estructura llamada sensores, la cual deberá estar formada por 3 variables: una tipo char, en la que se almacenará una letra indicativa del tipo de sensor; una tipo int, donde se almacenará el valor del sensor, una tipo unsigned long donde se almacenará el tiempo desde la última medición. Crear una variable como una estructura del tipo sensor y verificar el tamaño de memoria que ocupa. */

struct Sensores
{
    char TipoSensor;
    int ValorSensor;
    long TiempoTrans;
} StVar;

int main()
{
    printf("---------------------------------------------------------------------\n");
    printf("EL TAMANIO DE MEMORIA UTILIZADO ES: \n");
    printf("Estructura StVar: %d bytes \n", sizeof(StVar));
    printf("Miembro StVar.TipoSensor: %d bytes \n", sizeof(StVar.TipoSensor));
    printf("Miembro StVar.ValorSensor: %d bytes \n", sizeof(StVar.ValorSensor));
    printf("Miembro StVar.TiempoTrans: %d bytes \n", sizeof(StVar.TiempoTrans));
    printf("---------------------------------------------------------------------\n");
}