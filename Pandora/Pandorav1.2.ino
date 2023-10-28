//Código Caixa Misteriosa
// 0 - recebe liberação acesso; 1 - abre fechadura entrada; 2 - verificação de porta fechada aciona motor; 


//Pinos da Ponte H ligado as portas Digitais do Arduino
//PIN CONNECTIONS:

#define iN3 2
#define iN4 4
#define enB 3

int IN3 = 2;
int IN4 = 4;
int velocidade;
const int sensormag1 = 7;
const int led1 = 6;


void setup() {
    Serial.begin(9600);
 //Define os pinos como saida
 pinMode(iN3, OUTPUT);
 pinMode(iN4, OUTPUT);
 pinMode(enB, OUTPUT);
 //pinMode(sensormag1, INPUT_PULLUP);
 //pinMode(led1,OUTPUT);
}
void runMotorB()
{
  //START MOTOR B
  digitalWrite(enB, HIGH);
  digitalWrite(iN3, HIGH);
  digitalWrite(iN4, LOW);
}

void dontRunMotorB()
{
  //STOP MOTOR B
  digitalWrite(enB, LOW);
  digitalWrite(iN3, LOW);
  digitalWrite(iN4, LOW);
}

void reverseMotorB()
{
  //REVERSE MOTOR B
  digitalWrite(enB, HIGH);
  digitalWrite(iN3, LOW);
  digitalWrite(iN4, HIGH);
}

void runMotorB_PWM()
{
  //START MOTOR B PWM
  Serial.println(velocidade);
  digitalWrite(iN3, HIGH);
  digitalWrite(iN4, LOW);
  velocidade = analogRead(A0);
  velocidade = velocidade*0.2492668622; //We read thea analog value from the potentiometer calibrate it
  analogWrite(enB,velocidade);// Then inject it to our motor
  if (digitalRead(sensormag1) == HIGH){ //SE A LEITURA DO PINO FOR IGUAL A HIGH, FAZ
        digitalWrite(led1, HIGH); //ACENDE O LED
  }
  else{ //SENÃO, FAZ
      digitalWrite(sensormag1, LOW); //APAGA O LED
        }
}
void loop()
{
  Serial.println(velocidade);
  /*runMotorB();
  delay(10000);
  dontRunMotorB();
  delay(10000);
  reverseMotorB();
  delay(10000);*/
  runMotorB_PWM();
  delay(1000);

  
  
  
}


