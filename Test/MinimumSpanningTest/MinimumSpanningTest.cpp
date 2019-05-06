#include "MinimumSpanningTest.h"

MinimumSpanningTest::MinimumSpanningTest()
{
    matrix = nullptr;
    list = nullptr;
}

MinimumSpanningTest::~MinimumSpanningTest()
{
    if (matrix != nullptr && list != nullptr)
    {
        delete matrix;
        delete list;
    }
}

void MinimumSpanningTest::generateGraph(int vertexCount, int density)
{
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

TimeMeasurement MinimumSpanningTest::primTest(int vertexCount, int density, Prim * prim)
{
    TimeMeasurement timeMeasurement{};
    timeMeasurement.first = 0;
    timeMeasurement.second = 0;
    for (int i = 0; i < 10; i++)
    {
        generateGraph(vertexCount, density);
        measurement.startTimer();
        prim->proccessMatrix(matrix);
        measurement.stopTimer();
        timeMeasurement.first += measurement.getDuration();

        prim->resetContainers();
        measurement.startTimer();
        prim->proccessList(list);
        prim->resetContainers();
        measurement.stopTimer();
        timeMeasurement.second += measurement.getDuration();
    }

    timeMeasurement.first /= 10;
    timeMeasurement.second /= 10;
    return timeMeasurement;
}

TimeMeasurement MinimumSpanningTest::kruskalTest(int vertexCount, int density, Kruskal * kruskal)
{
    TimeMeasurement timeMeasurement{};
    timeMeasurement.first = 0;
    timeMeasurement.second = 0;
    for (int i = 0; i < 10; i++)
    {
        generateGraph(vertexCount, density);
        measurement.startTimer();
        kruskal->proccessMatrix(matrix);
        measurement.stopTimer();
        timeMeasurement.first += measurement.getDuration();

        kruskal->resetContainers();
        measurement.startTimer();
        kruskal->proccessList(list);
        kruskal->resetContainers();
        measurement.stopTimer();
        timeMeasurement.second += measurement.getDuration();
    }

    timeMeasurement.first /= 10;
    timeMeasurement.second /= 10;
    return timeMeasurement;
}

void MinimumSpanningTest::executionTestAverage()
{
    int vertexCounts[] = { 10, 20, 50, 100, 200 };
    int densities[] = { 20, 50, 75, 99 };
    std::ofstream file;
    file.open("mstResult.txt");
    if (file.is_open())
    {
        auto * prim = new Prim();
        for (auto count : vertexCounts)
        {
            for (auto density : densities)
            {
                auto time = primTest(count, density, prim);
                file << time.first << " " << time.second << "\n";
            }
        }
        delete prim;

        file << "\n";
        auto * kruskal = new Kruskal();
        for (auto count : vertexCounts)
        {
            for (auto density : densities)
            {
                auto time = kruskalTest(count, density, kruskal);
                file << time.first << " " << time.second << "\n";
            }
        }
        delete kruskal;
    }
    file.close();
}