#pragma once

#include <iostream>
#include <math.h>
#include <string>

/// Klasa reprezentująca macierz sąsiedztwa.
class AdjacencyMatrix
{
private:
    /// Stała opisująca wyjątek.
    const std::string EXCEPTION_DESC = "Nieprawidłowe dane (przekroczony zakres lub zła waga)!";
    /// Tablica przechowująca strukturę grafu.
    int * base;
    /// Ilość krawędzi w grafie.
    int graphSize;
public:
    /// Konstruktor klasy macierzy sąsiedztwa.
    explicit AdjacencyMatrix(int graphSize);
    /// Desktruktor klasy macierzy sąsiedztwa.
    ~AdjacencyMatrix();
    /// Dodaje wierzchołek do grafu.
    /// \param startVertex - wierzchołek początkowy krawędzi.
    /// \param endVertex - wierzchołek końcowy krawędzi.
    /// \param weight - waga krawędzi.
    void addVertex(int startVertex, int endVertex, int weight);
    /// Usuwa wierzchołek z grafu.
    /// \param startVertex - wierzchołek początkowy krawędzi.
    /// \param endVertex  - wierzchołek końcowy krawędzi.
    void removeVertex(int startVertex, int endVertex);
    /// Sprawdza czy krawędź istnieje w grafie.
    /// \param startVertex - wierzchołek początkowy krawędzi.
    /// \param endVertex - wierzchołek końcowy krawędzi.
    /// \return waga znalezionego wierzchołka lub zero, jeśli nie został znaleziony.
    int findVertex(int startVertex, int endVertex);
    /// Zwraca ilość wierzchołków grafu.
    int getSize();
    /// Zwraca łańcuch znaków reprezentujący macierz.
    std::string toString();
};