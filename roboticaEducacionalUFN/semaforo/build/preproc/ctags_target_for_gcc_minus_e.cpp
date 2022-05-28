# 1 "e:\\Documentos\\Repositorios\\pjtsArduino\\semaforo\\semaforo.ino"
// Declarar as saídas 11, 12, 13 como variáveis
int sinalVermelho = 13;
int sinalAmarelo = 12;
int sinalVerde = 11;

void setup(){
  // Declarar os pinos como saídas
  pinMode(sinalVermelho, 0x1);
  pinMode(sinalAmarelo, 0x1);
  pinMode(sinalVerde, 0x1);
}

void loop(){
  // Led vermelho
  digitalWrite(sinalVermelho, 0x1);
  delay(4000);
  digitalWrite(sinalVermelho, 0x0);

  // Led verde
  digitalWrite(sinalVerde, 0x1);
  delay(4000);
  digitalWrite(sinalVerde, 0x0);

  // Led amarelo
  digitalWrite(sinalAmarelo, 0x1);
  delay(2000);
  digitalWrite(sinalAmarelo, 0x0);
}
