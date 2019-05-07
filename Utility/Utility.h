#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include "Edge.h"

/// Klasa statyczna, która zawiera funkcje pomocnicze.
class Utility
{
public:
    /// Sprawdza czy dana wartość występuje w liście.
    /// \param list - lista dla której będzie wykonana operacja.
    /// \param x - szukana wartość.
    /// \return true jeśli została znaleziona, false - w przeciwnym wypadku.
    static bool contains(std::list<int> &list, int x)
    {
        return std::find(list.begin(), list.end(), x) != list.end();
    }
    /// Sprawdza czy lista krawędzi nie zawiera podanej.
    /// \param edgeList - lista krawędzi.
    /// \param edge - krawędź do znalezienia.
    /// \return true jeśli zostanie odnaleziona, w przeciwnym wypadku false.
    static bool containsEdge(std::list<Edge> &edgeList, Edge &edge)
    {
        return std::find(edgeList.begin(), edgeList.end(), edge) != edgeList.end();
    }
    /// Sprawdza czy wektor krawędzi nie zawiera podanej.
    /// \param edgeList - wektor krawędzi.
    /// \param edge - krawędź do znalezienia.
    /// \return true jeśli zostanie odnaleziona, w przeciwnym wypadku false.
    static bool containsEdge(std::vector<Edge> &edgeVector, Edge &edge)
    {
        return std::find(edgeVector.begin(), edgeVector.end(), edge) != edgeVector.end();
    }
};