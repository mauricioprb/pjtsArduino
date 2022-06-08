// Declarar as saídas 11, 12, 13 como variáveis
int sinalVermelho = 13;
int sinalAmarelo = 12;
int sinalVerde = 11;

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
