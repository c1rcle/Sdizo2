#include <iostream>
#include <ctime>
#include "Menu/Menu.h"
#include "Dijkstra/Dijkstra.h"
#include "FordBellman/FordBellman.h"
#include "Menu/Submenus/ShortestPathItem.h"
#include "Menu/Submenus/MinimumSpanningItem.h"

int main()
{
    std::srand(std::time(nullptr));
    auto * menu = new Menu();
    auto * path = new ShortestPathItem();
    auto * mst = new MinimumSpanningItem();
    menu->addMenuItem(path);
    menu->addMenuItem(mst);
    menu->processInput();
    delete menu;
    return 0;
}