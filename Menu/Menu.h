#include <iostream>
#include <vector>
#include "MenuItem.h"

/// Klasa dla głównego menu programu.
class Menu
{
private:
    /// Kontener przechowujący kolejne submenu.
    std::vector<MenuItem *> items;
    /// Zmienna przechowująca informację o wybraniu komendy zakończenia programu.
    bool quitTyped = false;
    /// Zmienna przechowująca informację o nierozpoznaniu komendy programu.
    bool unknownInput = true;
    /// Wypisuje menu dla podanych submenu.
    void printMenu();
public:
    /// Konstruktor klasy menu.
    Menu();
    /// Destruktor klasy menu.
    ~Menu();
    /// Dodaje nowe submenu do kontenera.
    /// \param item - wskaźnik na obiekt klasy abstrakcyjnej MenuItem.
    void addMenuItem(MenuItem * item);
    /// Obsługuje pętlę komend.
    void processInput();
};