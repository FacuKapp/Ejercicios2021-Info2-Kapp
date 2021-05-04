#include <Arduino.h>

struct Sensores
{
  char TipoSensor;
  int ValorSensor;
  long TiempoTrans;
} StVar;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  Serial.println("---------------------------------------------------------------------");
  Serial.println("EL TAMANIO DE MEMORIA UTILIZADO ES: ");
  Serial.print("Estructura StVar: ");
  Serial.print(sizeof(StVar));
  Serial.println(" Bytes");
  Serial.print("Miembro StVar.TipoSensor:");
  Serial.print(sizeof(StVar.TipoSensor));
  Serial.println(" Bytes");
  Serial.print("Miembro StVar.ValorSensor:");
  Serial.print(sizeof(StVar.ValorSensor));
  Serial.println(" Bytes");
  Serial.print("Miembro StVar.TiempoTrans:");
  Serial.print(sizeof(StVar.TiempoTrans));
  Serial.println(" Bytes");
  Serial.print("---------------------------------------------------------------------\n");
}

void loop() {
  // put your main code here, to run repeatedly:

}