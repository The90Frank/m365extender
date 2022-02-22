#include "AsyncExecutor.h"

void AsyncExecutor::execStart(){
  currentMillis = millis();
  objectActive = true;
  taskBoot();
}

void AsyncExecutor::execStop(){
  objectActive = false;
  taskShutdown();
}

void AsyncExecutor::exec(){
  if(objectActive){
    currentMillis = millis();
    if (currentMillis > previousMillis + interval) {
      previousMillis = currentMillis;
      task();
    }
  }
}

void AsyncExecutor::init(){
  objectActive = false; 
  previousMillis = 0;
  currentMillis = 0;
}

void AsyncExecutor::setInterval(uint32_t i){
  interval = i;
}
