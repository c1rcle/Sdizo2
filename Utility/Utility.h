#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

class Utility
{
public:
    /// Sprawdza czy dana wartość występuje w wektorze.
    /// \param vector - wektor dla którego będzie wykonana operacja.
    /// \param x - szukana wartość.
    /// \return true jeśli została znaleziona, false - w przeciwnym wypadku.
    static bool contains(std::vector<int> &vector, int x)
    {
        return std::find(vector.begin(), vector.end(), x) != vector.end();
    }
    /// Sprawdza czy dana wartość występuje w liście.
    /// \param list - lista dla której będzie wykonana operacja.
    /// \param x - szukana wartość.
    /// \return true jeśli została znaleziona, false - w przeciwnym wypadku.
    static bool contains(std::list<int> &list, int x)
    {
        return std::find(list.begin(), list.end(), x) != list.end();
    }
};