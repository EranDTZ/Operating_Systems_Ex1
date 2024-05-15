#include "dijkstra.hpp"

int main() {
    int V;
    std::cout << "Enter the number of vertices in the graph: ";
    std::cin >> V;

    Graph graph(V);

    std::cout << "Enter the adjacency matrix for the graph (" << V << " x " << V << "):\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            std::cin >> graph.adjMatrix[i][j];
        }
    }

    int source;
    std::cout << "Enter the source vertex (0 to " << V - 1 << "): ";
    std::cin >> source;

    if (source < 0 || source >= V) {
        std::cout << "Invalid source vertex." << std::endl;
    } else {
        graph.dijkstra(source);
    }

    return 0;
}
