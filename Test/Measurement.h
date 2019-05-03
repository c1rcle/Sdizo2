#include <chrono>

class Measurement
{
private:
    double duration;
    std::chrono::high_resolution_clock::time_point startTime;
    std::chrono::high_resolution_clock::time_point endTime;
public:
    Measurement();
    void startTimer();
    void stopTimer();
    double getDuration();
};