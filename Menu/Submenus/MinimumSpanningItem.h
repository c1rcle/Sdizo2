#include <iostream>
#include "../MenuItem.h"
#include "../../Algorithms/Prim/Prim.h"
#include "../../Algorithms/Kruskal/Kruskal.h"
#include "../../Test/MinimumSpanningTest/MinimumSpanningTest.h"

/// Klasa submenu dla problemu minimalnego drzewa rozpinającego.
class MinimumSpanningItem : public MenuItem
{
private:
    /// Wskaźnik na obiekt klasy macierzy sąsiedztwa.
    AdjacencyMatrix * matrix{};
    /// Wskaźnik na obiekt klasy listy sąsiedztwa.
    AdjacencyList * list{};
    /// Wyświetla dane submenu.
    void printMenu() override;
    /// Ładuje dane grafu z pliku.
    void loadFile();
    /// Tworzy losowy graf.
    void createRandom();
    /// Wyświetla graf dla obu reprezentacji.
    void display();
    /// Wykonuje pierwszy algorytm (algorytm Prima).
    void executeFirst();
    /// Wykonuje drugi algorytm (algorytm Kruskala).
    void executeSecond();
    /// Wykonuje testy dla obu algorytmów.
    void test();
    /// Wyświetla rezultat działania algorytmu Kruskala.
    /// \param edgeList - referencja do listy krawędzi drzewa MST.
    static void displayKruskalResult(std::list<Edge> &edgeList);
    /// Wyświetla rezultat działania algorytmu Prima.
    /// \param key - tablica najmniejszych wag krawędzi dla wierzchołków.
    /// \param connection - tablica połączeń.
    static void displayPrimResult(int * key, int * connection, int size);
public:
    /// Konstruktor klasy submenu dla problemu najkrótszej ścieżki.
    MinimumSpanningItem();
    /// Obsługuje pętlę komend.
    void processInput() override;
};

