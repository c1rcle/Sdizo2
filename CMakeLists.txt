cmake_minimum_required(VERSION 3.13)
project(Projekt2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Projekt2 main.cpp Dijkstra/Dijkstra.h Dijkstra/Dijkstra.cpp Graphs/AdjacencyMatrix.h Graphs/AdjacencyList.h Graphs/AdjacencyMatrix.cpp Graphs/AdjacencyList.cpp FordBellman/FordBellman.cpp FordBellman/FordBellman.h)