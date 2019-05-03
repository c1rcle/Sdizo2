#pragma once
#include <fstream>
#include <ctime>
#include <chrono>
#include <vector>

/// Klasa abstrakcyjna reprezentująca submenu.
class MenuItem
{
protected:
    /// Zmienna przechowująca informację o wybraniu komendy powrotu do głównego menu.
    bool backTyped = false;
    /// Zmienna przechowująca informację opisu danego submenu.
    std::string menuDescription;
    /// Zmienna przechowująca komendę dla wywołania danego submenu.
    std::string menuCommand;
    /// Wyświetla dane submenu (pure virtual).
    virtual void printMenu() = 0;
public:
    /// Destruktor wirtualny klasy submenu.
    virtual ~MenuItem() = default;
    /// Obsługuje pętlę komend dla danego submenu.
    virtual void processInput() = 0;
    /// Zwraca opis danego submenu.
    /// \return Opis submenu.
    std::string getMenuDescription() { return menuDescription; }
    /// Zwraca komendę dla wywołanie danego submenu.
    /// \return Komenda dla wywołania submenu.
    std::string getMenuCommand() { return menuCommand; }
};
