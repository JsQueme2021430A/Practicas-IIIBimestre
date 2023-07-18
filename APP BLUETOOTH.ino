/*
Centro educativo laboral Kinal
Perito en electronica
Quinto perito
Seccion A
Curso; Taller de electronica digital y reparacion de computadoras
Alumno; Jorge Diego Queme Andrino
Carne; 2021430
Proyecto; Aplicacion Bluethoot 
*/
#include <Ticker.h>
#include <SoftwareSerial.h>
#include <OneWire.h>                
#include <DallasTemperature.h>
#define pin_1 A1
void isr_sensor(void); 
volatile static bool estado_sensor;
Ticker isr_accion_sensor(isr_sensor, 10000);
OneWire ourWire(2);
DallasTemperature sensors(&ourWire);
SoftwareSerial bt(8, 9); // RX, TX
#define dataPin A0
int led3= 3;
int estado=0;

void setup() {
 pinMode(pin_1,OUTPUT);
 delay(1000);
 Serial.begin(9600); 
 sensors.begin(); 
 bt.begin(9600); 
 Serial.println("Ready");
 pinMode(led3,OUTPUT);
 digitalWrite(pin_1,LOW);
 isr_accion_sensor.start();
 sensors.begin();
 estado_sensor = LOW;
}

void loop(){
isr_accion_sensor.update();
if(bt.available()>0)
{
  estado=bt.read();
  Serial.println(bt);
}
if(estado=='1')
{
  digitalWrite(led3,HIGH);
}
if(estado=='2')
{
  digitalWrite(led3,LOW);
}

}
void isr_sensor(void)
{
sensors.requestTemperatures();   //Se envía el comando para leer la temperatura
float tempC= sensors.getTempCByIndex(0); //Se obtiene la temperatura en ºC
float tempF= sensors.getTempFByIndex(0); //Se obtiene la temperatura en ºF
estado_sensor = digitalRead(pin_1); //leo el estado digital del pin que estoy usando como salida.
digitalWrite(pin_1, !estado_sensor);
bt.print(tempC); //send distance to MIT App
bt.println(";");
}
