#include <Arduino.h>
#include "Timer.h"

Timer::Timer() :
    StartTime(0),
    StopTime(0)
{
    // Empty
}

void Timer::start()
{
    StartTime = millis();
}

void Timer::stop()
{
    StopTime = millis();
}

unsigned long Timer::elapsed() const
{
    return StopTime - StartTime;
}