#include <iostream>
#include "../MenuItem.h"
#include "../../Prim/Prim.h"

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
    /// Wyświetla rezultat działania algorytmu.
    void displayAlgorithmResult(std::list<Edge> &edgeList);
public:
    /// Konstruktor klasy submenu dla problemu najkrótszej ścieżki.
    MinimumSpanningItem();
    /// Obsługuje pętlę komend.
    void processInput() override;
};

