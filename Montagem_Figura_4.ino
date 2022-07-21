#include <Servo.h>

Servo servomotor; // Cria objeto para controlar o servo
int potPin = 0; // Especifica em qual pino o sinal do potenciometro está ligado
int readAnalog = 0; // Variável para armazenar o valor lido do potenciometro

void setup(){
  Serial.begin(9600);
  servomotor.attach(servoPin); // Associa o pino 7 ao objeto servomotor
  servomotor.write(0); // Inicia servomotor na posição zero
}

void loop(){
  // Lê o valor do potenciometro. Esse valor está entre 0 e 1023
  readAnalog = analogRead(potPin);
  Serial.println(readAnalog);

  // Traduz a escala de 0-1023 para uma escala de 0-179, usado pelo servo
  readAnalog = map(readAnalog, 0, 1023, 0, 179);

  // Seta o sinal de controle de acordo com o potenciometro
  servomotor.write(readAnalog);
  delay(500);
}