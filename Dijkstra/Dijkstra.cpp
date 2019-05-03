#include "Dijkstra.h"

Dijkstra::Dijkstra(int size)
{
    auto compare = [](ListItem left, ListItem right) { return left.weight > right.weight; };
    vertexQueue = minQueue(compare);
    distance = new int[size];
    predeccesor = new int[size];
}

Dijkstra::~Dijkstra()
{
    delete[] distance;
    delete[] predeccesor;
}

void Dijkstra::proccessMatrix(AdjacencyMatrix * graph, int startingVertex)
{
    std::vector<int> completedVertices;
    for (int i = 0; i < graph->getSize(); i++)
    {
        distance[i] = INT_MAX;
        predeccesor[i] = -1;
    }

    distance[startingVertex] = 0;
    updateQueue(graph->getSize(), completedVertices);

    while (!vertexQueue.empty())
    {
        auto item = vertexQueue.top();
        vertexQueue.pop();
        for (int i = 0; i < graph->getSize(); i++)
        {
            int weight = graph->findVertex(item.vertex, i);
            if (weight != 0)
            {
                if (distance[item.vertex] + weight < distance[i])
                {
                    distance[i] = distance[item.vertex] + weight;
                    predeccesor[i] = item.vertex;
                }
            }
        }
        completedVertices.push_back(item.vertex);
        updateQueue(graph->getSize(), completedVertices);
    }
}

void Dijkstra::proccessList(AdjacencyList * graph, int startingVertex)
{
    std::vector<int> completedVertices;
    for (int i = 0; i < graph->getSize(); i++)
    {
        distance[i] = INT_MAX;
        predeccesor[i] = -1;
    }

    distance[startingVertex] = 0;
    updateQueue(graph->getSize(), completedVertices);

    while (!vertexQueue.empty())
    {
        auto item = vertexQueue.top();
        vertexQueue.pop();
        for (int i = 0; i < graph->getSize(); i++)
        {
            int weight = graph->findVertex(item.vertex, i);
            if (weight != 0)
            {
                if (distance[item.vertex] + weight < distance[i])
                {
                    distance[i] = distance[item.vertex] + weight;
                    predeccesor[i] = item.vertex;
                }
            }
        }
        completedVertices.push_back(item.vertex);
        updateQueue(graph->getSize(), completedVertices);
    }
}

void Dijkstra::updateQueue(int size, std::vector<int> &completedVertices)
{
    for (int i = 0; i < size; i++)
    {
        if (!contains(completedVertices, i))
        {
            ListItem item { i, distance[i] };
            vertexQueue.push(item);
        }
    }
}

bool Dijkstra::contains(std::vector<int> &vector, int x)
{
    return std::find(vector.begin(), vector.end(), x) != vector.end();
}

int * Dijkstra::getDistanceArray()
{
    return distance;
}

int * Dijkstra::getPredeccesorArray()
{
    return predeccesor;
}
