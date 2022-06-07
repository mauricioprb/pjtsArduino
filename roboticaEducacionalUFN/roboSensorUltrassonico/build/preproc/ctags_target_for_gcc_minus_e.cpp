# 1 "e:\\Documentos\\Repositorios\\pjtsArduino\\roboticaEducacionalUFN\\roboSensorUltrassonico\\roboSensorUltrassonico.ino"
# 2 "e:\\Documentos\\Repositorios\\pjtsArduino\\roboticaEducacionalUFN\\roboSensorUltrassonico\\roboSensorUltrassonico.ino" 2

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
 pinMode(motorEsquerdoFrente, 0x1);
    pinMode(motorEsquerdoTras, 0x1);
    pinMode(motorDireitoTras, 0x1);
    pinMode(motorDireitoFrente, 0x1);

    // Delay para dar tempo de colocar o robô no chão
    delay(3000);
}

void loop() {
    // Variável para ler a que distância está o sensor no momento;
    distancia = sensor.read();

    // Se distância menor que 20cm 
    if(distancia < 20) {
        // Comandos para dar ré
        digitalWrite(motorEsquerdoFrente, 0x0); // Desliga a rotação do motor esquerdo para frente
        digitalWrite(motorEsquerdoTras, 0x1); // Liga a rotação traseira do motor esquerdo

        digitalWrite(motorDireitoFrente, 0x0); // Desliga a rotação do motor direito para frente
        digitalWrite(motorDireitoTras, 0x1); // Liga a rotação traseira do motor direito

        // Robô da ré durante 0.5s
        delay(500);

        // Motor irá dar ré para a esquerda
        digitalWrite(motorEsquerdoFrente, 0x0);
        digitalWrite(motorEsquerdoTras, 0x1);

        digitalWrite(motorDireitoFrente, 0x0);
        digitalWrite(motorDireitoTras, 0x0);

        // Faz a ação durante 0.2s
        delay(200);
    }

    // Se a distância for superior a 20cm executará os comandos abaixo
    else {
        // Ligar os motores para frente equanto a distância não for inferior a 20cm
        digitalWrite(motorEsquerdoFrente, 0x1);
        digitalWrite(motorEsquerdoTras, 0x0);

        digitalWrite(motorDireitoFrente, 0x1);
        digitalWrite(motorDireitoTras, 0x0);
    }
}
