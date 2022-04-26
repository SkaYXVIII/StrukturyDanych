//
// Created by barto on 11.04.2022.
//

#ifndef SDIZO_TIMER_H
#define SDIZO_TIMER_H

#include <windows.h>

class Timer {
    double PCFreq;
    __int64 counterStart;

public:
    void startCounter();
    void getCounter();
};


#endif //SDIZO_TIMER_H
