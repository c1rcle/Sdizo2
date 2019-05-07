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
    /// Kolejka priorytetowa dla wierzchołków
    PriorityQueue<Edge> vertexQueue;
    /// Lista krawędzi drzewa MST.
    std::list<Edge> edgeList;
    /// Usuwa z kolejki krawędzie, których wierzchołek końcowy należy już do MST i aktualizuje ją.
    /// \param treeVertices - lista wierzchołków drzewa MST.
    void deleteNotNeededEdges(std::list<int> &treeVertices);
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