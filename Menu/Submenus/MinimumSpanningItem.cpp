#include "MinimumSpanningItem.h"

MinimumSpanningItem::MinimumSpanningItem()
{
    //Ustawiamy zmienne definiujące opis submenu.
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
    std::cout << "6. Testuj (test)" << std::endl;
    std::cout << "7. Wróć (back)" << std::endl;
    std::cout << "Wybierz opcję: ";
}

void MinimumSpanningItem::processInput()
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
        else if (readConsole == "prim") executeFirst();
        else if (readConsole == "krus") executeSecond();
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

void MinimumSpanningItem::loadFile()
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
        matrix = new AdjacencyMatrix(vertexCount);
        list = new AdjacencyList(vertexCount);

        for (int i = 0; i < edgeCount; i++)
        {
            int start, end, weight;
            file >> start >> end >> weight;
            matrix->addEdge(start, end, weight);
            matrix->addEdge(end, start, weight);
            list->addEdge(start, end, weight);
            list->addEdge(end, start, weight);
        }
        display();
    }
    else std::cout << "Podana nazwa pliku jest nieprawidłowa!" << std::endl;
    file.close();
}

void MinimumSpanningItem::createRandom()
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

    //Maksymalna ilość wierzchołków to suma ciągu arytmetycznego an = n.
    int maxEdges = static_cast<int>(density / 100.0f * (((vertexCount + 1) / 2.0f) * vertexCount));
    int edgeCount = 0;
    //Generujemy drzewo rozpinające.
    for (int i = 0; i < vertexCount - 1; i++)
    {
        //Dla problemu minimalnego drzewa rozpinającego krawędzie są nieskierowane.
        int weight = (rand() % maxEdges) + 1;
        matrix->addEdge(i, i + 1, weight);
        matrix->addEdge(i + 1, i, weight);

        list->addEdge(i, i + 1, weight);
        list->addEdge(i + 1, i, weight);
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
            matrix->addEdge(end, start, weight);

            list->addEdge(start, end, weight);
            list->addEdge(end, start, weight);
            edgeCount++;
        }
    }
}

void MinimumSpanningItem::display()
{
    //Wyświetla obie reprezentacje.
    if (matrix != nullptr && list != nullptr)
    {
        std::cout << "\nMacierz sąsiedztwa:" << std::endl;
        matrix->display();
        std::cout << "Lista sąsiedztwa:"<< std::endl;
        list->display();
    }
    else std::cout << "\nGraf jest pusty!" << std::endl;
}

void MinimumSpanningItem::executeFirst()
{
    //Wykonuje algorytm Prima dla obu reprezentacji grafu.
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
    //Wykonuje algorytm Kruskala dla obu reprezentacji grafu.
    if (matrix == nullptr || list == nullptr)
    {
        std::cout << "\nGraf jest pusty!" << std::endl;
        return;
    }

    auto * kruskal = new Kruskal();
    kruskal->proccessMatrix(matrix);
    std::cout << "\nMacierz sąsiedztwa: " << std::endl;
    displayAlgorithmResult(kruskal->getEdgeList());
    kruskal->resetContainers();

    kruskal->proccessList(list);
    std::cout << "\nLista sąsiedztwa: " << std::endl;
    displayAlgorithmResult(kruskal->getEdgeList());
    kruskal->resetContainers();
    delete kruskal;
}

void MinimumSpanningItem::test()
{
    auto * test = new MinimumSpanningTest();
    test->executionTestAverage();
    delete test;
}


void MinimumSpanningItem::displayAlgorithmResult(std::list<Edge> &edgeList)
{
    //Wyświetla wynik działania algorytmu (w obu przypadkach lista krawędzi należących do MST).
    int mstWeight = 0;
    std::cout << "Krawędzie należące do MST: " << std::endl;
    for (auto item : edgeList)
    {
        std::cout << item.start << ", " << item.end << ", waga: " << item.weight << std::endl;
        mstWeight += item.weight;
    }
    std::cout << "Waga drzewa wynosi: " << mstWeight << std::endl;
}