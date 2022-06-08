#include <Ultrasonic.h>

// Declarar os pinos TRIGGER E ECHO
int TRIGGER = 6;
int ECHO = 7;

// Definindo uma função para os pinos
Ultrasonic sensor(TRIGGER, ECHO);

// Declarando variáveis para os pinos dos motores
int motorEsquerdoFrente = 13;
int motorEsquerdoTras = 12;

int motorDireitoTras = 11;
int motorDireitoFrente = 10;

// Variável para medir a distância (começando em zero)
int distancia = 0;

void setup() {
    // Definindo todos os motores como saídas
	pinMode(motorEsquerdoFrente, OUTPUT);
    pinMode(motorEsquerdoTras, OUTPUT);
    pinMode(motorDireitoTras, OUTPUT);
    pinMode(motorDireitoFrente, OUTPUT);

    Serial.begin(9600);

    // Delay para dar tempo de colocar o robô no chão
    delay(3000);
}

void loop() {
    // Variável para ler a que distância está o sensor no momento;
    distancia = sensor.read();

    // Se distância menor que 20cm 
    if(distancia < 20) {
        // Comandos para dar ré
        digitalWrite(motorEsquerdoFrente, LOW); // Desliga a rotação do motor esquerdo para frente
        digitalWrite(motorEsquerdoTras, HIGH); // Liga a rotação traseira do motor esquerdo

        digitalWrite(motorDireitoFrente, LOW); // Desliga a rotação do motor direito para frente
        digitalWrite(motorDireitoTras, HIGH); // Liga a rotação traseira do motor direito

        // Robô da ré durante 0.5s
        delay(500);

        // Motor irá dar ré para a esquerda
        digitalWrite(motorEsquerdoFrente, LOW); 
        digitalWrite(motorEsquerdoTras, HIGH);

        digitalWrite(motorDireitoFrente, LOW);
        digitalWrite(motorDireitoTras, LOW);

        // Faz a ação durante 0.2s
        delay(200);
    }

    // Se a distância for superior a 20cm executará os comandos abaixo
    else {
        // Ligar os motores para frente equanto a distância não for inferior a 20cm
        digitalWrite(motorEsquerdoFrente, HIGH);
        digitalWrite(motorEsquerdoTras, LOW);

        digitalWrite(motorDireitoFrente, HIGH);
        digitalWrite(motorDireitoTras, LOW);    
    }
}