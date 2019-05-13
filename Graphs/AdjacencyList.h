#pragma once

#include <iostream>
#include <climits>
#include <list>

/// Struktura reprezentująca element listy.
struct ListItem
{
    /// Numer wierzchołka.
    int vertex;
    /// Waga danego połączenia.
    int weight;
    /// Porównuje ze sobą dwa elementy listy.
    /// \param item - element do porównania.
    /// \return true jeśli równe, w przeciwnym wypadku false.
    bool operator==(const ListItem& item)
    {
        return this->vertex == item.vertex && this->weight == item.weight;
    }
    bool operator<(const ListItem& item)
    {
        return this->weight < item.weight;
    }
    bool operator<=(const ListItem& item)
    {
        return this->weight <= item.weight;
    }
    bool operator>(const ListItem& item)
    {
        return this->weight > item.weight;
    }
};

/// Klasa reprezentująca listę sąsiedztwa.
class AdjacencyList
{
private:
    /// Stała opisująca wyjątek.
    const std::string EXCEPTION_DESC = "Nieprawidłowe dane (przekroczony zakres lub zła waga)!";
    /// Tablica przechowująca strukturę grafu.
    std::list<ListItem> * base;
    /// Ilość krawędzi w grafie.
    int graphSize;
    /// Znajduje element w liście.
    /// \param list - lista do przeszukania.
    /// \param vertex - wierzchołek do znalezienia.
    /// \return Iterator wskazujący na dany element, w przeciwnym wypadku iterator wskazujący na end().
    static std::list<ListItem>::iterator findVertex(std::list<ListItem> &list, int vertex);
public:
    /// Konstruktor klasy listy sąsiedztwa.
    explicit AdjacencyList(int graphSize);
    /// Desktruktor klasy listy sąsiedztwa.
    ~AdjacencyList();
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
    /// Zwraca listę krawędzi sąsiadujących dla danego wierzchołka.
    /// \param vertex - wierzchołek dla którego zostanie zwrócona lista.
    /// \return lista krawędzi sąsiadującuch dla danego wierzchołka.
    std::list<ListItem>& getListForVertex(int vertex);
    /// Zwraca liczbę wierzchołków w grafie.
    int getSize();
    /// Wyświetla graf.
    void display();
};