#include "AdjacencyList.h"

AdjacencyList::AdjacencyList(int graphSize)
{
    this->graphSize = graphSize;
    base = new std::list<ListItem>[graphSize];
}

AdjacencyList::~AdjacencyList()
{
    delete[] base;
}

void AdjacencyList::addVertex(int startVertex, int endVertex, int weight)
{
    try
    {
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

void AdjacencyList::removeVertex(int startVertex, int endVertex)
{
    try
    {
        auto it = findVertex(base[startVertex], endVertex);
        if (it != base[startVertex].end())
            base[startVertex].remove(*(it));
    }
    catch (std::out_of_range&)
    {
        throw std::invalid_argument(EXCEPTION_DESC);
    }
}

int AdjacencyList::findVertex(int startVertex, int endVertex)
{
    for (auto item : base[startVertex])
    {
        if (item.vertex == endVertex) return item.weight;
    }
    return 0;
}

std::list<ListItem>::iterator AdjacencyList::findVertex(std::list<ListItem> &list, int vertex)
{
    for (auto it = list.begin(); it != list.end(); it++)
        if ((*it).vertex == vertex) return it;
    return list.end();
}

std::list<ListItem> &AdjacencyList::getListForVertex(int vertex)
{
    return base[vertex];
}

int AdjacencyList::getSize()
{
    return graphSize;
}

std::string AdjacencyList::toString()
{
    std::string representation;
    for (int i = 0; i < graphSize; i++)
    {
        for (auto item : base[i]) representation.append(std::to_string(item.vertex)
        + "(" + std::to_string(item.weight) + "), ");
        representation.erase(representation.size() - 2);
        representation.append("\n");
    }
    return representation;
}