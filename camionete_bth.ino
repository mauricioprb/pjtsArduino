#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial bth(11,12);
Servo servo;

int estadoLed1;
int estadoLed2;

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);

  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  
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
        
      case 'F': // frente
        digitalWrite(2, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
        break;
         
      case 'B': //ré
        digitalWrite(2, LOW);
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
        break;
        
      case 'L': // esquerda
        servo.write(180);
        break;
        
      case 'R': // direita
        servo.write(5);
        break;

        case 'I': // frente e direita
          digitalWrite(2, HIGH);
          digitalWrite(3, LOW);
          digitalWrite(4, LOW);
          digitalWrite(5, HIGH);
          servo.write(5);
          break;

        case 'G': // frente e esquerda
          digitalWrite(2, HIGH);
          digitalWrite(3, LOW);
          digitalWrite(4, LOW);
          digitalWrite(5, HIGH);
          servo.write(180);
         break;

        case 'H': // tras e esquerda
          digitalWrite(2, LOW);
          digitalWrite(3, HIGH);
          digitalWrite(4, HIGH);
          digitalWrite(5, LOW);
          break;

        case 'J': // tras e direita
          digitalWrite(2, LOW);
          digitalWrite(3, HIGH);
          digitalWrite(4, HIGH);
          digitalWrite(5, LOW);
          break;

        case 'W':
          digitalWrite(7, HIGH);
          digitalWrite(8, HIGH);
          break;
        
        case 'w':
          digitalWrite(7, LOW);
          digitalWrite(8, LOW);
          break;

        case 'V':
          tone(6, 1500);
          delay(100);
          noTone(6);
          break;
    } 
  }
}
