
/*
 * Ligação do módulo bluetooth:
 *    RXD -> Pino 12
 *    TXD -> Pino 11
 *    GND -> GND
 *    VCC -> 5V
 *    
 * Ligação Carro:
 *    Frente    -> Pino 4
 *    Ré        -> Pino 5
 *    Esquerda  -> Pino 6
 *    Direita   -> Pino 7
 *    
 * Controle:
 *    Aplicativo: Bluetooth RC Controller
 *    
 * Módulo bluetooth:
 *    PIN:  1234
 *    Baud: 115200
 */
#include <SoftwareSerial.h>
SoftwareSerial bth(11,12);

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  
  Serial.begin(9600);
  bth.begin(9600); 
  Serial.println("Pronto"); 
} 
    
void loop() {
  if (bth.available()) {
    char comando = bth.read();
    Serial.write(comando);

    switch(comando) {
      case 'S':// stop
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
        break;
        
      case 'F':// frente
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, HIGH);
        break;
         
      case 'B'://Ré
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, HIGH);
        digitalWrite(5, LOW);
        break;
        
      case 'L': // Esquerda
        digitalWrite(2, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
        break;
        
      case 'R': // Direita
        digitalWrite(2, LOW);
        digitalWrite(3, HIGH);
        digitalWrite(4,LOW );
        digitalWrite(5, LOW);
        break;

        case 'I':// frente e direita
        digitalWrite(2, LOW);
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
        digitalWrite(5, HIGH);
        break;

        case 'G':// frente e esquerda
        digitalWrite(2, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, HIGH);
        break;

        case 'H':// tras e esquerda
        digitalWrite(2, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(4, HIGH);
        digitalWrite(5, LOW);
        break;

        case 'J':// frente e direita
        digitalWrite(2, LOW);
        digitalWrite(3, HIGH);
        digitalWrite(4, HIGH);
        digitalWrite(5, LOW);
        break;
    } 
  }
}
