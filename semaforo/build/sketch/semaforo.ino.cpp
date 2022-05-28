#include <Arduino.h>
#line 1 "e:\\Documentos\\Repositorios\\pjtsArduino\\semaforo\\semaforo.ino"
// Declarar as saídas 11, 12, 13 como variáveis
int sinalVermelho = 13;
int sinalAmarelo = 12;
int sinalVerde = 11;

#line 6 "e:\\Documentos\\Repositorios\\pjtsArduino\\semaforo\\semaforo.ino"
void setup();
#line 13 "e:\\Documentos\\Repositorios\\pjtsArduino\\semaforo\\semaforo.ino"
void loop();
#line 6 "e:\\Documentos\\Repositorios\\pjtsArduino\\semaforo\\semaforo.ino"
void setup(){
  // Declarar os pinos como saídas
  pinMode(sinalVermelho, OUTPUT);
  pinMode(sinalAmarelo, OUTPUT);
  pinMode(sinalVerde, OUTPUT);
}

void loop(){
  // Led vermelho
  digitalWrite(sinalVermelho, HIGH);
  delay(4000);
  digitalWrite(sinalVermelho, LOW);

  // Led verde
  digitalWrite(sinalVerde, HIGH);
  delay(4000);
  digitalWrite(sinalVerde, LOW);

  // Led amarelo
  digitalWrite(sinalAmarelo, HIGH);
  delay(2000);
  digitalWrite(sinalAmarelo, LOW);
}

