#pragma once

#include "Graph.h"
#include <memory>
#include <vector>
#include <limits>

class ShortestPathManager {
private:
    std::shared_ptr<IGraph> graph;
    std::vector<int> d;
    std::vector<bool> visited;
    std::vector<bool> banned;
    int startVertex;
    int endVertex;
    std::pair<int, std::vector<int>> length_path_of_two_vertices;

    std::pair<int, std::vector<int>> __getShortestPath(int startVertex, int endVertex);

public:
    ShortestPathManager(std::shared_ptr<IGraph> graph, int startVertex, int endVertex);

    std::pair<int, std::vector<int>> getShortestPath();
    std::pair<int, std::vector<int>> getNextShortestPath();
};

