#include <Arduino.h>
#include <SPI.h>
#include <SD.h>

/*
Conexiones con Arduino UNO
--SCK  PIN 13
--MISO PIN 12
--MOSI PIN 11
--CS   chipSelect
--5 V
--GND
*/

#define CHIPSELECT 4                //Pin chipSelect para comunicacion SPI

struct Sensores
{
  uint32_t TTSensor;            //Tiempo transcurrido de la ultima lectura
  uint16_t VSensor;             //Valor del sensor
  uint8_t NSensor;              //Nombre Sensor

} SensorPrueba = { 2, 126, 'P' },       //Estructura a guardar en la memoria SD
  SensorLectura = { 0, 0, 'X' };        //Estructura a leer de la memoria SD
  

void EscMemSD(void);            //Escritura de la memoria SD

void LecMemSD(void);            //Escritura de la memoria SD

void DatoLeido(void);           //Muestreo por puerto serie del dato leido

void setup() {

  Serial.println("---------------------------------------------------------------------");
  Serial.println("Prog. para guardar una estructura en memoria SD y luego leerla");
  Serial.println("---------------------------------------------------------------------");

  Serial.begin(9600);           //Inicializacion del puerto serie

  Serial.println("Inicializando tarjeta SD...");

  if (!SD.begin(CHIPSELECT))            //En caso de que no se inicialice correctamente
  {
    Serial.println("Error con la tarjeta SD");
    while (1);
  }
  Serial.println("Tarjeta iniciada");   //Si se inicializa correctamente

    EscMemSD();                   //Escritura de la memoria SD

    LecMemSD();                   //Lectura de la memoria SD

    DatoLeido();                  //Muestreo por puerto serie del dato leido

  // put your setup code here, to run once:
}

void loop() {

  // put your main code here, to run repeatedly:
}

/*----------------------------------------------------------------------------------------------*/
/*------------------------------------ Funcion escritura SD ------------------------------------*/
void EscMemSD()
{
  File archivo;                           //Puntero de tipo fichero o "archivo"

  archivo = SD.open("archivo.dat", FILE_WRITE);       //Apertura del archivo en modo escritura
  
  if(archivo)                                         //Si se abre correctamente
  {
    Serial.println("Escribiendo...");                 //Muestreo en puerto serie

    archivo.write((const uint8_t *)&SensorPrueba, sizeof(SensorPrueba));    //Guarda la estructura en la SD

    archivo.close();                                  //Cierra el archivo

    Serial.println("---------------------------------------------------------------------");
    Serial.println("Escritura realizada correctamente");
    Serial.println("---------------------------------------------------------------------");
  }
  else                                                //Si no se abre correctamente
  {
    Serial.println("Error al escribir el archivo");
  }
}

/*----------------------------------------------------------------------------------------------*/
/*------------------------------------ Funcion lectura SD ------------------------------------*/
void LecMemSD()
{
  File archivo;                           //Puntero de tipo fichero o "archivo"

  archivo = SD.open("archivo.dat", FILE_READ);       //Apertura del archivo en modo lectura
  
  if(archivo)                                         //Si se abre correctamente
  {
    Serial.println("Leyendo...");                 //Muestreo en puerto serie

    archivo.read((const uint8_t *)&SensorLectura, sizeof(SensorLectura));    //Guarda la estructura leida de la SD
  
    archivo.close();                                  //Cierra el archivo

    Serial.println("---------------------------------------------------------------------");
    Serial.println("Lectura realizada correctamente");
    Serial.println("---------------------------------------------------------------------");
  }
  else                                                //Si no se abre correctamente
  {
    Serial.println("Error al leer el archivo");
  }
}

/*----------------------------------------------------------------------------------------------*/
/*----------------------------------- Funcion muestreo datos -----------------------------------*/
void DatoLeido()
{
  Serial.print("NombreSensor:");
  Serial.write(SensorLectura.NSensor);
  Serial.println();

  Serial.print("ValorSensor:");
  Serial.println(SensorLectura.VSensor);

  Serial.print("TiempoTranscurridoSensor:");
  Serial.println(SensorLectura.TTSensor);
}