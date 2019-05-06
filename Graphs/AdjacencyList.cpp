#include "AdjacencyList.h"

AdjacencyList::AdjacencyList(int graphSize)
{
    this->graphSize = graphSize;
    //Alokujemy pamięć na 'graphSize' list.
    base = new std::list<ListItem>[graphSize];
}

AdjacencyList::~AdjacencyList()
{
    //Dealokujemy tablicę bazową.
    delete[] base;
}

void AdjacencyList::addEdge(int startVertex, int endVertex, int weight)
{
    try
    {
        //Tworzymy nowy element grafu o zadanej wadze.
        ListItem item{};
        item.vertex = endVertex;
        item.weight = weight;
        base[startVertex].push_back(item);
    }
    catch (std::out_of_range&)
    {
        throw std::invalid_argument(EXCEPTION_DESC);
    }
}

void AdjacencyList::removeEdge(int startVertex, int endVertex)
{
    try
    {
        //Znajdujemy i usuwamy wierzchołek jeśli iterator nie wskazuje na koniec listy.
        auto it = findVertex(base[startVertex], endVertex);
        if (it != base[startVertex].end())
            base[startVertex].remove(*(it));
    }
    catch (std::out_of_range&)
    {
        throw std::invalid_argument(EXCEPTION_DESC);
    }
}

int AdjacencyList::findEdge(int startVertex, int endVertex)
{
    //Zwracamy przepustowość krawędzi dla danych wierzchołków.
    for (auto item : base[startVertex])
    {
        if (item.vertex == endVertex) return item.weight;
    }
    return 0;
}

std::list<ListItem>::iterator AdjacencyList::findVertex(std::list<ListItem> &list, int vertex)
{
    //Iterujemy po liście aż do znalezienia danego wierzchołka.
    for (auto it = list.begin(); it != list.end(); it++)
        if ((*it).vertex == vertex) return it;
    return list.end();
}

std::list<ListItem> &AdjacencyList::getListForVertex(int vertex)
{
    //Zwraca listę sąsiadów dla danego wierzchołka.
    return base[vertex];
}

int AdjacencyList::getSize()
{
    //Zwraca ilość wierzchołków grafu.
    return graphSize;
}

std::string AdjacencyList::toString()
{
    //Zwraca ciąg znaków reprezentujący graf w postaci listy sąsiedztwa.
    std::string representation;
    for (int i = 0; i < graphSize; i++)
    {
        representation.append(std::to_string(i) + ": ");
        for (auto item : base[i]) representation.append(std::to_string(item.vertex)
        + "(" + std::to_string(item.weight) + "), ");
        representation.erase(representation.size() - 2);
        representation.append("\n");
    }
    return representation;
}