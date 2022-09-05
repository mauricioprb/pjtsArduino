#include <SoftwareSerial.h>
#include <Servo.h>
#include "libraries/controles.h"

SoftwareSerial bth(11,12);

// Instanciar objetos das classes
Motor *frente;
Motor *re;
Direcao *direcao;
Controles *controles;

void setup() {
    // Criar objetos com os pinos correspondentes
    re = new Motor(3);
    frente = new Motor(2);
    direcao = new Direcao(9);

    // Definir as portas dos motores como saída
    pinMode(frente->porta(), OUTPUT);
    pinMode(re->porta(), OUTPUT);

    direcao->porta(); // Define porta para o servo
    direcao->centro(); // Inicia o programa com o servo centralizado

    bth.begin(9600); // BAUD do bluetooth
}

void loop() {
    if (bth.available()) { // Se o bluetooth estiver disponível
        Serial.write(bth.read()); // Defindo leitura do bluetooth com as letras que o app envia
        controles->Controles(bth.read()); // Acessa a classe com o caratere que o bluetooth envia
    }
}
