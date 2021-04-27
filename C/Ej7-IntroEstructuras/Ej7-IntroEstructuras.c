#include <stdio.h>
#include <string.h>

/* Apartir de la estructura dada, escriba una expresión que pueda utilizarse para acceder a los miembros de la estructura en cada una de las siguientes partes:
a) Al miembro apellido de la estructura registroCliente.
b) Al miembro apellido de la estructura apuntada por ptrCliente.
c) Al miembro nombre de la estructura registroCliente.
d) Al miembro nombre de la estructura apuntada por ptrCliente.
e) Al miembro numeroCliente de la estructura registroCliente.
f) Al miembro numeroCliente de la estructura apuntada por ptrCliente.
g) Al miembro numeroTelefonico del miembro personal de la estructura registroCliente.
h) Al miembro numeroTelefonico del miembro personal de la estructura apuntada por ptrCliente.
i) Al miembro direccion del miembro personal de la estructura registroCliente.
j) Al miembro direccion del miembro personal de la estructura apuntada por ptrCliente.
k) Al miembro ciudad del miembro personal de la estructura registroCliente.
l) Al miembro ciudad del miembro personal de la estructura apuntada por ptrCliente.
m) Al miembro estado del miembro personal de la estructura registroCliente.
n) Al miembro estado del miembro personal de la estructura apuntada por ptrCliente.
o) Al miembro codigoPostal del miembro personal de la estructura registroCliente.
p) Al miembro codigoPostal del miembro personal de la estructura apuntada por ptrCliente. */

struct cliente
{
    char apellido[15];
    char nombre[15];
    int numeroCliente;
    
    struct
    {
        char numeroTelefonico[11];
        char direccion[50];
        char ciudad[15];
        char estado[3];
        char codigoPostal[6];
    } personal;
} registroCliente, *ptrCliente = &registroCliente;

char ch;                                //char para limpiar el buffer despues de un scanf

char SelecOpcion();                     //Para elegir opcion de cargar datos por estructura o por puntero a estructura

void CargaDatosEstructura();            //Para cargar los datos a travez de miembros de la estructura

void CargaDatosPunteroEstructura();     //Para cargar los datos a travez de puntero a estructura

void MuestreoDatosCargados();           //Para mostrar por pantalla los datos ingresados, dado cualquier opcion anterior

int main()
{
    printf("Prog. sobre ESTRUCTURAS \n");
    printf("----------------------------------------------------------------------------- \n");
    printf("DEBE INGRESAR EL DATO SOLICITADO Y PRESIONAR ENTER \n");
    printf("----------------------------------------------------------------------------- \n");

    switch(SelecOpcion())                           //De acuerdo a la seleccion de opcion hecha
    {
        case 'A':                                   //Se cargan los datos por miembros de estructura
            CargaDatosEstructura();
            break;

        case 'B':                                   //Se cargan los datos por puntero a estructura
            CargaDatosPunteroEstructura();
            break;
    }

    MuestreoDatosCargados();                        //Se muestran los datos cargados anteriormente
};

char SelecOpcion()
{
    char Opcion;                                    //char que guarda la letra ingresada
    printf("Desea ingresar los datos a travez de: \n");
    printf("A- Los miembros de la estructura \n");
    printf("B- Los miembros de puntero a estructura \n");

    do{
        printf("----------------------------------------------------------------------------- \n");
        printf("INGRESE A O B SOLAMENTE\n");
        printf("----------------------------------------------------------------------------- \n");
        scanf("%c", &Opcion);
    }while(((Opcion != 'A') && (Opcion != 'B')));       //El ciclo se ejecuta mientras se ingresen opciones distintas
    
    while((ch = getchar()) != '\n' && ch != EOF);       //Limpiamos el búfer stdin después del scanf.
    return Opcion;                                      //Devuelve la letra ingresada
};

void CargaDatosEstructura()                             //Se cargan los datos correspondientes a la opcion ingresada
{
    printf("USTED CARGARA LOS DATOS POR ESTRUCTURA(sin puntero)\n");
    printf("----------------------------------------------------------------------------- \n");
    printf("Ingrese el Apellido:");
    gets(registroCliente.apellido);
    printf("Ingrese el Nombre:");
    gets(registroCliente.nombre);
    printf("Ingrese el Numero de Cliente:");
    scanf("%d", &registroCliente.numeroCliente);
    while((ch = getchar()) != '\n' && ch != EOF);       //Limpiamos el búfer stdin después del scanf.
    printf("Ingrese el Numero Telefonico: ");
    gets(registroCliente.personal.numeroTelefonico);
    printf("Ingrese la Direccion: ");
    gets(registroCliente.personal.direccion);
    printf("Ingrese la Ciudad: ");
    gets(registroCliente.personal.ciudad);
    printf("Ingrese el Estado: ");
    gets(registroCliente.personal.estado);
    printf("Ingrese el Codigo Postal: ");
    gets(registroCliente.personal.codigoPostal);
};

void CargaDatosPunteroEstructura()                      //Se cargan los datos correspondientes a la opcion ingresada
{
    printf("USTED CARGARA LOS DATOS POR PUNTERO A ESTRUCTURA\n");
    printf("----------------------------------------------------------------------------- \n");
    printf("Ingrese el Apellido: ");
    gets(ptrCliente->apellido);
    printf("Ingrese el Nombre: ");
    gets(ptrCliente->nombre);
    printf("Ingrese el Numero de Cliente: ");
    scanf("%d", &ptrCliente->numeroCliente);
    while((ch = getchar()) != '\n' && ch != EOF);       //Limpiamos el búfer stdin después del scanf.
    printf("Ingrese el Numero Telefonico: ");
    gets(ptrCliente->personal.numeroTelefonico);
    printf("Ingrese la Direccion: ");
    gets(ptrCliente->personal.direccion);
    printf("Ingrese la Ciudad: ");
    gets(ptrCliente->personal.ciudad);
    printf("Ingrese el Estado: ");
    gets(ptrCliente->personal.estado);
    printf("Ingrese el Codigo Postal: ");
    gets(ptrCliente->personal.codigoPostal);
};

void MuestreoDatosCargados()                             //Se muestran los datos ingresados
{
    printf("----------------------------------------------------------------------------- \n");
    printf("LOS DATOS INGRESADOS FUERON \n");
    printf("----------------------------------------------------------------------------- \n");
    printf("Apellido: %s \n", ptrCliente->apellido);
    printf("Nombre: %s \n", ptrCliente->nombre);
    printf("Numero de Cliente: %d \n", ptrCliente->numeroCliente);
    printf("    Numero Telefonico: %s \n", ptrCliente->personal.numeroTelefonico);
    printf("    Direccion: %s \n", ptrCliente->personal.direccion);
    printf("    Ciudad: %s \n", ptrCliente->personal.ciudad);
    printf("    Estado: %s \n", ptrCliente->personal.estado);
    printf("    Codigo Postal: %s \n", ptrCliente->personal.codigoPostal); 
};
