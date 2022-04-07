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
  pinMode(12, OUTPUT);
}

void loop(){
  digitalWrite(12, HIGH);
  delay(100);

  digitalWrite(12, LOW);
  delay(100);
}