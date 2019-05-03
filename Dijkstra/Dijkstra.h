#pragma once
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <climits>
#include "../Graphs/AdjacencyMatrix.h"
#include "../Graphs/AdjacencyList.h"

/// Klasa dla algorytmu Dijkstry.
class Dijkstra
{
private:
    typedef std::priority_queue<ListItem, std::vector<ListItem>, bool (*)(ListItem, ListItem)> minQueue;
    /// Kolejka priorytetowa dla wierzchołków
    minQueue vertexQueue;
    /// Tablica najkrótszych odległości do wierzchołków.
    int * distance;
    /// Tablica poprzedników dla wierzchołków.
    int * predeccesor;
    /// Wypełnia kolejkę wierzchołkami.
    /// \param size - ilość wierzchołków grafu.
    void updateQueue(int size, std::vector<int> &completedVertices);
    /// Sprawdza czy dana wartość występuje w wektorze.
    /// \param vector - wektor dla którego będzie wykonana operacja.
    /// \param x - szukana wartość.
    /// \return true jeśli została znaleziona, false - w przeciwnym wypadku.
    static bool contains(std::vector<int> &vector, int x);
public:
    /// Konstruktor klasy algorytmu Dijkstry.
    /// \param size - ilość wierzchołków grafu.
    explicit Dijkstra(int size);
    /// Destruktor klasy algorytmu Dijkstry.
    ~Dijkstra();
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