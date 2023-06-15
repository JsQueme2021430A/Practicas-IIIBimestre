#define R 3 
#define G 5
#define B 6
#define POT A1


int I; 


void setup() {
  pinMode(R,OUTPUT); 
  pinMode(G,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(POT,INPUT);
  POTCONFIG();
}
void loop() {
  SECUENCE();



}

void SECUENCE () //Funcion para la secuencia.
{
  analogWrite(R,174);
  analogWrite(G,92);
  analogWrite(B,230);
  delay(I);

  analogWrite(R,255);
  analogWrite(G,255);
  analogWrite(B,255);
  delay(I);

  analogWrite(R,0);
  analogWrite(G,255);
  analogWrite(B,255);
  delay(I);

  analogWrite(R,189);
  analogWrite(G,174);
  analogWrite(B,20);
  delay(I);

  analogWrite(R,225);
  analogWrite(G,87);
  analogWrite(B,35);
  delay(I);
}

int POTCONFIG () //
{
  int READING=analogRead(POT);
  I=map(READING,0,1023,100,1000);
  return I;
}