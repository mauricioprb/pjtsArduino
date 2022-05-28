#include <Arduino.h>
#line 1 "e:\\Documentos\\Repositorios\\pjtsArduino\\roboticaEducacionalUFN\\roboSensorUltrassonico\\roboSensorUltrassonico.ino"
#include "Ultrasonic.h"

// Pinos Trigger - 9 - e Echo - 10
Ultrasonic sensorUltrassonico(9, 10);

long microSegundos = 0; // Armazenar o valor do tempo da reflexão do som refletido pelo objeto fornecido pela biblioteca do sensor
float distanciaCentimetros = 0; // Armazenar o valor da distância a ser convertido por uma função da própria bilbioteca do sensor

// Definir os pinos dos motores
#define motorEsquerdo1 4
#define motorEsquerdo2 5

#define motorDireito1 7
#define motorDireito2 8

// Definir os pinos para controle da velocidade
#define velocidadeMotorEsquerdo 3
#define velocidadeMotorDireito 6

// Escolha da velocidade dos motores
int valorEsquerdo = 180;
int valorDireito = 180;

#line 24 "e:\\Documentos\\Repositorios\\pjtsArduino\\roboticaEducacionalUFN\\roboSensorUltrassonico\\roboSensorUltrassonico.ino"
void setup();
#line 35 "e:\\Documentos\\Repositorios\\pjtsArduino\\roboticaEducacionalUFN\\roboSensorUltrassonico\\roboSensorUltrassonico.ino"
void loop();
#line 24 "e:\\Documentos\\Repositorios\\pjtsArduino\\roboticaEducacionalUFN\\roboSensorUltrassonico\\roboSensorUltrassonico.ino"
void setup() {
    // Definir os motores como saídas
    pinMode(motorDireito1, OUTPUT);
    pinMode(motorDireito2, OUTPUT);
    pinMode(motorEsquerdo1, OUTPUT);
    pinMode(motorEsquerdo2, OUTPUT);

    Serial.begin(115200); // Inicia a comunicação seria com velocidade de 115200 bits por segundo
    delay(3000); // Tempo de espera para inicialização (para dar tempo de por o robô no chão)
    }

    void loop() {
        // Convertendo a distância em CM e lendo o sensor
        distanciaCentimetros = sensorUltrassonico.convert(sensorUltrassonico.timing(), Ultrasonic::CM);
        
        Serial.print(distanciaCentimetros);
        Serial.println(" cm");

        if (distanciaCentimetros <= 40) { // Se a distância lida pelo sensor for menor ou igual que 40 centimetros
            //Velocidade motor lado esquerdo
            analogWrite(velocidadeMotorDireito, valorEsquerdo);

            //Velocidade motor lado direito
            analogWrite(velocidadeMotorEsquerdo, valorDireito);

            // Motor lado esquerdo para trás
            digitalWrite(motorDireito1, LOW);
            digitalWrite(motorDireito2, HIGH);

            // Motor lado direito para trás
            digitalWrite(motorEsquerdo1, LOW);
            digitalWrite(motorEsquerdo2, HIGH);
            delay(700); // Tempo que ficará indo para trás

            // Motor lado esquerdo para frente
            digitalWrite(motorDireito1, HIGH);
            digitalWrite(motorDireito2, LOW);

            // Motor lado direito para trás
            digitalWrite(motorEsquerdo1, LOW);
            digitalWrite(motorEsquerdo2, HIGH);

            delay(200);  // Tempo que ficará indo para o lado direito
        }

        else { // Se não, ou seja, se a distância for maior que 40 centimetros
            //Velocidade motor lado esquerdo
            analogWrite(velocidadeMotorDireito, valorEsquerdo);
        
            //Velocidade motor lado direito
            analogWrite(velocidadeMotorEsquerdo, valorDireito);
        
            // Motor lado esquerdo para frente
            digitalWrite(motorDireito1, HIGH);
            digitalWrite(motorDireito2, LOW);
        
            // Motor lado direito para frente
            digitalWrite(motorEsquerdo1, HIGH);
            digitalWrite(motorEsquerdo2, LOW);
        }
}
