#ifndef __ASYNCEXECUTOR_H
#define __ASYNCEXECUTOR_H

#include <Arduino.h>

class AsyncExecutor
{
protected:
    uint32_t interval;
    uint32_t previousMillis;
    uint32_t currentMillis;
    
    bool objectActive;
    
    virtual void task();
    virtual void taskBoot();
    virtual void taskShutdown();

public:
    void setInterval(uint32_t i);
    void init();
    void exec();
    void execStart();
    void execStop();
};

#endif
