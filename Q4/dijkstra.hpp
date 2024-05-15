#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

class Graph {
private:
    int V;
    std::vector<std::vector<int>> adjMatrix;

public:
    Graph(int vertices);

    void addEdge(int src, int dest, int weight);

    void dijkstra(int src);

private:
    int minDistance(std::vector<int> &dist, std::vector<bool> &sptSet);

    void printSolution(std::vector<int> &dist);
};

#endif // DIJKSTRA_H
