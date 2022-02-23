#include "Arrow.h"
#include "Buzzer.h"

const uint32_t flashPin = 10;
const uint32_t interruptFlashPin = 0;

const uint32_t buzzerPin = 11;
const uint32_t interruptBuzzerPin = 1;

const uint32_t arrowPinL = 12;
const uint32_t interruptPinL = 2;

const uint32_t arrowPinR = 13;
const uint32_t interruptPinR = 3;

const uint32_t intervalArrow = 500;

const Arrow left = Arrow(arrowPinL, intervalArrow);
const Arrow right = Arrow(arrowPinR, intervalArrow);

uint32_t pitches[] =  {NOTE_G4, NOTE_E4, NOTE_C4, NOTE_NO,  NOTE_C4, NOTE_NO,  NOTE_C4, NOTE_D4, NOTE_E4, NOTE_NO,  NOTE_F4, NOTE_NO,  NOTE_G4, NOTE_NO,  NOTE_G4, NOTE_NO,  NOTE_G4, NOTE_NO,  NOTE_E4,  NOTE_NO};
uint32_t times[] =    {150,     150,     300,     10,       300,     10,       150,     150,     150,     10,       150,     10,       300,     10,       300,     10,       300,     10,       300,      1500};
const Buzzer buzzer = Buzzer(buzzerPin, pitches, times, 20);

void interF() {
  byte state = digitalRead(interruptFlashPin);
  if (state == HIGH) {
    digitalWrite(flashPin, HIGH);
  } else {
    digitalWrite(flashPin, LOW);
  }
}

void interB() {
  byte state = digitalRead(interruptBuzzerPin);
  if (state == HIGH) {
    buzzer.execStart();
  } else {
    buzzer.execStop();
  }
}

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
  setupInter(interruptBuzzerPin, interB, CHANGE);
  setupInter(interruptFlashPin, interF, CHANGE);
}

void loop() {
  left.exec();
  right.exec();
  buzzer.exec();
}

void setupInter(uint32_t pin, void (*interFun)(void), uint32_t mode){
  pinMode(pin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(pin), interFun, mode);
}
