#include <iostream>
#include "dijkstra.hpp"

int main() {

    int V = 9;
    Dijkstra dijkstra;

    std::cout << "Enter the number of vertices in the graph: ";
    std::cin >> V;

    dijkstra.initialize(static_cast<size_t>(V));
    dijkstra.initialize(static_cast<size_t>(V));
    dijkstra.readGraph();
    dijkstra.shortestPath();

    return 0;
}
