#include <iostream>
#include "dijkstra.hpp"

int main() {
    int V;
    std::cout << "Enter the number of vertices in the graph: ";
    std::cin >> V;

    Dijkstra dijkstra;
    dijkstra.initialize(static_cast<size_t>(V));
    dijkstra.readGraph();
    dijkstra.shortestPath();

    return 0;
}
