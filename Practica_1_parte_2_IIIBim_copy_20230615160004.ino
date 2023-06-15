/*
Centro educativo laboral Kinal
Perito en electronica
Quinto perito
Seccion A
Curso; Taller de electronica digital y reparacion de computadoras
Alumno; Jorge Diego Queme Andrino
Carne; 2021430
Proyecto; INTERRUPCIONES POR MEDIO DE SOFTWARE 
*/

#include <Ticker.h> 
#include <OneWire.h>                
#include <DallasTemperature.h>


#define BT 3 

void TEMP(void); 
void BTN(void);

OneWire ourWire(2); 
DallasTemperature TempSens(&ourWire); 

Ticker TempState(TEMP,300); 
Ticker BtnState(BTN,600); 

volatile static bool BTNSTATE; 



void setup() {
  Serial.begin(9600);
  TempSens.begin();
  TempState.start();
  BtnState.start();
}
void loop() {
  TempState.update();
  BtnState.update();

}

void BTN(void)
{
  BTNSTATE = digitalRead(BT);
  if (BTNSTATE == HIGH) {
    Serial.println("Boton Presionado");
  }
  else if (BTNSTATE == LOW) {
    Serial.println("No Se Ha Presionado El Boton");
  }
   
  }
void TEMP(void)
{
    TempSens.requestTemperatures();
  int GRADOS = TempSens.getTempCByIndex(0);
  if (GRADOS  >> 10 && GRADOS << 100) {
    Serial.print("Grados centigrados  ");
    Serial.println(GRADOS);
  }
}
