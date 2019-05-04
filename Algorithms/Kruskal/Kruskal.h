#pragma once
#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include "../../Graphs/AdjacencyMatrix.h"
#include "../../Graphs/AdjacencyList.h"
#include "../../Utility/Utility.h"
#include "../../Utility/Edge.h"

/// Struktura reprezentująca zbiór.
struct Subset
{
    /// Rodzic zbioru.
    int parent;
    /// Ranga zbioru.
    int rank;
};

/// Klasa dla algorytmu Kruskala.
class Kruskal
{
private:
    /// Lista krawędzi drzewa MST.
    std::list<Edge> edgeList;
    /// Sprawdza do którego zbioru należy dany element.
    /// \param subsets - tablica zbiorów rozłącznych.
    /// \param element - element do przyporządkowania.
    /// \return indeks zbioru do którego należy element.
    static int find(Subset * subsets, int element);
    /// Łączy zbiory według rangi.
    /// \param subsets - tablica zbiorów rozłącznych.
    /// \param first - indeks pierwszego zbioru.
    /// \param second - indeks drugiego zbioru.
    static void setUnion(Subset * subsets, int first, int second);
public:
    /// Konstruktor klasy algorytmu Kruskala.
    Kruskal();
    /// Desktruktor klasy algorytmu Kruskala.
    ~Kruskal();
    /// Wykonuje algorytm dla grafu w postaci macierzy sąsiedztwa.
    /// \param graph - macierz sąsiedztwa grafu.
    void proccessMatrix(AdjacencyMatrix * graph);
    /// Wykonuje algorytm dla grafu w postaci listy sąsiedztwa.
    /// \param graph - lista sąsiedztwa grafu.
    void proccessList(AdjacencyList * graph);
    /// Zwraca listę krawędzi drzewa MST.
    std::list<Edge> &getEdgeList();
    /// Usuwa wyniki działania algorytmu poprzez wyczyszczenie kontenerów.
    void resetContainers();
};