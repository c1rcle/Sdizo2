#include "ShortestPathItem.h"

ShortestPathItem::ShortestPathItem()
{
    //Ustawiamy zmienne definiujące opis submenu.
    menuDescription = "Problem najkrótszej ścieżki (path)";
    menuCommand = "path";
}

void ShortestPathItem::printMenu()
{
    //Wypisanie menu dla problemu najkrótszej ścieżki.
    std::cout << std::endl;
    std::cout << "Menu dla problemu najkrótszej ścieżki" << std::endl;
    std::cout << "1. Wczytaj graf z pliku (load)" << std::endl;
    std::cout << "2. Stwórz losowy graf (rand)" << std::endl;
    std::cout << "3. Wyświetl (disp)" << std::endl;
    std::cout << "4. Algorytm Dijkstry (dijk)" << std::endl;
    std::cout << "5. Algorytm Forda-Bellmana (ford)" << std::endl;
    std::cout << "6. Testuj (test)" << std::endl;
    std::cout << "7. Wróć (back)" << std::endl;
    std::cout << "Wybierz opcję: ";
}

void ShortestPathItem::processInput()
{
    //Wchodzimy do pętli obsługi opcji.
    std::string readConsole;
    backTyped = false;
    while (!backTyped)
    {
        printMenu();
        std::cin >> readConsole;
        if (readConsole == "load") loadFile();
        else if (readConsole == "rand") createRandom();
        else if (readConsole == "disp") display();
        else if (readConsole == "dijk") executeFirst();
        else if (readConsole == "ford") executeSecond();
        else if (readConsole == "test") test();
        else if (readConsole == "back") backTyped = true;
        else std::cout << "Nieznane polecenie!" << std::endl;
    }
    //Jeśli graf został stworzony, dealokujemy pamięć.
    if (matrix != nullptr && list != nullptr)
    {
        delete matrix;
        delete list;
    }
}

void ShortestPathItem::loadFile()
{
    //Standardowe wczytywanie z pliku.
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
        file >> startingVertex;
        matrix = new AdjacencyMatrix(vertexCount);
        list = new AdjacencyList(vertexCount);

        for (int i = 0; i < edgeCount; i++)
        {
            int start, end, weight;
            file >> start >> end >> weight;
            matrix->addEdge(start, end, weight);
            list->addEdge(start, end, weight);
        }
        display();
    }
    else std::cout << "Podana nazwa pliku jest nieprawidłowa!" << std::endl;
    file.close();
}

void ShortestPathItem::createRandom()
{
    //Wczytujemy parametry generowanego grafu od użytkownika.
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

    startingVertex = rand() % vertexCount;
    int maxEdges = static_cast<int>(density / 100.0f * (vertexCount * vertexCount));
    int edgeCount = 0;
    //Generujemy drzewo rozpinające.
    for (int i = 0; i < vertexCount; i++)
    {
        if (i == startingVertex) continue;
        int weight = (rand() % maxEdges) + 1;
        matrix->addEdge(startingVertex, i, weight);
        list->addEdge(startingVertex, i, weight);
        edgeCount++;
    }

    //Dodajemy pozostałe krawędzie (zawsze zostanie wygenerowane chociaż drzewo rozpinające).
    while (edgeCount < maxEdges)
    {
        int start = rand() % vertexCount;
        int end = rand() % vertexCount;
        int weight = (rand() % maxEdges) + 1;

        if (matrix->findEdge(start, end) == 0)
        {
            matrix->addEdge(start, end, weight);
            list->addEdge(start, end, weight);
            edgeCount++;
        }
    }
}

void ShortestPathItem::display()
{
    //Wyświetla obie reprezentacje.
    if (matrix != nullptr && list != nullptr)
    {
        std::cout << "\nMacierz sąsiedztwa:" << std::endl;
        matrix->display();
        std::cout << "\nLista sąsiedztwa:"<< std::endl;
        list->display();
    }
    else std::cout << "\nGraf jest pusty!" << std::endl;
}

void ShortestPathItem::executeFirst()
{
    //Wykonuje algorytm Dijkstry dla obu reprezentacji grafu.
    if (matrix == nullptr || list == nullptr)
    {
        std::cout << "\nGraf jest pusty!" << std::endl;
        return;
    }

    auto * dijkstra = new Dijkstra(matrix->getSize());
    dijkstra->proccessMatrix(matrix, startingVertex);
    std::cout << "\nMacierz sąsiedztwa: " << std::endl;
    displayAlgorithmResult(dijkstra->getDistanceArray(), dijkstra->getPredeccesorArray());
    std::cout << std::endl;

    dijkstra->proccessList(list, startingVertex);
    std::cout << "Lista sąsiedztwa: " << std::endl;
    displayAlgorithmResult(dijkstra->getDistanceArray(), dijkstra->getPredeccesorArray());
    delete dijkstra;
}

void ShortestPathItem::executeSecond()
{
    //Wykonuje algorytm Forda-Bellmana dla obu reprezentacji grafu.
    if (matrix == nullptr || list == nullptr)
    {
        std::cout << "\nGraf jest pusty!" << std::endl;
        return;
    }

    auto * fordBellman = new FordBellman(matrix->getSize());
    fordBellman->proccessMatrix(matrix, startingVertex);
    std::cout << "\nMacierz sąsiedztwa: " << std::endl;
    displayAlgorithmResult(fordBellman->getDistanceArray(), fordBellman->getPredeccesorArray());
    std::cout << std::endl;

    fordBellman->proccessList(list, startingVertex);
    std::cout << "Lista sąsiedztwa: " << std::endl;
    displayAlgorithmResult(fordBellman->getDistanceArray(), fordBellman->getPredeccesorArray());
    delete fordBellman;
}

void ShortestPathItem::test()
{
    auto * test = new ShortestPathTest();
    test->executionTestAverage();
    delete test;
}

void ShortestPathItem::displayAlgorithmResult(int * distance, int * predeccesor)
{
    //Wyświetla wynik działania algorytmu (w obu przypadkach tablice odległości i poprzedników).
    std::string representation;
    std::string vertex;

    for (int i = 0; i < matrix->getSize(); i++)
    {
        if (distance[i] == INT_MAX) continue;
        int currentVertex = i;
        while (currentVertex != startingVertex)
        {
            vertex.insert(0, std::to_string(predeccesor[currentVertex]) + " -> ");
            currentVertex = predeccesor[currentVertex];
        }

        vertex.append(std::to_string(i));
        representation.append(std::to_string(i) + " (koszt = " + std::to_string(distance[i]) + "): ");
        representation.append(vertex + "\n");
        vertex = "";
    }
    std::cout << representation;
}