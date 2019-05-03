#include "Measurement.h"

Measurement::Measurement()
{
    duration = 0;
}

void Measurement::startTimer()
{
    startTime = std::chrono::high_resolution_clock::now();
}

void Measurement::stopTimer()
{
    endTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::nano> time = endTime - startTime;
    duration = time.count();
}

double Measurement::getDuration()
{
    return duration;
}