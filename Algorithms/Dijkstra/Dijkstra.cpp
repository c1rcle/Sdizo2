#include "Dijkstra.h"

Dijkstra::Dijkstra(int size)
{
    //Deklaracja wyrażenia lambda jako komparatora dla kolejki priorytetowej.
    auto compare = [](ListItem left, ListItem right) { return left.weight > right.weight; };
    vertexQueue = minQueue(compare);
    //Alokujemy pamięć dla odpowiednich tablic.
    distance = new int[size];
    predeccesor = new int[size];
}

Dijkstra::~Dijkstra()
{
    //Dealokujemy tablice dynamiczne.
    delete[] distance;
    delete[] predeccesor;
}

void Dijkstra::proccessMatrix(AdjacencyMatrix * graph, int startingVertex)
{
    //Wektor pomocniczy służący do ułatwienia aktualizacji kolejki priorytetowej.
    std::vector<int> completedVertices;
    for (int i = 0; i < graph->getSize(); i++)
    {
        //Dla każdego wierzchołka ustawiamy odległość na nieskończoność.
        distance[i] = INT_MAX;
        //Poprzednik jest niezdefiniowany.
        predeccesor[i] = -1;
    }

    //Wierzchołek startowy ma odległość równą zero.
    distance[startingVertex] = 0;
    //Wypełniamy kolejkę priorytetową.
    updateQueue(graph->getSize(), completedVertices);

    while (!vertexQueue.empty())
    {
        //Dopóki kolejka nie jest pusta, usuwamy wierzchołek o najniższym priorytecie.
        auto item = vertexQueue.top();
        vertexQueue.pop();
        //Dla każdego sąsiada wykonujemy relaksację krawędzi.
        for (int i = 0; i < graph->getSize(); i++)
        {
            int weight = graph->findEdge(item.vertex, i);
            if (weight != 0)
            {
                if (distance[item.vertex] + weight < distance[i])
                {
                    distance[i] = distance[item.vertex] + weight;
                    predeccesor[i] = item.vertex;
                }
            }
        }
        //Aktualizujemy kolejkę priorytetową.
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
            int weight = graph->findEdge(item.vertex, i);
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
        //Dla każdego wierzchołka sprawdzamy czy nie został już przetworzony.
        if (!Utility::contains(completedVertices, i))
        {
            //Jeśli nie, dodajemy go do kolejki.
            ListItem item { i, distance[i] };
            vertexQueue.push(item);
        }
    }
}

int * Dijkstra::getDistanceArray()
{
    return distance;
}

int * Dijkstra::getPredeccesorArray()
{
    return predeccesor;
}
