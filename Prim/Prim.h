#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "../Graphs/AdjacencyMatrix.h"
#include "../Graphs/AdjacencyList.h"
#include "../Utility/Utility.h"

/// Struktura opisująca krawędź.
struct Edge
{
    /// Wierzchołek początkowy krawędzi.
    int start;
    /// Wierzchołek końcowy krawędzi.
    int end;
    /// Waga krawędzi.
    int weight;
    /// Sprawdza czy krawędzie są równe (w przypadku MST są nieskierowane).
    /// \param item - krawędź do porównania.
    /// \return true jeśli krawędzie są równe, w przeciwnym wypadku false.
    bool operator==(const Edge &item)
    {
        return (this->start == item.start && this->end == item.end && this->weight == item.weight) ||
        (this->start == item.end && this->end == item.start && this->weight == item.weight);
    }
};

/// Klasa dla algorytmu Prima.
class Prim
{
private:
    typedef std::priority_queue<Edge, std::vector<Edge>, bool (*)(Edge, Edge)> minQueue;
    /// Kolejka priorytetowa dla wierzchołków
    minQueue vertexQueue;
    /// Lista krawędzi drzewa MST.
    std::list<Edge> edgeList;
    /// Sprawdza czy lista krawędzi nie zawiera podanej.
    /// \param edgeList - lista krawędzi.
    /// \param edge - krawędź do znalezienia.
    /// \return true jeśli zostanie odnaleziona, w przeciwnym wypadku false.
    static bool containsEdge(std::list<Edge> &edgeList, Edge edge);
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