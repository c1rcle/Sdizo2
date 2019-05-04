#include "MinimumSpanningItem.h"

MinimumSpanningItem::MinimumSpanningItem()
{
    menuDescription = "Problem minimalnego drzewa rozpinającego (mst)";
    menuCommand = "mst";
}

void MinimumSpanningItem::printMenu()
{
    //Wypisanie menu dla problemu najkrótszej ścieżki.
    std::cout << std::endl;
    std::cout << "Menu dla problemu minimalnego drzewa rozpinającego" << std::endl;
    std::cout << "1. Wczytaj graf z pliku (load)" << std::endl;
    std::cout << "2. Stwórz losowy graf (rand)" << std::endl;
    std::cout << "3. Wyświetl (disp)" << std::endl;
    std::cout << "4. Algorytm Prima (prim)" << std::endl;
    std::cout << "5. Algorytm Kruskala (krus)" << std::endl;
    std::cout << "6. Wróć (back)" << std::endl;
    std::cout << "Wybierz opcję: ";
}

void MinimumSpanningItem::processInput()
{
    std::string readConsole;
    backTyped = false;
    while (!backTyped)
    {
        printMenu();
        std::cin >> readConsole;
        if (readConsole == "load") loadFile();
        else if (readConsole == "rand") createRandom();
        else if (readConsole == "disp") display();
        else if (readConsole == "prim") executeFirst();
        else if (readConsole == "krus") executeSecond();
        else if (readConsole == "back") backTyped = true;
        else std::cout << "Nieznane polecenie!" << std::endl;
    }
    if (matrix != nullptr && list != nullptr)
    {
        delete matrix;
        delete list;
    }
}

void MinimumSpanningItem::loadFile()
{
    std::string filename;
    int edgeCount, vertexCount;
    std::cout << "\nPodaj nazwę pliku: ";
    std::cin >> filename;
    std::ifstream file;
    file.open(filename);

    if (file.is_open())
    {
        if (matrix != nullptr && list != nullptr)
        {
            delete matrix;
            delete list;
        }

        file >> edgeCount;
        file >> vertexCount;
        matrix = new AdjacencyMatrix(vertexCount);
        list = new AdjacencyList(vertexCount);

        for (int i = 0; i < edgeCount; i++)
        {
            int start, end, weight;
            file >> start >> end >> weight;
            matrix->addVertex(start, end, weight);
            matrix->addVertex(end, start, weight);
            list->addVertex(start, end, weight);
            list->addVertex(end, start, weight);
        }
        display();
    }
    else std::cout << "Podana nazwa pliku jest nieprawidłowa!" << std::endl;
    file.close();
}

void MinimumSpanningItem::createRandom()
{
    int vertexCount, density;
    std::cout << "\nPodaj liczbę wierzchołków grafu: ";
    std::cin >> vertexCount;
    std::cout << "Podaj gęstość grafu (w %): ";
    std::cin >> density;

    if (matrix != nullptr && list != nullptr)
    {
        delete matrix;
        delete list;
    }
    matrix = new AdjacencyMatrix(vertexCount);
    list = new AdjacencyList(vertexCount);

    int maxEdges = static_cast<int>(density / 100.0f * (vertexCount * vertexCount));
    int edgeCount = 0;
    while (edgeCount < maxEdges)
    {
        int start = rand() % vertexCount;
        int end = rand() % vertexCount;
        int weight = (rand() % maxEdges) + 1;

        if (matrix->findVertex(start, end) == 0)
        {
            matrix->addVertex(start, end, weight);
            list->addVertex(start, end, weight);
            edgeCount++;
        }
    }
}

void MinimumSpanningItem::display()
{
    if (matrix != nullptr && list != nullptr)
    {
        std::cout << "\nMacierz sąsiedztwa:" << std::endl;
        std::cout << matrix->toString() << std::endl;
        std::cout << "Lista sąsiedztwa:"<< std::endl;
        std::cout << list->toString();
    }
    else std::cout << "\nGraf jest pusty!" << std::endl;
}

void MinimumSpanningItem::executeFirst()
{
    if (matrix == nullptr || list == nullptr)
    {
        std::cout << "\nGraf jest pusty!" << std::endl;
        return;
    }

    auto * prim = new Prim();
    prim->proccessMatrix(matrix);
    std::cout << "\nMacierz sąsiedztwa: " << std::endl;
    displayAlgorithmResult(prim->getEdgeList());
    prim->resetContainers();

    prim->proccessList(list);
    std::cout << "\nLista sąsiedztwa: " << std::endl;
    displayAlgorithmResult(prim->getEdgeList());
    prim->resetContainers();
    delete prim;
}

void MinimumSpanningItem::executeSecond()
{

}

void MinimumSpanningItem::displayAlgorithmResult(std::list<Edge> &edgeList)
{
    int mstWeight = 0;
    std::cout << "Krawędzie należące do MST: " << std::endl;
    for (auto item : edgeList)
    {
        std::cout << item.start << ", " << item.end << ", waga: " << item.weight << std::endl;
        mstWeight += item.weight;
    }
    std::cout << "Waga drzewa wynosi: " << mstWeight << std::endl;
}