/*
Centro educativo laboral Kinal
Perito en electronica
Quinto perito
Seccion A
Curso; Taller de electronica digital y reparacion de computadoras
Alumno; Jorge Diego Queme Andrino
Carne; 2021430
Proyecto; CONTROL DE BRILLO DE UN LED
*/
#define POT A0
#define led 2
unsigned int raw_potenciometro = 0;
unsigned int intencidad = 0;


void setup() {
  pinMode(led, OUTPUT);
  pinMode(POT, INPUT);
}

void loop() {

raw_potenciometro = analogRead(POT); //leo el canal analogico A0
  intencidad = map(raw_potenciometro, 0, 1023, 0, 255);
  analogWrite(led, intencidad);
  delay(2000);


}
