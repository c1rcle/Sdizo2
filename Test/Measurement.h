#pragma once
#include <chrono>

/// Struktura opisująca czas wykonania dla obu algorytmów.
struct TimeMeasurement
{
    double first;
    double second;
};

/// Klasa służąca do mierzenia czasu wykonywania algorytmów.
class Measurement
{
private:
    /// Zmienna przechowująca informację o długości wykonywania pewnego segmentu (mikrosekundy).
    double duration;
    /// Zmienna przechowująca czas startu pomiaru.
    std::chrono::high_resolution_clock::time_point startTime;
    /// Zmienna przechowująca czas końca pomiaru.
    std::chrono::high_resolution_clock::time_point endTime;
public:
    /// Konstruktor klasy Measurement.
    Measurement();
    /// Rozpoczyna odmierzanie czasu.
    void startTimer();
    /// Kończy odmierzanie czasu.
    void stopTimer();
    /// Zwraca czas w mikrosekundach, który upłynął dla ostatniego pomiaru.
    double getDuration();
};