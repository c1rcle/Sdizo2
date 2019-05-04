#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "../../Graphs/AdjacencyMatrix.h"
#include "../../Graphs/AdjacencyList.h"
#include "../../Utility/Utility.h"
#include "../../Utility/Edge.h"

/// Klasa dla algorytmu Prima.
class Prim
{
private:
    typedef std::priority_queue<Edge, std::vector<Edge>, bool (*)(Edge, Edge)> minQueue;
    /// Kolejka priorytetowa dla wierzchołków
    minQueue vertexQueue;
    /// Lista krawędzi drzewa MST.
    std::list<Edge> edgeList;
    /// Czyści kolejkę wierzchołków.
    void clearQueue();
public:
    /// Konstruktor klasy algorytmu Prima.
    Prim();
    /// Destruktor klasy algorytmu Prima.
    ~Prim();
    /// Wykonuje algorytm dla grafu w postaci macierzy sąsiedztwa.
    /// \param graph - macierz sąsiedztwa grafu.
    void proccessMatrix(AdjacencyMatrix * graph);
    /// Wykonuje algorytm dla grafu w postaci listy sąsiedztwa.
    /// \param graph - lista sąsiedztwa grafu.
    void proccessList(AdjacencyList * graph);
    /// Zwraca listę krawędzi drzewa MST.
    /// \return - referencja do listy krawędzi drzewa MST.
    std::list<Edge> &getEdgeList();
    /// Usuwa wyniki działania algorytmu poprzez wyczyszczenie kontenerów.
    void resetContainers();
};