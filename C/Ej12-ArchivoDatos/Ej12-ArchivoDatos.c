#include <stdio.h>

/* Almacenar en un archivo .dat los datos de una estructura que tenga los mismos campos que la estructura creada en el Ej9-EstructuraSensores (char, uint16_t, uint32_t). Realizar tanto la escritura como la posterior lectura de los datos. Los datos pueden ingresarse a través del teclado. */

#define NumElementos 1

struct Sensores                     //Estructura de tipo sensores a guardar en el archivo
{
    char TipoSensor;                //Tipo de sensor leido
    int ValorSensor;                //Valor de sensor
    long TiempoTrans;               //Tiempo transcurrido
} Sensor1E = { 'T', 27, 1 }, *StVar = &Sensor1E, Sensor1L;
// Struct a escribir, puntero tipo struct, struct para almacenar los datos leidos

int main()
{
    printf("Prog. para crear un archivo, almacenar datos, y luego leerlos \n");
    printf("---------------------------------------------------------------- \n");

    FILE *fptr;                                     //Puntero de tipo FILE, para leer y escribir archivos
    fptr = fopen( "ArchivoDatos.dat", "w" );        //Se abre el archivo en modo escritura

    if( fptr == NULL )                              //En caso de que no se haya podido abrir el archivo
    {
        printf("ERROR AL ABRIR EL ARCHIVO \n");
        return -1;
    }

    fwrite(StVar, sizeof(struct Sensores), NumElementos, fptr);        //Se escribe en el archivo la estructura
    fclose(fptr);                                   //Se cierra el archivo

    printf("DATOS ALMACENADOS CORRECTAMENTE \n");
    printf("---------------------------------------------------------------- \n");

    StVar = &Sensor1L;                              //Cambio el puntero de tipo estructura
    fptr = fopen( "ArchivoDatos.dat", "r" );        //Se abre el archivo en modo lectura

    if( fptr == NULL )                              //En caso de que no se haya podido abrir el archivo
    {
        printf("ERROR AL ABRIR EL ARCHIVO \n");
        return -1;
    }

    fread(StVar, sizeof(struct Sensores), NumElementos, fptr);        //Se escribe en el archivo la estructura
    fclose(fptr);                                   //Se cierra el archivo

    printf("El sensor leido fue -%c- \n", Sensor1L.TipoSensor);         //Se muestran los valores leidos del archivo
    printf("Su valor es: %d \n", Sensor1L.ValorSensor);
    printf("El tiempo transcurrido fue de: %d hs \n", Sensor1L.TiempoTrans);

    return 0;
}