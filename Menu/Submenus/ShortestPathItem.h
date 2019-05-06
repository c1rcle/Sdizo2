#include <iostream>
#include "../MenuItem.h"
#include "../../Algorithms/Dijkstra/Dijkstra.h"
#include "../../Algorithms/FordBellman/FordBellman.h"
#include "../../Test/ShortestPathTest/ShortestPathTest.h"

/// Klasa submenu dla problemu najkrótszej ścieżki.
class ShortestPathItem : public MenuItem
{
private:
    /// Wskaźnik na obiekt klasy macierzy sąsiedztwa.
    AdjacencyMatrix * matrix{};
    /// Wskaźnik na obiekt klasy listy sąsiedztwa.
    AdjacencyList * list{};
    /// Wierzchołek początkowy dla algorytmów.
    int startingVertex{};
    /// Wyświetla dane submenu.
    void printMenu() override;
    /// Ładuje dane grafu z pliku.
    void loadFile();
    /// Tworzy losowy graf.
    void createRandom();
    /// Wyświetla graf dla obu reprezentacji.
    void display();
    /// Wykonuje pierwszy algorytm (algorytm Dijkstry).
    void executeFirst();
    /// Wykonuje drugi algorytm (algorytm Forda-Bellmana).
    void executeSecond();
    /// Wykonuje testy dla obu algorytmów.
    void test();
    /// Wyświetla rezultat działania algorytmu.
    void displayAlgorithmResult(int * distance, int * predeccesor);
public:
    /// Konstruktor klasy submenu dla problemu najkrótszej ścieżki.
    ShortestPathItem();
    /// Obsługuje pętlę komend.
    void processInput() override;
};
