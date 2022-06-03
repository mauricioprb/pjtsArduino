#include <Ultrasonic.h>

Ultrasonic sensor(6, 7);

int motorEsquerdoFrente = 13;
int motorEsquerdoTras = 12;

int motorDireitoTras = 11;
int motorDireitoFrente = 10;

int distancia;

void setup() {
	pinMode(motorEsquerdoFrente, OUTPUT);
    pinMode(motorEsquerdoTras, OUTPUT);
    pinMode(motorDireitoTras, OUTPUT);
    pinMode(motorDireitoFrente, OUTPUT);

    Serial.begin(9600);
    delay(3000);
}

void loop() {
    distancia = sensor.distanceRead();

    if(distancia < 20) {
        digitalWrite(motorEsquerdoFrente, LOW);
        digitalWrite(motorEsquerdoTras, HIGH);

        digitalWrite(motorDireitoFrente, LOW);
        digitalWrite(motorDireitoTras, HIGH);

        delay(500);

        digitalWrite(motorEsquerdoFrente, LOW);
        digitalWrite(motorEsquerdoTras, HIGH);

        digitalWrite(motorDireitoFrente, LOW);
        digitalWrite(motorDireitoTras, LOW);

        delay(200);
    }

    else {
        digitalWrite(motorEsquerdoFrente, HIGH);
        digitalWrite(motorEsquerdoTras, LOW);

        digitalWrite(motorDireitoFrente, HIGH);
        digitalWrite(motorDireitoTras, LOW);    
    }
}