#include <Servo.h>

Servo servomotor; // Cria objeto para controlar o servo
int Abertura = 50;
int Fechamento = 0;
int UltimoEstado = 0;
int sevoPin = 7; // Especifica o pino usado para controlar o servo
int readPin = 8; // Variável para armazenar o valor lido do potenciometro

void setup(){
  pinMode(readPin, INPUT);
  Serial.begin(9600);
  servomotor.attach(servoPin); // Associa o pino 7 ao objeto servomotor
  servomotor.write(Fechamento); // Inicia servomotor na posição zero
}

void loop(){
  if (digitalRead(readPin) == HIGH && UltimoEstado == 0){
    servomotor.write(Abertura);
    UltimoEstado = 1;
    delay(100);
  }else if (digitalRead(readPin) == HIGH && UltimoEstado == 1){
    servomotor.write(Fechamento);
    UltimoEstado = 0;
    delay(100);
  }
  delay(500);
}