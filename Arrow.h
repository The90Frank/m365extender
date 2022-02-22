#ifndef __ARROW_H
#define __ARROW_H

#include <Arduino.h>

class Arrow
{
private:
    uint32_t _arrowPin;
    uint32_t _interval;
    bool arrowState;
    bool arrowON;
    uint32_t previousMillis;
    uint32_t currentMillis;
    
    void lBlink();

public:
    Arrow(uint32_t arrowPin, uint32_t interval);

    void exec();
    void blinkStart();
    void blinkStop();

    bool getArrowON() { return arrowON; }
};

#endif
