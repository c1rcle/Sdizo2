#pragma once

#include <iostream>
#include <iomanip>
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
    /// Dodaje krawędź do grafu.
    /// \param startVertex - wierzchołek początkowy krawędzi.
    /// \param endVertex - wierzchołek końcowy krawędzi.
    /// \param weight - waga krawędzi.
    void addEdge(int startVertex, int endVertex, int weight);
    /// Usuwa krawędź z grafu.
    /// \param startVertex - wierzchołek początkowy krawędzi.
    /// \param endVertex  - wierzchołek końcowy krawędzi.
    void removeEdge(int startVertex, int endVertex);
    /// Sprawdza czy krawędź istnieje w grafie.
    /// \param startVertex - wierzchołek początkowy krawędzi.
    /// \param endVertex - wierzchołek końcowy krawędzi.
    /// \return waga znalezionego wierzchołka lub zero, jeśli nie został znaleziony.
    int findEdge(int startVertex, int endVertex);
    /// Zwraca ilość wierzchołków grafu.
    int getSize();
    /// Wyświetla graf.
    void display();
};