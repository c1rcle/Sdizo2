#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "../../Graphs/AdjacencyMatrix.h"
#include "../../Graphs/AdjacencyList.h"
#include "../../Utility/Utility.h"
#include "../../Utility/Edge.h"
#include "../../Utility/PriorityQueue.h"

/// Klasa dla algorytmu Prima.
class Prim
{
private:
    /// Wagi najmniejszych krawędzi dla konkretnego wierzchołka.
    int * key;
    /// Połączenia wierzchołków.
    int * connection;
    /// Kolejka priorytetowa dla wierzchołków
    PriorityQueue<ListItem> vertexQueue;
public:
    /// Konstruktor klasy algorytmu Prima.
    /// \param size - ilość wierzchołków grafu.
    explicit Prim(int size);
    /// Destruktor klasy algorytmu Prima.
    ~Prim();
    /// Wykonuje algorytm dla grafu w postaci macierzy sąsiedztwa.
    /// \param graph - macierz sąsiedztwa grafu.
    void proccessMatrix(AdjacencyMatrix * graph);
    /// Wykonuje algorytm dla grafu w postaci listy sąsiedztwa.
    /// \param graph - lista sąsiedztwa grafu.
    void proccessList(AdjacencyList * graph);
    /// Zwraca tablicę najmniejszych wag krawędzi dla wierzchołków.
    /// \return wskaźnik na pierwszy element tablicy krawędzi.
    int * getKeyArray();
    /// Zwraca tablicę połączeń wierzchołków.
    /// \return wskaźnik na pierwszy element tablicy połączeń.
    int * getConnectionArray();
};