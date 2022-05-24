int led = 13; // LED no pino 13
int botao = 2; // Botão no pino 2
int estadoBotao; // Variável para ler quando o botão é apertado

void setup(){
  pinMode(led, OUTPUT); // Pino do LED definido como saída
  pinMode(botao, INPUT); // Pino do botão definido como entrada
}

void loop(){
  /*
   Novo estado do botão vai ser igual ao que o arduino ler no pino
   onde está o botão. Poderá ser ALTO (HIGH), se o botão estiver
   pressionado ou BAIXO (LOW), se o botão estiver solto
   */
  estadoBotao = digitalRead(botao);

  if(estadoBotao == HIGH) { // Se o botão estiver pressionado
    digitalWrite(led, HIGH); // Acender LED
    delay(500);
  }
  else { // Se não estiver pressionado
    digitalWrite(led, LOW); // Apaga LED
  }
}
