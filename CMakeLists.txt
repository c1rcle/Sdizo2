cmake_minimum_required(VERSION 3.13)
project(Projekt2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Projekt2 Menu/Menu.h Menu/Menu.cpp Menu/MenuItem.h Test/Measurement.h Test/Measurement.cpp main.cpp Algorithms/Dijkstra/Dijkstra.h Algorithms/Dijkstra/Dijkstra.cpp Graphs/AdjacencyMatrix.h Graphs/AdjacencyList.h Graphs/AdjacencyMatrix.cpp Graphs/AdjacencyList.cpp Algorithms/FordBellman/FordBellman.cpp Algorithms/FordBellman/FordBellman.h Menu/Submenus/ShortestPathItem.h Menu/Submenus/MinimumSpanningItem.h Menu/Submenus/ShortestPathItem.cpp Menu/Submenus/MinimumSpanningItem.cpp Algorithms/Prim/Prim.h Algorithms/Prim/Prim.cpp Utility/Utility.h Algorithms/Kruskal/Kruskal.h Algorithms/Kruskal/Kruskal.cpp Utility/Edge.h Test/MinimumSpanningTest/MinimumSpanningTest.h Test/MinimumSpanningTest/MinimumSpanningTest.cpp Test/ShortestPathTest/ShortestPathTest.cpp Test/ShortestPathTest/ShortestPathTest.h)