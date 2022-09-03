#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial bth(11,12);
Servo servo;

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
  servo.attach(9);
  servo.write(90);
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

        servo.write(90);
        break;
        
      case 'F':// frente
        digitalWrite(2, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
        break;
         
      case 'B'://Ré
        digitalWrite(2, LOW);
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
        break;
        
      case 'L': // Esquerda
        servo.write(180);
        break;
        
      case 'R': // Direita
        servo.write(5);
        break;

        case 'I':// frente e direita
        digitalWrite(2, LOW);
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
        digitalWrite(5, HIGH);

        servo.write(5);
        
        break;

        case 'G':// frente e esquerda
        digitalWrite(2, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, HIGH);

        servo.write(180);
        
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
