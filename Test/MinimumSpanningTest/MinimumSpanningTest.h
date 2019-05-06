#include "../../Algorithms/Prim/Prim.h"
#include "../../Algorithms/Kruskal/Kruskal.h"
#include "../Measurement.h"
#include <fstream>

/// Klasa służąca do testowania wydajności algorytmów problemu najmniejszego drzewa rozpinającego.
class MinimumSpanningTest
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
    /// Testuje wydajność wykonywania się algorytmu Prima.
    /// \param size - ilość wierzchołków.
    /// \param density - gęstość grafu.
    TimeMeasurement primTest(int vertexCount, int density, Prim * prim);
    /// Testuje wydajność wykonywania się algorytmu Kruskala.
    /// \param size - ilość wierzchołków.
    /// \param density - gęstość grafu.
    TimeMeasurement kruskalTest(int vertexCount, int density, Kruskal * kruskal);
public:
    /// Konstruktor klasy MinimumSpanningTest.
    MinimumSpanningTest();
    /// Destruktor klasy MinimumSpanningTest.
    ~MinimumSpanningTest();
    /// Przeprowadza testy czasu wykonania dla zdefiniowanych wielkości grafu.
    void executionTestAverage();
};