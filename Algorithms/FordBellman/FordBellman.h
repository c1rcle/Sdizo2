#pragma once

#include <string>
#include <climits>
#include "../../Graphs/AdjacencyMatrix.h"
#include "../../Graphs/AdjacencyList.h"

/// Klasa dla algorytmu Forda-Bellmana.
class FordBellman
{
private:
    /// Tablica najkrótszych odległości do wierzchołków.
    int * distance;
    /// Tablica poprzedników dla wierzchołków.
    int * predeccesor;
public:
    /// Konstruktor klasy algorytmu Dijkstry.
    /// \param size - ilość wierzchołków grafu.
    explicit FordBellman(int size);
    /// Destruktor klasy algorytmu Forda-Bellmana.
    ~FordBellman();
    /// Wykonuje algorytm dla grafu w postaci macierzy sąsiedztwa.
    /// \param graph - macierz sąsiedztwa grafu.
    /// \param startingVertex - wierzchołek startu.
    void proccessMatrix(AdjacencyMatrix * graph, int startingVertex);
    /// Wykonuje algorytm dla grafu w postaci listy sąsiedztwa.
    /// \param graph - lista sąsiedztwa grafu.
    /// \param startingVertex - wierzchołek startu.
    void proccessList(AdjacencyList * graph, int startingVertex);
    /// Zwraca wskaźnik na pierwszy element tablicy odłegłości.
    /// \return wskaźnik na pierwszy element tablicy odłegłości.
    int * getDistanceArray();
    /// Zwraca wskaźnik na pierwszy element tablicy poprzedników.
    /// \return wskaźnik na pierwszy element tablicy poprzedników.
    int * getPredeccesorArray();
};
