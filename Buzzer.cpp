#include "Buzzer.h"

void Buzzer::task(){
  if(pitches[buzzerState] == NOTE_NO) {
    noTone(buzzerPin);
  } else {
    tone(buzzerPin, pitches[buzzerState]);
  }
  setInterval(times[buzzerState]);
  buzzerState = (buzzerState+1)%melodySize;
}

void Buzzer::taskBoot(){
  noTone(buzzerPin);
}

void Buzzer::taskShutdown(){
  noTone(buzzerPin);
}

Buzzer::Buzzer(uint32_t pin, uint32_t* _pitches, uint32_t* _times, uint32_t _melodySize){
  pitches = _pitches;
  times = _times;
  melodySize = _melodySize;
  buzzerPin = pin;
  setInterval(64);
  init();
  buzzerState = 0;

  noTone(buzzerPin);
}
