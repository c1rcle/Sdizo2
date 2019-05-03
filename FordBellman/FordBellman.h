#pragma once

#include <string>
#include <climits>
#include "../Graphs/AdjacencyMatrix.h"
#include "../Graphs/AdjacencyList.h"

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
    /// \return Lista wierzchołków z drogami oraz poprzednikami.
    std::string proccessMatrix(AdjacencyMatrix * graph, int startingVertex);
    /// Wykonuje algorytm dla grafu w postaci listy sąsiedztwa.
    /// \param graph
    /// \param startingVertex
    /// \return Lista wierzchołków z drogami oraz poprzednikami.
    std::string proccessList(AdjacencyList * graph, int startingVertex);
};
