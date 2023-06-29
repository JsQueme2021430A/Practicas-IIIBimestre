/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Electronica
 * Grado: Quinto
 * Sección: A
 * Curso: Taller de electronica digital y reparación de computadoras I
 * Nombre:Pablo David Hernandez Ajiataz
 * Carnet: 2022472
 * Proyecto: Clasificadora de colores - Bimestre III
*/
#include <Servo.h>
#define SEN  2
#define ch_LDR A0
#define led_Azul  4   //led azul conec1ado al pin 3
#define led_Verde 5   //led verde conec1ado al pin 4
#define led_Rojo  6
int resultado_azul, resultado_rojo, resultado_verde;
int resultado;
Servo servo;
void setup() {

  pinMode(SEN, INPUT);
  pinMode(A0, INPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);



  servo.attach(3);
  pinMode(ch_LDR, INPUT); 
  pinMode(led_Azul, OUTPUT); 
  pinMode(led_Verde, OUTPUT);
  pinMode(led_Rojo, OUTPUT);  
  
  digitalWrite(led_Azul, LOW);
  digitalWrite(led_Verde, LOW);
  digitalWrite(led_Rojo, LOW);
  Serial.begin(9600);

}

void loop() {
  bool SEN_LEER = digitalRead(SEN);
  if (SEN_LEER == HIGH) {
    servo.write(0);
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    delay(1);

    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    delay(1);

    digitalWrite(7, LOW); //3
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    delay(1);

    digitalWrite(7, LOW); //4
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW );
    delay(1);

    digitalWrite(7, LOW); //5
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
    delay(1);

    digitalWrite(7, LOW); //6
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    delay(1);

    digitalWrite(7, LOW); //7
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
    delay(1);

    digitalWrite(7, HIGH); //8
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
    delay(1);


  }
  if (SEN_LEER == LOW) {

    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    delay(2500);
    LUM();
    caminar();

  }
}

void LUM() {
  digitalWrite(led_Rojo, HIGH);

  delay(150);

 
  resultado = analogRead(ch_LDR);
  resultado_rojo = map(resultado, 0, 1023, 0, 1023);
  Serial.print("R, G, B, = ");
  Serial.println(resultado_rojo);
  digitalWrite(led_Rojo, LOW);
  delay(150);

  
  digitalWrite(led_Verde, HIGH);

  delay(150);

 
  resultado = analogRead(ch_LDR);
  resultado_verde = map(resultado, 0, 1023, 0, 1023); 
 
  Serial.print("R, G, B, = ");
  Serial.println(resultado_verde);
  digitalWrite(led_Verde, LOW);
  delay(150);

  
  digitalWrite(led_Azul, HIGH);
 
  delay(150);

 
  resultado = analogRead(ch_LDR);
  resultado_azul = map(resultado, 0, 1023, 0, 1023); //lo linealizo
 
  Serial.print("R, G, B, = ");
  Serial.println(resultado_azul);
  digitalWrite(led_Azul, LOW);
  delay(150);


  if((resultado_verde<=123 && resultado_verde>=118)&&(resultado_azul<=190 && resultado_azul>=187) ){
    servo.write(90);
    delay(100);
    servo.write(0);
  }
 
}

void caminar() {
  int T = 1;
  int pos = 0;
  for (pos = 0; pos <= 300; pos += 1) { // goes from 0 degrees 1o 180 degrees
    digitalWrite(7, HIGH); //1
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    delay(T);

    digitalWrite(7, HIGH); //T
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    delay(T);

    digitalWrite(7, LOW); //3
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    delay(T);

    digitalWrite(7, LOW); //4
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW );
    delay(T);

    digitalWrite(7, LOW); //5
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
    delay(T);

    digitalWrite(7, LOW); //6
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    delay(T);

    digitalWrite(7, LOW); //7
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
    delay(T);

    digitalWrite(7, HIGH); //8
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
    delay(T);                       // waits 15 ms for the servo to reach the position
  }
  for (pos = 300; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    digitalWrite(7, HIGH); //1
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    delay(T);

    digitalWrite(7, HIGH); //T
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    delay(T);

    digitalWrite(7, LOW); //3
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    delay(T);

    digitalWrite(7, LOW); //4
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW );
    delay(T);

    digitalWrite(7, LOW); //5
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
    delay(T);

    digitalWrite(7, LOW); //6
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    delay(T);

    digitalWrite(7, LOW); //7
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
    delay(T);

    digitalWrite(7, HIGH); //8
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
    delay(T);                     // waits 15 ms for the servo to reach the position
  }

}
