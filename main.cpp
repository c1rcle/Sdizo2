#include <iostream>
#include <ctime>
#include "Menu/Menu.h"
#include "Dijkstra/Dijkstra.h"
#include "FordBellman/FordBellman.h"
#include "Menu/Submenus/ShortestPathItem.h"

int main()
{
    std::srand(std::time(nullptr));
    auto * menu = new Menu();
    auto * path = new ShortestPathItem();
    menu->addMenuItem(path);
    menu->processInput();
    delete menu;
    return 0;
}