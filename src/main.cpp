#include <Arduino.h>

void setup() {
  // PD2 pour le bouton poussoir => entrée avec résistance de pullup
  // PD3 pour la LED => sortie
  DDRD &= ~(1<<DDD2);     // Configuration en entrée de PORTD2
  bitSet(DDRD, DDD3);     // Configuration en sortie de PORDT3
  bitSet(PORTD, PORTD2);  // Activation de la résistance de pullup
}

void loop() {
  // Bouton appuyé alors on allume la LED sinon on éteint la LED
  if (bitRead(PIND, PIND2) == 0) bitSet(PORTD, PORTD3); else bitClear(PORTD, PORTD3);
}