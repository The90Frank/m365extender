#include "Arrow.h"

void Arrow::blinkStart(){
  currentMillis = millis();
  arrowON = true;
}

void Arrow::blinkStop(){
  arrowON = false;
}

void Arrow::lBlink(){
  currentMillis = millis();
  if (currentMillis > previousMillis + _interval) {
    previousMillis = currentMillis;
    arrowState = !arrowState;
  }
}

Arrow::Arrow(uint32_t arrowPin, uint32_t interval){
  _arrowPin = arrowPin;
  _interval = interval;

  arrowState = LOW;
  arrowON = false;

  previousMillis = 0;
  currentMillis = 0;

  pinMode(_arrowPin, OUTPUT);
  analogWrite(_arrowPin, LOW);
}

void Arrow::exec(){
  if (arrowON){
    lBlink();
    digitalWrite(_arrowPin, arrowState);
  }
  else digitalWrite(_arrowPin, LOW);
}
