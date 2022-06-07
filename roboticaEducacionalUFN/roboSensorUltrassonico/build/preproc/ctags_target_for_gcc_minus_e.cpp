# 1 "e:\\Documentos\\Repositorios\\pjtsArduino\\roboticaEducacionalUFN\\roboSensorUltrassonico\\roboSensorUltrassonico.ino"
# 2 "e:\\Documentos\\Repositorios\\pjtsArduino\\roboticaEducacionalUFN\\roboSensorUltrassonico\\roboSensorUltrassonico.ino" 2

// Pinos Trigger - 9 - e Echo - 10
Ultrasonic sensorUltrassonico(9, 10);

long microSegundos = 0; // Armazenar o valor do tempo da reflexão do som refletido pelo objeto fornecido pela biblioteca do sensor
float distanciaCentimetros = 0; // Armazenar o valor da distância a ser convertido por uma função da própria bilbioteca do sensor

// Definir os pinos dos motores
int motorEsquerdo1 = 4;
int motorEsquerdo2 = 5;

int motorDireito1 = 7;
int motorDireito2 = 8;

// Definir os pinos para controle da velocidade
int velocidadeMotorEsquerdo = 3;
int velocidadeMotorDireito = 6;

// Escolha da velocidade dos motores
int valorEsquerdo = 180;
int valorDireito = 180;

void setup() {
    // Definir os motores como saídas
    pinMode(motorDireito1, 0x1);
    pinMode(motorDireito2, 0x1);
    pinMode(motorEsquerdo1, 0x1);
    pinMode(motorEsquerdo2, 0x1);

    Serial.begin(115200); // Inicia a comunicação seria com velocidade de 115200 bits por segundo
    delay(3000); // Tempo de espera para inicialização (para dar tempo de por o robô no chão)
    }

    void loop() {
        // Convertendo a distância em CM e lendo o sensor
        distanciaCentimetros = sensorUltrassonico.convert(sensorUltrassonico.timing(), Ultrasonic::28);

        Serial.print(distanciaCentimetros);
        Serial.println(" cm");

        if (distanciaCentimetros <= 40) { // Se a distância lida pelo sensor for menor ou igual que 40 centimetros
            //Velocidade motor lado esquerdo
            analogWrite(velocidadeMotorDireito, valorEsquerdo);

            //Velocidade motor lado direito
            analogWrite(velocidadeMotorEsquerdo, valorDireito);

            // Motor lado esquerdo para trás
            digitalWrite(motorDireito1, 0x0);
            digitalWrite(motorDireito2, 0x1);

            // Motor lado direito para trás
            digitalWrite(motorEsquerdo1, 0x0);
            digitalWrite(motorEsquerdo2, 0x1);
            delay(700); // Tempo que ficará indo para trás

            // Motor lado esquerdo para frente
            digitalWrite(motorDireito1, 0x1);
            digitalWrite(motorDireito2, 0x0);

            // Motor lado direito para trás
            digitalWrite(motorEsquerdo1, 0x0);
            digitalWrite(motorEsquerdo2, 0x1);

            delay(200); // Tempo que ficará indo para o lado direito
        }

        else { // Se não, ou seja, se a distância for maior que 40 centimetros
            //Velocidade motor lado esquerdo
            analogWrite(velocidadeMotorDireito, valorEsquerdo);

            //Velocidade motor lado direito
            analogWrite(velocidadeMotorEsquerdo, valorDireito);

            // Motor lado esquerdo para frente
            digitalWrite(motorDireito1, 0x1);
            digitalWrite(motorDireito2, 0x0);

            // Motor lado direito para frente
            digitalWrite(motorEsquerdo1, 0x1);
            digitalWrite(motorEsquerdo2, 0x0);
        }
}
