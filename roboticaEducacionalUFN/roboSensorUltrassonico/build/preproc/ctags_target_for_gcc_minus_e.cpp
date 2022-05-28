# 1 "e:\\Documentos\\Repositorios\\pjtsArduino\\roboSensorUltrassonico\\roboSensorUltrassonico.ino"
# 2 "e:\\Documentos\\Repositorios\\pjtsArduino\\roboSensorUltrassonico\\roboSensorUltrassonico.ino" 2

// Pinos Trigger - 9 - e Echo - 10
Ultrasonic sensorUltrassonico(9, 10);

long microSegundos = 0; // Armazenar o valor do tempo da reflexão do som refletido pelo objeto fornecido pela biblioteca do sensor
float distanciaCentimetros = 0; // Armazenar o valor da distância a ser convertido por uma função da própria bilbioteca do sensor

// Definir os pinos dos motores






// Definir os pinos para controle da velocidade



// Escolha da velocidade dos motores
int valorEsquerdo = 180;
int valorDireito = 180;


void setup() {
    // Definir os motores como saídas
    pinMode(7, 0x1);
    pinMode(8, 0x1);
    pinMode(4, 0x1);
    pinMode(5, 0x1);

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
            analogWrite(6, valorEsquerdo);

            //Velocidade motor lado direito
            analogWrite(3, valorDireito);

            // Motor lado esquerdo para trás
            digitalWrite(7, 0x0);
            digitalWrite(8, 0x1);

            // Motor lado direito para trás
            digitalWrite(4, 0x0);
            digitalWrite(5, 0x1);
            delay(700); // Tempo que ficará indo para trás

            // Motor lado esquerdo para frente
            digitalWrite(7, 0x1);
            digitalWrite(8, 0x0);

            // Motor lado direito para trás
            digitalWrite(4, 0x0);
            digitalWrite(5, 0x1);

            delay(200); // Tempo que ficará indo para o lado direito
        }

        else { // Se não, ou seja, se a distância for maior que 40 centimetros
            //Velocidade motor lado esquerdo
            analogWrite(6, valorEsquerdo);

            //Velocidade motor lado direito
            analogWrite(3, valorDireito);

            // Motor lado esquerdo para frente
            digitalWrite(7, 0x1);
            digitalWrite(8, 0x0);

            // Motor lado direito para frente
            digitalWrite(4, 0x1);
            digitalWrite(5, 0x0);
        }
}
