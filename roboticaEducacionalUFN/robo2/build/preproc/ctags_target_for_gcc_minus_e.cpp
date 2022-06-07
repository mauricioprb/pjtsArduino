# 1 "e:\\Documentos\\Repositorios\\pjtsArduino\\roboticaEducacionalUFN\\robo2\\roboSensorUltrassonico.ino"
# 2 "e:\\Documentos\\Repositorios\\pjtsArduino\\roboticaEducacionalUFN\\robo2\\roboSensorUltrassonico.ino" 2

Ultrasonic sensor(6, 7);

int motorEsquerdoFrente = 13;
int motorEsquerdoTras = 12;

int motorDireitoTras = 11;
int motorDireitoFrente = 10;

int distancia = 0;

void setup() {
 pinMode(motorEsquerdoFrente, 0x1);
    pinMode(motorEsquerdoTras, 0x1);
    pinMode(motorDireitoTras, 0x1);
    pinMode(motorDireitoFrente, 0x1);

    Serial.begin(9600);
    delay(3000);
}

void loop() {
    distancia = sensor.read();

    if(distancia < 20) {
        digitalWrite(motorEsquerdoFrente, 0x0);
        digitalWrite(motorEsquerdoTras, 0x1);

        digitalWrite(motorDireitoFrente, 0x0);
        digitalWrite(motorDireitoTras, 0x1);

        delay(500);

        digitalWrite(motorEsquerdoFrente, 0x0);
        digitalWrite(motorEsquerdoTras, 0x1);

        digitalWrite(motorDireitoFrente, 0x0);
        digitalWrite(motorDireitoTras, 0x0);

        delay(200);
    }

    else {
        digitalWrite(motorEsquerdoFrente, 0x1);
        digitalWrite(motorEsquerdoTras, 0x0);

        digitalWrite(motorDireitoFrente, 0x1);
        digitalWrite(motorDireitoTras, 0x0);
    }
}
