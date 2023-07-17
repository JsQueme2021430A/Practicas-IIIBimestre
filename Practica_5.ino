/*
Centro educativo laboral Kinal
Perito en electronica
Quinto perito
Seccion A
Curso; Taller de electronica digital y reparacion de computadoras
Alumno; Jorge Diego Queme Andrino
Carne; 2021430
Proyecto; Sensor de gas y matriz led
*/
#include <LedControl.h>   //libreria que me permite usar el controlador led max7219
//Directivas de preprocesador
#define dataPin0   12   //pin 12 conectado al pin de datos del max7219.
#define dataClock0 11   //pin 11 conectado al pin de clock del max7219.
#define dataLoad0  10   //pin 10 conectado al pin de carga del max7219.
int adc, conver;
int i;
//Constructores
LedControl MmatrixLed = LedControl(dataPin0,dataClock0,dataLoad0,1);

/*
 * Variable:
 * Estas variables especifican que leds deben de encenderse en la matriz
 * de manera similar a como creabamos caracteres especiales en una lcd.
*/
byte copo_0[8]= {        
B10011001,
B01011010,
B00111100,
B11100111,
B11100111,
B00111100,
B01011010,
B10011001

};

byte fuego_1[8]= {       
B00010000,
B00001000,
B00001100,
B00011000,
B00110000,
B01111000,
B00111100,
B00011000

};

byte fuego_2[8]= {      
B00000100,
B00001000,
B00011000,
B00001100,
B00011000,
B00111100,
B00111100,
B00011000

};

byte fuego_3[8]= {       
B00001000,
B00010000,
B00001000,
B00011000,
B00111100,
B00111100,
B00111100,
B00011000

};
int display_number(unsigned char number);


void setup() {
  Serial.begin(9600); //Inicio la comunicacion serial a 9600 baudios.
  MmatrixLed.shutdown(0,false); //Activo el max7219 para poder mostrar los digitos.
  MmatrixLed.setIntensity(0,15);  //Brilo a la mitad 
  MmatrixLed.clearDisplay(0);    //limpio el display
  Serial.println("Detector de gas");
}

void loop() {
adc = analogRead(A0);
conver = map(adc, 0, 1024, 0, 100);

Serial.print("adc:");
Serial.print(adc);
Serial.print("    porcentaje:");
Serial.println(conver);
delay(100);
  
  for(int i =0; i<8;i++)
  {
    display_number(i);
  }
}
int display_number(unsigned char number){
 
    if(adc <= 250){
      for(int i=0; i<8;i++)
         MmatrixLed.setRow(0,i,copo_0[i]);
    }
    
    if(adc >= 251){
      for(int i=0; i<8;i++)
        MmatrixLed.setRow(0,i,fuego_1[i]);
    delay(200);
    for(int i=0; i<8;i++)
        MmatrixLed.setRow(0,i,fuego_2[i]);
    delay(200);
    for(int i=0; i<8;i++)
        MmatrixLed.setRow(0,i,fuego_3[i]);
    delay(200);
       }
    }
