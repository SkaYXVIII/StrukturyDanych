//
// Created by barto on 11.04.2022.
//

#include "Timer.h"
#include <iostream>
using namespace std;

void Timer::startCounter() {
    counterStart = 0;
    LARGE_INTEGER li;
    if (!QueryPerformanceFrequency(&li))
        cout << "QueryPerformanceFrequency failed!\n";

    PCFreq = double(li.QuadPart) / 1000.0;

    QueryPerformanceCounter(&li);
    counterStart = li.QuadPart;
}

void Timer::getCounter() {
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    cout << endl;
    cout << "Operacja zajela: " << (li.QuadPart - counterStart) / PCFreq << " milisekund\n" << endl;
}
