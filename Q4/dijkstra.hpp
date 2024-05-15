#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include <vector>
#include <climits> // כותרת נוספת

class Dijkstra {
public:
    Dijkstra();
    void initialize(std::vector<std::vector<int>>::size_type V); // שינוי כאן
    void readGraph();
    void shortestPath();
private:
    int minDistance(const std::vector<int>& dist, const std::vector<bool>& sptSet);
    void printSolution(const std::vector<int>& dist);
    std::vector<std::vector<int>> graph;
};

#endif /* DIJKSTRA_HPP */
