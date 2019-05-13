#include "AdjacencyMatrix.h"

AdjacencyMatrix::AdjacencyMatrix(int graphSize)
{
    //Alokujemy pamięć dla tablicy przechowującej informacje o grafie.
    this->graphSize = graphSize;
    base = new int[graphSize * graphSize];

    //Zerujemy tablicę.
    for (int i = 0; i < graphSize; i++)
        for (int j = 0; j < graphSize; j++)
            base[i * graphSize + j] = INT_MAX;
}

AdjacencyMatrix::~AdjacencyMatrix()
{
    delete[] base;
}

void AdjacencyMatrix::addEdge(int startVertex, int endVertex, int weight)
{
    try
    {
        base[startVertex * graphSize + endVertex] = weight;
    }
    catch (std::out_of_range&)
    {
        throw std::invalid_argument(EXCEPTION_DESC);
    }
}

void AdjacencyMatrix::removeEdge(int startVertex, int endVertex)
{
    try
    {
        //Brak krawędzi to 'INT_MAX' w macierzy sąsiedztwa.
        base[startVertex * graphSize + endVertex] = INT_MAX;
    }
    catch (std::out_of_range&)
    {
        throw std::invalid_argument(EXCEPTION_DESC);
    }
}

int AdjacencyMatrix::findEdge(int startVertex, int endVertex)
{
    int value;
    try
    {
        //Zwracamy wagę krawędzi dla danych wierzchołków.
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
    //Ilość wierzchołków grafu.
    return graphSize;
}

void AdjacencyMatrix::display()
{
    //Obliczamy ilość cyfr potrzebną do zapisania danej liczby.
    int padding = ceil(std::log10(graphSize * graphSize));
    for (int i = 0; i < graphSize; i++)
    {
        for (int j = 0; j < graphSize; j++)
        {
            int value = base[i * graphSize + j];
            if (value == INT_MAX) value = 0;
            //Wyrównujemy do lewej na podstawie maksymalnej wielkości.
            std::cout << std::setw(padding) << value << ' ';
        }
        std::cout << "\n";
    }
}