#include <Arduino.h>

/* Realizar un programa que pueda recibir dos o más “comandos” por el puerto serie, desde el monitor serial. Cuando reciba alguno de los comandos, debe enviar por el puerto serie la siguiente frase: “Se recibió el comando x” (siendo x el comando recibido). Además, si el comando recibido es la letra “E” se deberá encender un led, y si se recibe “A” deberá apagarse. */

#define LED 13

void LecturaPSerie();                     //Lectura del puerto serie y muestra

void VerificaComandos();                  //Verifica la lectura y enciende o apaga el led

String CadenaRecibida;                    //Cadena recibida por puerto serie

void setup() {
  // put your setup code here, to run once:

  pinMode(LED, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  LecturaPSerie();                         //Lectura del puerto serie y muestra

  VerificaComandos();                      //Verifica la lectura y enciende o apaga el led

}


/* ------------------------------------------------------------------------------------------------------------------ */
/* ------------------------------------------------ Funcion Lectura ------------------------------------------------- */
void LecturaPSerie()
{
  if(Serial.available())                          //Si se envia un dato
  {
    CadenaRecibida = Serial.readString();         //Lectura del dato recibido

    Serial.print("Dato recibido: ");              //Muestreo por puerto serie del dato recibido
    Serial.println(CadenaRecibida);
  }
}

/* ------------------------------------------------------------------------------------------------------------------ */
/* -------------------------------------------------- Funcion Led --------------------------------------------------- */
void VerificaComandos()
{
  if(CadenaRecibida == "E")
  {
    digitalWrite(LED, HIGH);
  }

  else if(CadenaRecibida == "A")
  {
    digitalWrite(LED, LOW);
  }
}