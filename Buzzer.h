#ifndef __BUZZER_H
#define __BUZZER_H

#include "AsyncExecutor.h"
#include "Pitches.h"

class Buzzer : public AsyncExecutor 
{
private:
    uint32_t buzzerPin;
    uint32_t buzzerState;
    uint32_t melodySize;
    uint32_t* pitches;
    uint32_t* times;
    

public:
    Buzzer(uint32_t pin, uint32_t* _pitches, uint32_t* _times, uint32_t _melodySize);
    bool getBuzzerON() { return objectActive; }

    void task();
    void taskBoot();
    void taskShutdown();
};

#endif
