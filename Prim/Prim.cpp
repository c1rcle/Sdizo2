#include "Prim.h"

Prim::Prim()
{
    clearQueue();
}

Prim::~Prim() = default;

void Prim::proccessMatrix(AdjacencyMatrix * graph)
{
    clearQueue();
    edgeList.clear();
    std::list<int> treeVertices;
    int startingVertex = rand() % graph->getSize();
    treeVertices.push_back(startingVertex);

    for (int i = 0; i < graph->getSize(); i++)
    {
        int weight = graph->findVertex(startingVertex, i);
        if (weight != 0)
        {
            Edge edge = { startingVertex, i, weight };
            vertexQueue.push(edge);
        }
    }

    while (treeVertices.size() < graph->getSize())
    {
        Edge item = vertexQueue.top();
        vertexQueue.pop();
        if (Utility::contains(treeVertices, item.end)) continue;
        treeVertices.push_back(item.end);
        edgeList.push_back(item);

        for (int i = 0; i < graph->getSize(); i++)
        {
            int weight = graph->findVertex(item.end, i);
            Edge newItem = { item.end, i, weight };
            if (weight != 0 && !containsEdge(edgeList, newItem)
                && !Utility::contains(treeVertices, i))
                vertexQueue.push(newItem);
        }
    }
}

void Prim::proccessList(AdjacencyList * graph)
{
    clearQueue();
    edgeList.clear();
    std::list<int> treeVertices;
    int startingVertex = rand() % graph->getSize();
    treeVertices.push_back(startingVertex);

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
            if (!containsEdge(edgeList, newItem)
            && !Utility::contains(treeVertices, rowItem.vertex)) vertexQueue.push(newItem);
        }
    }
}

bool Prim::containsEdge(std::list<Edge> &edgeList, Edge edge)
{
    return std::find(edgeList.begin(), edgeList.end(), edge) != edgeList.end();
}

std::list<Edge> &Prim::getEdgeList()
{
    return edgeList;
}

void Prim::clearQueue()
{
    auto compare = [](Edge left, Edge right) { return left.weight > right.weight; };
    vertexQueue = minQueue(compare);
}
