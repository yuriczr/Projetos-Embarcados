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
const int pwmPin = 9; // Define o pino onde você deseja gerar o sinal PWM
const int magnet_switch = 8;     // Magnet switch

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


void setup() {
  pinMode(pwmPin, OUTPUT); // Configura o pino como saída
  pinMode(magnet_switch, INPUT_PULLUP);
  TCCR1B = TCCR1B & 0b11111000 | 0x01; // Define o prescaler para 1
  Serial.begin(9600);

  pinMode(iN3, OUTPUT);
  pinMode(iN4, OUTPUT);
  pinMode(enB, OUTPUT);
  //pinMode(sensormag1, INPUT_PULLUP);
  //pinMode(led1,OUTPUT);

}

void loop() {

  // Gere um sinal PWM variando o ciclo de trabalho (duty cycle)
  //for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
  //  analogWrite(pwmPin, dutyCycle); // Define o ciclo de trabalho (0-255)
  //  delay(10); // Aguarde um curto período de tempo para a transição
  //}
  // Inverta o ciclo de trabalho para diminuir a intensidade
  //for (int dutyCycle = 255; dutyCycle >= 0; dutyCycle--) {
  //  analogWrite(pwmPin, dutyCycle);
  //  delay(10);
  //}

  if (digitalRead(magnet_switch) == LOW) { 
    Serial.println("Switch Closed");
    analogWrite(pwmPin,255);
    //delay(1000);
    //analogWrite(pwmPin,0);
    //delay(1000);
  }
  else {
    Serial.println("Switch Opened");
    analogWrite(pwmPin,0);
  }

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