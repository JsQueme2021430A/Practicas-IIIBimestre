/*
Centro educativo laboral Kinal
Perito en electronica
Quinto perito
Seccion A
Curso; Taller de electronica digital y reparacion de computadoras
Alumno; Jorge Diego Queme Andrino
Carne; 2021430
Proyecto; INTERRUPCIONES POR HARDWARE 
*/

#define btn_rising  2    
#define btn_falling 3   
#define ledA 4
#define ledB 5
#define ledC 6
#define ledD 7
#define leda 8
#define ledb 9
#define ledc 10
#define ledd 11
int UNIDAD=0;
int DECENA=0;


void funcion_ISR_falling(void);
void funcion_ISR_rising(void);


void setup() {
  CONFPINS();


  attachInterrupt(digitalPinToInterrupt(btn_rising),funcion_ISR_rising,RISING);   //Anclar la interrupción del pin 2 a una funcion de ISR, disparada por el flanco ascendente
  attachInterrupt(digitalPinToInterrupt(btn_falling),funcion_ISR_falling,FALLING); //Anclar la interrupción del pin 3 a una funcion de ISR, disparada por el flanco descendente
}

void loop() {
    CCONT();
    LED_UNIDADES();
    LED_DECENAS();

}


//Funciones de ISR
void funcion_ISR_rising(void)
{
  UNIDAD=UNIDAD+1;
}

void funcion_ISR_falling(void)
{
  UNIDAD=UNIDAD-1;
}   

void CONFPINS(void){
  pinMode(2, INPUT);
  pinMode(3, INPUT); 
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledC, OUTPUT);
  pinMode(ledD, OUTPUT);
  pinMode(leda, OUTPUT);
  pinMode(ledb, OUTPUT);
  pinMode(ledc, OUTPUT);
  pinMode(ledd, OUTPUT);
}

void CCONT(void)
{
    if(UNIDAD > 9) {
    UNIDAD = 0;
    DECENA = DECENA+1;
  }
  if((DECENA == 5) && (UNIDAD >0)) {
    DECENA = 0;
    UNIDAD = 0;
  }
  if((DECENA == 0) && (UNIDAD <0)) {
    DECENA = 5;
    UNIDAD = 0;
  }
  if(UNIDAD < 0) {
    UNIDAD = 9;
    DECENA = DECENA-1;
  }

}
void LED_UNIDADES (void) {
   switch(UNIDAD){
         
          case(0):
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
 
            break;
 
 
          case(1):
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
 
            break;
 
 
            case(2):
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  
            break;
 
 
            case(3):
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
 
            break;

            case(4):
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
            break;

            case(5):
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
            break;

            case(6):
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
            break;

            case(7):
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
            break;

            case(8):
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
            break;

            case(9):
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
           break;

}
}
void LED_DECENAS (void){
    switch (DECENA) {
           case (0):
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
               break;
           
           case(1):
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
 
            break;
 
 
            case(2):
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  
            break;
 
 
            case(3):
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
 
            break;

            case(4):
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
            break;

            case(5):
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
            break;
    }
}
  
