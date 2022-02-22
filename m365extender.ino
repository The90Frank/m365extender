#include "Arrow.h"

const uint32_t flashPin = 13;
const uint32_t interruptFlashPin = 0;

const uint32_t buzzerPin = 12;
const uint32_t interruptBuzzerPin = 1;

const uint32_t arrowPinL = 11;
const uint32_t interruptPinL = 2;

const uint32_t arrowPinR = 10;
const uint32_t interruptPinR = 3;

const uint32_t intervalArrow = 500;

const Arrow left = Arrow(arrowPinL, intervalArrow);
const Arrow right = Arrow(arrowPinR, intervalArrow);

void interL() {
  byte state = digitalRead(interruptPinL);
  if (state == HIGH) {
    left.execStart();
  } else {
    left.execStop();
  }
}

void interR() {
  byte state = digitalRead(interruptPinR);
  if (state == HIGH) {
    right.execStart();
  } else {
    right.execStop();
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
