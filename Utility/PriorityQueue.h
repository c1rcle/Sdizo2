#pragma once
#include <iostream>
#include <vector>

/// Klasa generyczna kolejki priorytetowej (wymaga implementacji odpowiednich operatorów).
/// \tparam T - klasa, która jest typem obiektów przechowywanych w kolejce.
template<class T>
class PriorityQueue
{
private:
    /// Stała opisująca wyjątek.
    const std::string EXCEPTION_DESC = "Kopiec jest pusty!";
    /// Wektor elementów kolejki priorytetowej.
    std::vector<T> base;
    /// Ilość wierzchołków kopca.
    int vertexCount;
    /// Naprawia kopiec w górę od zadanego indexu.
    /// \param index - indeks startowy.
    void heapFixUp(int index);
    /// Naprawia kopiec w dół od zadanego indexu.
    /// \param index - indeks startowy.
    void heapFixDown(int index);
public:
    /// Konstruktor klasy PriorityQueue.
    explicit PriorityQueue();
    /// Destruktor klasy PriorityQueue.
    ~PriorityQueue();
    /// Dodaje element do kolejki priorytetowej.
    /// \param element - nowy element.
    void insert(T element);
    /// Zamienia wartość elementu 'existing', który znajduje się w kolejce na 'newValue' i aktualizuje kopiec.
    /// \param existing - element do wyszukania.
    /// \param newValue - element do zamiany.
    void updateQueue(T existing, T newValue);
    /// Znajduje dany element w kolejce, usuwa go i następnie przywraca własności kopca.
    /// \param element - element do usunięcia.
    void updateAndDelete(T element);
    /// Zwraca referencję do kontenera kolejki.
    /// \return referencja do kontenera kolejki.
    std::vector<T> &getContainer();
    /// Ściąga minimalny element, usuwa go z kopca oraz przywraca jego własności.
    /// \return minimalny element znajdujący się w kopcu.
    T pop();
    /// Czyści kolejkę.
    void clear();
    /// Sprawdza czy kolejka jest pusta.
    bool isEmpty();
};

template<class T>
PriorityQueue<T>::PriorityQueue()
{
    vertexCount = 0;
}

template<class T>
PriorityQueue<T>::~PriorityQueue() = default;

template<class T>
void PriorityQueue<T>::insert(T element)
{
    //Standardowe dodanie elementu do kopca.
    int index = vertexCount;
    vertexCount++;
    base.push_back(element);
    heapFixUp(index);
}

template<class T>
void PriorityQueue<T>::updateQueue(T existing, T newValue)
{
    for (int i = 0; i < vertexCount; i++)
    {
        //Jeśli element zostanie znaleziony, zamieniamy wartość i aktualizujemy kopiec.
        if (base[i] == existing)
        {
            base[i] = newValue;
            if (i == 0)
            {
                heapFixDown(0);
                return;
            }
            T parent = base[(i - 1) / 2];
            if (base[i] < parent) heapFixUp(i);
            else heapFixDown(i);
            return;
        }
    }
}

template<class T>
void PriorityQueue<T>::updateAndDelete(T element)
{
    for (int i = 0; i < vertexCount; i++)
    {
        //Jeśli element zostanie znaleziony, usuwamy go z kopca.
        if (base[i] == element)
        {
            if (i == 0)
            {
                pop();
                return;
            }
            vertexCount--;
            base[i] = base[vertexCount];
            base.erase(base.begin() + vertexCount);
            T parent = base[(i - 1) / 2];
            if (base[i] < parent) heapFixUp(i);
            else heapFixDown(i);
            return;
        }
    }
}

template<class T>
std::vector<T> &PriorityQueue<T>::getContainer()
{
    return base;
}

template<class T>
T PriorityQueue<T>::pop()
{
    if (vertexCount == 0) throw std::length_error(EXCEPTION_DESC);
    vertexCount--;

    //Zapisujemy wartość szczytu kopca i usuwamy go.
    T root = base[0];
    base[0] = base[vertexCount];
    base.erase(base.begin() + vertexCount);
    heapFixDown(0);
    return root;
}

template<class T>
void PriorityQueue<T>::heapFixUp(int index)
{
    //Standardowa naprawa kopca w górę.
    int parent = (index - 1) / 2;
    T fixVertex = base[index];
    while (index > 0 && base[parent] > fixVertex)
    {
        T temp = base[index];
        base[index] = base[parent];
        base[parent] = temp;
        index = parent;
        parent = (index - 1) / 2;
    }
}

template<class T>
void PriorityQueue<T>::heapFixDown(int index)
{
    //Standardowa naprawa kopca w dół.
    T fixVertex = base[index];
    int greaterChildren = 2 * index + 1;
    while (greaterChildren < vertexCount)
    {
        if (greaterChildren + 1 < vertexCount && base[greaterChildren] > base[greaterChildren + 1]) greaterChildren++;
        if (fixVertex <= base[greaterChildren]) break;
        T temp = base[index];
        base[index] = base[greaterChildren];
        base[greaterChildren] = temp;
        index = greaterChildren;
        greaterChildren = 2 * greaterChildren + 1;
    }
}

template<class T>
void PriorityQueue<T>::clear()
{
    base.clear();
    vertexCount = 0;
}

template<class T>
bool PriorityQueue<T>::isEmpty()
{
    return vertexCount == 0;
}