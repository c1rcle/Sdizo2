#include "Prim.h"

Prim::Prim() = default;

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
            vertexQueue.insert(edge);
        }
    }

    //Dopóki nasze drzewo nie zawiera wszystkich wierzchołków znajdujących się w grafie,
    //dodajemy do niego wierzchołek o najmniejszej wadze przejścia oraz aktualizujemy listę wierzchołków
    //o nowe, wychodzące z dodanego wierzchołka.
    while (treeVertices.size() < graph->getSize())
    {
        Edge item = vertexQueue.pop();
        treeVertices.push_back(item.end);
        edgeList.push_back(item);

        for (int i = 0; i < graph->getSize(); i++)
        {
            if (!Utility::contains(treeVertices, i))
            {
                int weight = graph->findEdge(item.end, i);
                Edge newItem = { item.end, i, weight };
                if (weight != 0 && !Utility::containsEdge(edgeList, newItem)) vertexQueue.insert(newItem);
            }
        }
        deleteNotNeededEdges(treeVertices);
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
        vertexQueue.insert(edge);
    }

    while (treeVertices.size() < graph->getSize())
    {
        Edge item = vertexQueue.pop();
        treeVertices.push_back(item.end);
        edgeList.push_back(item);

        std::list<ListItem> &currentRow = graph->getListForVertex(item.end);
        for (auto rowItem : currentRow)
        {
            if (!Utility::contains(treeVertices, rowItem.vertex))
            {
                Edge newItem = { item.end, rowItem.vertex, rowItem.weight };
                if (!Utility::containsEdge(edgeList, newItem)) vertexQueue.insert(newItem);
            }
        }
        deleteNotNeededEdges(treeVertices);
    }
}

void Prim::deleteNotNeededEdges(std::list<int> &treeVertices)
{
    for (auto item : vertexQueue.getContainer())
    {
        if (Utility::contains(treeVertices, item.end))
            vertexQueue.updateAndDelete(item);
    }
}

void Prim::clearQueue()
{
    vertexQueue.clear();
}

std::list<Edge> &Prim::getEdgeList()
{
    return edgeList;
}

void Prim::resetContainers()
{
    //Czyści kontenery przechowujące wyniki algorytmu.
    clearQueue();
    edgeList.clear();
}