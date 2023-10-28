#include <Stepper.h> //biblioteca para controle de motor de passo

//definiçao dos pinos ligados a ponte H
#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11

//definindo pino do endstop
const int endstopL = 4;
const int endstopR = 7; 

//potenciometro
const int POT = A0;
const int POTV = A1;

//variavel auxiliar
int LA1;
int LA2;
int Au1;
int Au2;
int valor_mapeado;
int valor_mapeado2;


const int stepsPerRevolution = 100;  // change this to fit the number of steps per revolution

Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

void setup()
{
  // initialize the serial port:
  Serial.begin(9600);
  
  //potenciometro com entrada da dados
  pinMode(POT, INPUT);
  pinMode(POTV, INPUT);
   
  //declara o sensor de fim de curso como entrada
  pinMode(endstopL, INPUT);
  pinMode(endstopR, INPUT);
}
void loop() {
  
  Au1 = 0;
  while( digitalRead(endstopR) == 1 && digitalRead(endstopL) == 1 ){
  valor_mapeado = map(analogRead(POTV),0,1024,5,60);
  Serial.println(valor_mapeado);
  Serial.println("horario");
  myStepper.setSpeed(valor_mapeado);
  myStepper.step(stepsPerRevolution);
  valor_mapeado2 = map(analogRead(POT),0,1024,0,25000);
  Serial.println(valor_mapeado2);
  delay(valor_mapeado2);  
  }
  LA1 = digitalRead(endstopL);
  while(digitalRead(endstopR) == 1 && Au1 == LA1 ){
  valor_mapeado = map(analogRead(POTV),0,1024,5,60);
  Serial.println(valor_mapeado);
  Serial.println("antihorario");
  myStepper.setSpeed(valor_mapeado);
  myStepper.step(-stepsPerRevolution);
  valor_mapeado2 = map(analogRead(POT),0,1024,0,25000);
  Serial.println(valor_mapeado2);
  delay(valor_mapeado2);
  
  }
  LA2 = digitalRead(endstopR);
  while(digitalRead(endstopL) == 1 && Au1 == LA2 ){
  valor_mapeado = map(analogRead(POTV),0,1024,5,60);
  Serial.println(valor_mapeado);
  Serial.println("horario");
  myStepper.setSpeed(valor_mapeado);
  myStepper.step(stepsPerRevolution);
  valor_mapeado2 = map(analogRead(POT),0,1024,0,25000);
  Serial.println(valor_mapeado2);
  delay(valor_mapeado2);
  }
  
  }
