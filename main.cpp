#include <iostream>
#include <ctime>
#include "Menu/Menu.h"
#include "Dijkstra/Dijkstra.h"
#include "FordBellman/FordBellman.h"

int main()
{
    std::srand(std::time(nullptr));
    auto * matrix = new AdjacencyMatrix(6);
    matrix->addVertex(0, 1, 3);
    matrix->addVertex(0, 4, 3);
    matrix->addVertex(1, 2, 1);
    matrix->addVertex(2, 3, 3);
    matrix->addVertex(2, 5, 1);
    matrix->addVertex(3, 1, 3);
    matrix->addVertex(4, 5, 2);
    matrix->addVertex(5, 0, 6);
    matrix->addVertex(5, 3, 1);

    auto * list = new AdjacencyList(6);
    list->addVertex(0, 1, 3);
    list->addVertex(0, 4, 3);
    list->addVertex(1, 2, 1);
    list->addVertex(2, 3, 3);
    list->addVertex(2, 5, 1);
    list->addVertex(3, 1, 3);
    list->addVertex(4, 5, 2);
    list->addVertex(5, 0, 6);
    list->addVertex(5, 3, 1);
    auto * dijkstra = new Dijkstra(matrix->getSize());
    auto * bellman = new FordBellman(matrix->getSize());
    std::cout << dijkstra->proccessMatrix(matrix, 0) << std::endl;
    std::cout << dijkstra->proccessList(list, 0) << std::endl;
    std::cout << bellman->proccessMatrix(matrix, 0) << std::endl;
    std::cout << bellman->proccessList(list, 0) << std::endl;
    delete dijkstra;
    delete bellman;
    delete matrix;
    delete list;
    return 0;
}