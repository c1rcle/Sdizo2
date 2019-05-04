cmake_minimum_required(VERSION 3.13)
project(Projekt2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Projekt2 Menu/Menu.h Menu/Menu.cpp Menu/MenuItem.h Test/Measurement.h Test/Measurement.cpp main.cpp Dijkstra/Dijkstra.h Dijkstra/Dijkstra.cpp Graphs/AdjacencyMatrix.h Graphs/AdjacencyList.h Graphs/AdjacencyMatrix.cpp Graphs/AdjacencyList.cpp FordBellman/FordBellman.cpp FordBellman/FordBellman.h Menu/Submenus/ShortestPathItem.h Menu/Submenus/MinimumSpanningItem.h Menu/Submenus/ShortestPathItem.cpp Menu/Submenus/MinimumSpanningItem.cpp Prim/Prim.h Prim/Prim.cpp Utility/Utility.h Kruskal/Kruskal.h Kruskal/Kruskal.cpp)