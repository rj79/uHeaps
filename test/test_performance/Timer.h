#ifndef TIMER_H
#define TIMER_H

class Timer
{
public:
    Timer();
    void start();
    void stop();
    unsigned long elapsed() const;

private:
    unsigned long StartTime;
    unsigned long StopTime;
};

#endif