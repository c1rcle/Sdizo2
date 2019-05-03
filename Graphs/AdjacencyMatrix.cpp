#include "AdjacencyMatrix.h"

AdjacencyMatrix::AdjacencyMatrix(int graphSize)
{
    this->graphSize = graphSize;
    base = new int[graphSize * graphSize];

    for (int i = 0; i < graphSize; i++)
        for (int j = 0; j < graphSize; j++)
            base[i * graphSize + j] = 0;
}

AdjacencyMatrix::~AdjacencyMatrix()
{
    delete[] base;
}

void AdjacencyMatrix::addVertex(int startVertex, int endVertex, int weight)
{
    if (weight < 1) throw std::invalid_argument(EXCEPTION_DESC);
    try
    {
        base[startVertex * graphSize + endVertex] = weight;
    }
    catch (std::out_of_range&)
    {
        throw std::invalid_argument(EXCEPTION_DESC);
    }
}

void AdjacencyMatrix::removeVertex(int startVertex, int endVertex)
{
    try
    {
        base[startVertex * graphSize + endVertex] = 0;
    }
    catch (std::out_of_range&)
    {
        throw std::invalid_argument(EXCEPTION_DESC);
    }
}

int AdjacencyMatrix::findVertex(int startVertex, int endVertex)
{
    int value;
    try
    {
        value = base[startVertex * graphSize + endVertex];
    }
    catch (std::out_of_range&)
    {
        throw std::invalid_argument(EXCEPTION_DESC);
    }
    return value;
}

int AdjacencyMatrix::getSize()
{
    return graphSize;
}

std::string AdjacencyMatrix::toString()
{
    std::string representation;
    int padding = floor(std::log10(graphSize * graphSize));
    for (int i = 0; i < graphSize; i++)
    {
        for (int j = 0; j < graphSize; j++)
        {
            std::string currentWeight = std::to_string(base[i * graphSize + j]);
            currentWeight.insert(0, padding - currentWeight.size(), ' ');
            representation.append(currentWeight + " ");
        }
        representation.append("\n");
    }
    return representation;
}