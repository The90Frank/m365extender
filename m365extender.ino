#include "Arrow.h"

const uint32_t arrowPinL = 52;
const uint32_t interruptPinL = 2;

const uint32_t arrowPinR = 53;
const uint32_t interruptPinR = 3;

const uint32_t interval = 500;

const Arrow left = Arrow(arrowPinL, interval);
const Arrow right = Arrow(arrowPinR, interval);

void interL() {
  byte state = digitalRead(interruptPinL);
  if (state == HIGH) {
    left.blinkStart();
  } else {
    left.blinkStop();
  }
}

void interR() {
  byte state = digitalRead(interruptPinR);
  if (state == HIGH) {
    right.blinkStart();
  } else {
    right.blinkStop();
  }
}

void setup() {
  setupInter(interruptPinL, interL, CHANGE);
  setupInter(interruptPinR, interR, CHANGE);
}

void loop() {
  left.exec();
  right.exec();
}

void setupInter(uint32_t pin, void (*interFun)(void), uint32_t mode){
  pinMode(pin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(pin), interFun, mode);
}
