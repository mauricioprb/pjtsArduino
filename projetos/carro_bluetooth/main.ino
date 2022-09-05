#include <SoftwareSerial.h>
#include <Servo.h>
#include "libraries/controles.h"

SoftwareSerial bth(11,12);

Motor *frente;
Motor *re;
Direcao *direcao;
Controles *controles;

void setup() {
    frente = new Motor(2);
    re = new Motor(3);
    direcao = new Direcao(9);

    pinMode(frente->porta(), OUTPUT);
    pinMode(re->porta(), OUTPUT);

    direcao->porta();
    direcao->centro();

    bth.begin(9600); 
}

void loop() {
    if (bth.available()) {
        Serial.write(bth.read());
        controles->controles(bth.read());
    }
}
