#include "Arrow.h"

void Arrow::task(){
  arrowState = !arrowState;
  digitalWrite(arrowPin, arrowState);
}

void Arrow::taskBoot(){
  digitalWrite(arrowPin, HIGH);
}

void Arrow::taskShutdown(){
  digitalWrite(arrowPin, LOW);
}

Arrow::Arrow(uint32_t pin, uint32_t interv){
  arrowPin = pin;
  setInterval(interv);
  init();
  arrowState = LOW;

  pinMode(arrowPin, OUTPUT);
  analogWrite(arrowPin, LOW);
}
