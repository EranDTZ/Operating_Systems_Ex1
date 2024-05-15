#include "dijkstra.hpp"
#include <iostream>
#include <climits> // כותרת נוספת

Dijkstra::Dijkstra() {}

void Dijkstra::initialize(std::vector<std::vector<int>>::size_type V) {
    this->graph.resize(V, std::vector<int>(V));
}

void Dijkstra::readGraph() {
    std::cout << "Enter the adjacency matrix of the graph:\n";
    for (std::vector<int>::size_type i = 0; i < graph.size(); i++) {
        for (std::vector<int>::size_type j = 0; j < graph[i].size(); j++) {
            std::cin >> graph[i][j];
        }
    }
}

int Dijkstra::minDistance(const std::vector<int>& dist, const std::vector<bool>& sptSet) {
    int min = INT_MAX, min_index;

    for (std::vector<int>::size_type v = 0; v < graph.size(); v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void Dijkstra::printSolution(const std::vector<int>& dist) {
    std::cout << "Vertex \t\t Distance from Source\n";
    for (std::vector<int>::size_type i = 0; i < graph.size(); i++)
        std::cout << i << "\t\t\t\t" << dist[i] << "\n";
}

void Dijkstra::shortestPath() {
    std::vector<int> dist(graph.size(), INT_MAX);
    std::vector<bool> sptSet(graph.size(), false);

    // Distance of source vertex from itself is always 0
    dist[0] = 0;

    // Find shortest path for all vertices
    for (std::vector<int>::size_type count = 0; count < graph.size() - 1; count++) {
        // Pick the minimum distance vertex from the set of
        // vertices not yet processed. u is always equal to
        // src in the first iteration.
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[static_cast<size_t>(u)] = true;

        // Update dist value of the adjacent vertices of the
        // picked vertex.
        for (std::vector<int>::size_type v = 0; v < graph.size(); v++)

            // Update dist[v] only if is not in sptSet,
            // there is an edge from u to v, and total
            // weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && graph[static_cast<size_t>(u)][v]
                && dist[static_cast<size_t>(u)] != INT_MAX
                && dist[static_cast<size_t>(u)] + graph[static_cast<size_t>(u)][v] < dist[v])
                dist[v] = dist[static_cast<size_t>(u)] + graph[static_cast<size_t>(u)][v];
    }

    // print the constructed distance array
    printSolution(dist);
}
