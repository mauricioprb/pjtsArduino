#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int potenciometro = 0;
int valor = 0;

float vMin = 0;
float vMax = 5;
float potMin = 0;
float potMax = 1023;
float m;

 
void setup() {
  lcd.begin(16, 2);

  Serial.begin(9600);

  m = (vMax - vMin) / (potMax - potMin);
}
 
void loop() {
  float potencia = analogRead(potenciometro);

  float v = (m * (potencia - potMin)) + vMin;
  Serial.print(v);

  lcd.setCursor(3, 0);
  lcd.print(v);
  lcd.setCursor(3, 1);
  delay(1000);
}
