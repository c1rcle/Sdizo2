#include "AdjacencyMatrix.h"

AdjacencyMatrix::AdjacencyMatrix(int graphSize)
{
    //Alokujemy pamięć dla tablicy przechowującej informacje o grafie.
    this->graphSize = graphSize;
    base = new int[graphSize * graphSize];

    //Zerujemy tablicę.
    for (int i = 0; i < graphSize; i++)
        for (int j = 0; j < graphSize; j++)
            base[i * graphSize + j] = 0;
}

AdjacencyMatrix::~AdjacencyMatrix()
{
    delete[] base;
}

void AdjacencyMatrix::addEdge(int startVertex, int endVertex, int weight)
{
    //Dodajemy nową krawędź jeśli waga jest większa lub równa 1.
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

void AdjacencyMatrix::removeEdge(int startVertex, int endVertex)
{
    try
    {
        //Brak krawędzi to '0' w macierzy sąsiedztwa.
        base[startVertex * graphSize + endVertex] = 0;
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
            //Wyrównujemy do lewej na podstawie maksymalnej wielkości.
            std::cout << std::setw(padding) << base[i * graphSize + j] << ' ';
        }
        std::cout << "\n";
    }
}