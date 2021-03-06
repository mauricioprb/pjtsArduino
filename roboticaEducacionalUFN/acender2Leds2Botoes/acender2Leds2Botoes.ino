int led1 = 13; // LED 1 no pino 13
int led2 = 12; // LED 2 no pino 12
int botao1 = 3; // Botão no pino 3
int botao2 = 2; // Botão no pino 2
int estadoBotao1; // Variável para ler quando o botão 1 é apertado
int estadoBotao2; // Variável para ler quando o botão 2 é apertado

void setup(){
    pinMode(led1, OUTPUT); // Pino do LED 1 definido como saída
    pinMode(led2, OUTPUT); // Pino do LED 2 definido como saída
    pinMode(botao1, INPUT); // Pino do botão 1 definido como entrada
    pinMode(botao1, INPUT); // Pino do botão 2 definido como entrada
}

void loop(){
    /*
    Novo estado do botão vai ser igual ao que o arduino ler no pino
    onde está o botão. Poderá ser ALTO (HIGH), se o botão estiver
    pressionado ou BAIXO (LOW), se o botão estiver solto
    */
    estadoBotao1 = digitalRead(botao1);
    estadoBotao2 = digitalRead(botao2);
    
    if(estadoBotao1 == HIGH) { // Se o botão 1 estiver pressionado
        digitalWrite(led1, HIGH); // Acender LED 1
        delay(500);
    }
    else { // Se não estiver pressionado
        digitalWrite(led1, LOW); // Apaga LED 1
    }

    if(estadoBotao2 == HIGH) { // Se o botão 2 estiver pressionado
        digitalWrite(led2, HIGH); // Acender LED 2
        delay(500);
    }
    else { // Se não estiver pressionado
        digitalWrite(led2, LOW); // Apaga LED 2
    }
}