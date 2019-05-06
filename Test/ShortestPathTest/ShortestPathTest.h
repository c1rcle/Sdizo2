#include "../../Algorithms/Dijkstra/Dijkstra.h"
#include "../../Algorithms/FordBellman/FordBellman.h"
#include "../Measurement.h"
#include <fstream>

/// Klasa służąca do testowania wydajności algorytmów problemu najkrótszej ścieżki.
class ShortestPathTest
{
private:
    /// Wskaźnik na obiekt klasy macierzy sąsiedztwa.
    AdjacencyMatrix * matrix;
    /// Wskaźnik na obiekt klasy listy sąsiedztwa.
    AdjacencyList * list;
    /// Obiekt klasy służacej do wykonywania pomiarów.
    Measurement measurement;
    /// Tworzy graf o 'size' wierzchołkach oraz 'density' gęstości.
    /// \param size - ilość wierzchołków.
    /// \param density - gęstość grafu.
    void generateGraph(int vertexCount, int density);
    /// Testuje wydajność wykonywania się algorytmu Dijkstry.
    /// \param size - ilość wierzchołków.
    /// \param density - gęstość grafu.
    TimeMeasurement dijkstraTest(int vertexCount, int density, Dijkstra * dijkstra);
    /// Testuje wydajność wykonywania się algorytmu Forda-Bellmana.
    /// \param size - ilość wierzchołków.
    /// \param density - gęstość grafu.
    TimeMeasurement fordBellmanTest(int vertexCount, int density, FordBellman * fordBellman);
public:
    /// Konstruktor klasy ShortestPathTest.
    ShortestPathTest();
    /// Destruktor klasy ShortestPathTest.
    ~ShortestPathTest();
    /// Przeprowadza testy czasu wykonania dla zdefiniowanych wielkości grafu.
    void executionTestAverage();
};