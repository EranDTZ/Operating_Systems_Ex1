#include "dijkstra.hpp"

Graph::Graph(int vertices) : V(vertices), adjMatrix(vertices, std::vector<int>(vertices, 0)) {}

void Graph::addEdge(int src, int dest, int weight) {
    adjMatrix[src][dest] = weight;
    adjMatrix[dest][src] = weight; // Assuming undirected graph
}

void Graph::dijkstra(int src) {
    std::vector<int> dist(V, std::numeric_limits<int>::max());
    std::vector<bool> sptSet(V, false);

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && adjMatrix[u][v] && dist[u] != std::numeric_limits<int>::max() &&
                dist[u] + adjMatrix[u][v] < dist[v]) {
                dist[v] = dist[u] + adjMatrix[u][v];
            }
        }
    }

    printSolution(dist);
}

int Graph::minDistance(std::vector<int> &dist, std::vector<bool> &sptSet) {
    int min = std::numeric_limits<int>::max(), min_index;

    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void Graph::printSolution(std::vector<int> &dist) {
    std::cout << "Vertex \t\t Distance from Source\n";
    for (int i = 0; i < V; i++) {
        std::cout << i << "\t\t\t\t" << dist[i] << std::endl;
    }
}
