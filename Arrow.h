#ifndef __ARROW_H
#define __ARROW_H

#include "AsyncExecutor.h"

class Arrow : public AsyncExecutor 
{
private:
    uint32_t arrowPin;
    bool arrowState;

public:
    Arrow(uint32_t pin, uint32_t interv);
    bool getArrowON() { return objectActive; }

    void task();
    void taskBoot();
    void taskShutdown();
};

#endif
