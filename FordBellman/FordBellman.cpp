#include "FordBellman.h"

FordBellman::FordBellman(int size)
{
    distance = new int[size];
    predeccesor = new int[size];
}

FordBellman::~FordBellman()
{
    delete[] distance;
    delete[] predeccesor;
}

std::string FordBellman::proccessMatrix(AdjacencyMatrix * graph, int startingVertex)
{
    for (int i = 0; i < graph->getSize(); i++)
    {
        distance[i] = INT_MAX;
        predeccesor[i] = -1;
    }

    distance[startingVertex] = 0;
    for (int i = 0; i < graph->getSize(); i++)
    {
        for (int u = 0; u < graph->getSize(); u++)
        {
            for (int v = 0; v < graph->getSize(); v++)
            {
                int weight = graph->findVertex(u, v);
                if (weight != 0)
                {
                    if (distance[u] + weight < distance[v])
                    {
                        distance[v] = distance[u] + weight;
                        predeccesor[v] = u;
                    }
                }
            }
        }
    }

    std::string representation = "Droga: ";
    for (int i = 0; i < graph->getSize(); i++)
        representation.append(std::to_string(i) + "(" + std::to_string(distance[i]) + "), ");
    representation.erase(representation.size() - 2);

    representation.append("\nPoprzednicy: ");
    for (int i = 0; i < graph->getSize(); i++)
        representation.append(std::to_string(i) + "(" + std::to_string(predeccesor[i]) + "), ");
    representation.erase(representation.size() - 2);
    return representation;
}

std::string FordBellman::proccessList(AdjacencyList * graph, int startingVertex)
{
    for (int i = 0; i < graph->getSize(); i++)
    {
        distance[i] = INT_MAX;
        predeccesor[i] = -1;
    }

    distance[startingVertex] = 0;
    for (int i = 0; i < graph->getSize(); i++)
    {
        for (int u = 0; u < graph->getSize(); u++)
        {
            for (auto item : graph->getListForVertex(u))
            {
                if (distance[u] + item.weight < distance[item.vertex])
                {
                    distance[item.vertex] = distance[u] + item.weight;
                    predeccesor[item.vertex] = u;
                }
            }
        }
    }

    std::string representation = "Droga: ";
    for (int i = 0; i < graph->getSize(); i++)
        representation.append(std::to_string(i) + "(" + std::to_string(distance[i]) + "), ");
    representation.erase(representation.size() - 2);

    representation.append("\nPoprzednicy: ");
    for (int i = 0; i < graph->getSize(); i++)
        representation.append(std::to_string(i) + "(" + std::to_string(predeccesor[i]) + "), ");
    representation.erase(representation.size() - 2);
    return representation;
}

