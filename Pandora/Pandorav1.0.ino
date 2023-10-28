//Código Caixa Misteriosa
// 0 - recebe liberação acesso; 1 - abre fechadura entrada; 2 - verificação de porta fechada aciona motor; 


//Pinos da Ponte H ligado as portas Digitais do Arduino
int IN1 = 2;
int IN2 = 4;
int IN3 = 7;
int IN4 = 8;


void setup() {
 //Define os pinos como saida
 pinMode(IN1, OUTPUT);
 pinMode(IN2, OUTPUT);
 pinMode(IN3, OUTPUT);
 pinMode(IN4, OUTPUT);

}

void loop() {

 
 //Gira o Motor A no sentido horario
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, HIGH);
 delay(2000);
 //Gira o Motor A no sentido anti-horario
 digitalWrite(IN1, HIGH);
 digitalWrite(IN2, HIGH);
 delay(2000);
 //Para o motor A
 digitalWrite(IN1, HIGH);
 digitalWrite(IN2, HIGH);
 delay(500);

  //Para o motor B
 //digitalWrite(IN3, HIGH);
 //digitalWrite(IN4, HIGH);
 //delay(500);
 //Para o motor B
 //digitalWrite(IN3, LOW);
 //digitalWrite(IN4, HIGH);
 //delay(500);

}
