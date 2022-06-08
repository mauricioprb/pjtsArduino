#include <Arduino.h>
#line 1 "/home/mauricio/Documentos/Repositorios/pjtsArduino/roboticaEducacionalUFN/piscarLed/piscarLed.ino"
int led = 13; // Define o pino 13 como led

#line 3 "/home/mauricio/Documentos/Repositorios/pjtsArduino/roboticaEducacionalUFN/piscarLed/piscarLed.ino"
void setup();
#line 7 "/home/mauricio/Documentos/Repositorios/pjtsArduino/roboticaEducacionalUFN/piscarLed/piscarLed.ino"
void loop();
#line 3 "/home/mauricio/Documentos/Repositorios/pjtsArduino/roboticaEducacionalUFN/piscarLed/piscarLed.ino"
void setup() { // Faz a inicialização dos pinos como entrada ou saída
  pinMode(led, OUTPUT); // Define o led como saída
}

void loop() { // Executará o programa em ciclo
  digitalWrite(led, HIGH); // Liga o led
  delay(1000); // Define um intervalo de 1 segundo
  digitalWrite(led, LOW); // Desliga o led
  delay(1000); // Define um intervalo de 1 segundo

  // Repete todo ciclo novamente
}
