#include "Prim.h"

Prim::Prim()
{
    //Przygotowujemy kolejkę.
    clearQueue();
}

Prim::~Prim() = default;

void Prim::proccessMatrix(AdjacencyMatrix * graph)
{
    //Lista służy do przechowywania wierzchołków, które należą już do MST.
    std::list<int> treeVertices;
    //Wierzchołek początkowy jest wybierany losowo.
    int startingVertex = rand() % graph->getSize();
    treeVertices.push_back(startingVertex);

    //Do kolejki priorytetowej dodajemy wszystkie krawędzie wychodzące z wylosowanego wierzchołka.
    for (int i = 0; i < graph->getSize(); i++)
    {
        int weight = graph->findEdge(startingVertex, i);
        if (weight != 0)
        {
            Edge edge = { startingVertex, i, weight };
            vertexQueue.push(edge);
        }
    }

    //Dopóki nasze drzewo nie zawiera wszystkich wierzchołków znajdujących się w grafie,
    //dodajemy do niego wierzchołek o najmniejszej wadze przejścia oraz aktualizujemy listę wierzchołków
    //o nowe, wychodzące z dodanego wierzchołka.
    while (treeVertices.size() < graph->getSize())
    {
        Edge item = vertexQueue.top();
        vertexQueue.pop();
        if (Utility::contains(treeVertices, item.end)) continue;
        treeVertices.push_back(item.end);
        edgeList.push_back(item);

        for (int i = 0; i < graph->getSize(); i++)
        {
            int weight = graph->findEdge(item.end, i);
            Edge newItem = { item.end, i, weight };
            if (weight != 0 && !Utility::containsEdge(edgeList, newItem)
                && !Utility::contains(treeVertices, i))
                vertexQueue.push(newItem);
        }
    }
}

void Prim::proccessList(AdjacencyList * graph)
{
    std::list<int> treeVertices;
    int startingVertex = rand() % graph->getSize();
    treeVertices.push_back(startingVertex);

    //Dla reprezentacji listowej mamy dokładnie tyle iteracji, ile krawędzi wychodzi z danego wierzchołka.
    std::list<ListItem> &firstRow = graph->getListForVertex(startingVertex);
    for (auto rowItem : firstRow)
    {
        Edge edge = { startingVertex, rowItem.vertex, rowItem.weight };
        vertexQueue.push(edge);
    }

    while (treeVertices.size() < graph->getSize())
    {
        Edge item = vertexQueue.top();
        vertexQueue.pop();
        if (Utility::contains(treeVertices, item.end)) continue;
        treeVertices.push_back(item.end);
        edgeList.push_back(item);

        std::list<ListItem> &currentRow = graph->getListForVertex(item.end);
        for (auto rowItem : currentRow)
        {
            Edge newItem = { item.end, rowItem.vertex, rowItem.weight };
            if (!Utility::containsEdge(edgeList, newItem)
            && !Utility::contains(treeVertices, rowItem.vertex)) vertexQueue.push(newItem);
        }
    }
}

std::list<Edge> &Prim::getEdgeList()
{
    return edgeList;
}

void Prim::clearQueue()
{
    //Inicjalizacja kolejki priorytetowej.
    auto compare = [](Edge left, Edge right) { return left.weight > right.weight; };
    vertexQueue = minQueue(compare);
}

void Prim::resetContainers()
{
    //Czyści kontenery przechowujące wyniki algorytmu.
    clearQueue();
    edgeList.clear();
}
