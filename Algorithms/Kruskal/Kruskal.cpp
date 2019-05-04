#include "Kruskal.h"

Kruskal::Kruskal() = default;

Kruskal::~Kruskal() = default;

int Kruskal::find(Subset * subsets, int element)
{
    if (subsets[element].parent != element)
        subsets[element].parent = find(subsets, subsets[element].parent);
    return subsets[element].parent;
}

void Kruskal::setUnion(Subset * subsets, int first, int second)
{
    int firstRoot = find(subsets, first);
    int secondRoot = find(subsets, second);

    if (subsets[firstRoot].rank < subsets[secondRoot].rank)
        subsets[firstRoot].parent = secondRoot;
    else if (subsets[firstRoot].rank > subsets[secondRoot].rank)
        subsets[secondRoot].parent = firstRoot;
    else
    {
        subsets[secondRoot].parent = firstRoot;
        subsets[firstRoot].rank++;
    }
}

void Kruskal::proccessMatrix(AdjacencyMatrix * graph)
{
    std::vector<Edge> edgeVector;
    int diagonal = 1;
    for (int i = 0; i < graph->getSize(); i++)
    {
        for (int j = 0; j < diagonal; j++)
        {
            int weight = graph->findVertex(i, j);
            if (weight != 0)
            {
                Edge item = { i, j, weight };
                edgeVector.push_back(item);
            }
        }
        diagonal++;
    }

    std::sort(edgeVector.begin(), edgeVector.end());
    auto * subsets = new Subset[graph->getSize()];
    for (int i = 0; i < graph->getSize(); i++)
    {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    int edgeIndex = 0;
    while (edgeList.size() < graph->getSize() - 1)
    {
        Edge currentEdge = edgeVector[edgeIndex];
        edgeIndex++;

        int startSet = find(subsets, currentEdge.start);
        int endSet = find(subsets, currentEdge.end);
        if (startSet != endSet)
        {
            edgeList.push_back(currentEdge);
            setUnion(subsets, startSet, endSet);
        }
    }
    delete[] subsets;
}

void Kruskal::proccessList(AdjacencyList * graph)
{
    std::vector<Edge> edgeVector;
    for (int i = 0; i < graph->getSize(); i++)
    {
        std::list<ListItem> &row = graph->getListForVertex(i);
        for (auto edge : row)
        {
            Edge item = { i, edge.vertex, edge.weight };
            if (!Utility::containsEdge(edgeVector, item)) edgeVector.push_back(item);
        }
    }

    std::sort(edgeVector.begin(), edgeVector.end());
    auto * subsets = new Subset[graph->getSize()];
    for (int i = 0; i < graph->getSize(); i++)
    {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    int edgeIndex = 0;
    while (edgeList.size() < graph->getSize() - 1)
    {
        Edge currentEdge = edgeVector[edgeIndex];
        edgeIndex++;

        int startSet = find(subsets, currentEdge.start);
        int endSet = find(subsets, currentEdge.end);
        if (startSet != endSet)
        {
            edgeList.push_back(currentEdge);
            setUnion(subsets, startSet, endSet);
        }
    }
    delete[] subsets;
}

std::list<Edge> &Kruskal::getEdgeList()
{
    return edgeList;
}

void Kruskal::resetContainers()
{
    edgeList.clear();
}
