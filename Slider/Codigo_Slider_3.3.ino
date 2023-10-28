// Inclusao biblioteca Stepper do Arduino
#include <Stepper.h>

// Numero de passos de saida por revolucao 
const int stepsPerRevolution = 100;

// Criacao instance biblioteca Stepper
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

//definiçao dos pinos ligados a ponte H
#define INPUT_1 8
#define INPUT_2 9
#define INPUT_3 10
#define INPUT_4 11

// Sinal Sensor Fim de Curso
const int endstop_1 = 4;
const int endstop_2 = 7; 
const int rpm = 30;
// variaveis auxiliares

int inicioMeioOuVolta = 1; // horario


void setup()
{
 // Definição dos endstop como entrada
  pinMode(endstop_1,INPUT_PULLUP);
  pinMode(endstop_2,INPUT_PULLUP);
  
 // Definição dos pinos do motor como saida
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);

  // set a velocidade a 30 rpm
  myStepper.setSpeed(30);
  // step one revolution in the other direction:
  Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
  delay(10); //milliseconds
}

void loop() 
{
  if (digitalRead(endstop_2) == HIGH){
    // set a velocidade a 30 rpm
    myStepper.setSpeed(30);
    // step one revolution in one direction:
    Serial.println("counterclockwise");
    myStepper.step(-stepsPerRevolution);
    delay(10);  
  }
  else if(digitalRead(endstop_1) == HIGH){
    // set a velocidade a 10 rpm
    myStepper.setSpeed(10);
    // step one revolution in the other direction:
    Serial.println("clockwise");
    myStepper.step(stepsPerRevolution);
    delay(10); //milliseconds
  }

}



