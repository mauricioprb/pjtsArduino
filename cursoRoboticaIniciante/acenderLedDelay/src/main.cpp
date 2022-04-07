/**
 * @file main.cpp
 * @author Mauricio Pereira Braga (mauprb@gmail.com)
 * @brief Piscar led com intervalo de 1 segundo - Bolsa PROBEX
 * @version 0.1
 * @date 2022-04-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <Arduino.h>

void setup(){
  pinMode(12, OUTPUT); // Declara a saída 12 como saída do led
}

void loop(){
  digitalWrite(12, HIGH); // Liga a saída 12
  delay(1000); // Espera 1s

  digitalWrite(12, LOW); // Desliga saída 12
  delay(1000); // Espera 1s 

  // Recomeça o ciclo
}