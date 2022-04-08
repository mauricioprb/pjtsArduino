/**
 * @file main.cpp
 * @author Mauricio Pereira Braga (mauprb@gmail.com)
 * @brief Semáfaro - Bolsa PROBEX
 * @version 0.1
 * @date 2022-04-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <Arduino.h>

void setup(){
  // Declarar as saídas 10, 11, 12 como saídas, no caso, acender os leds
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
}

// Led verde
void loop(){
  digitalWrite(10, HIGH); // Acender a saída 12
  delay(4000); // Mante-la acesa por 4s
  digitalWrite(10, LOW); // Desligar a saída 12

  // Led amarelo
  digitalWrite(11, HIGH);
  delay(2000);
  digitalWrite(11, LOW);

  // Led vermelho
  digitalWrite(12, HIGH);
  delay(4000);
  digitalWrite(12, LOW);
}