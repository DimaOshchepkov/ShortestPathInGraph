#include "pch.h"
#include "framework.h"

#include <algorithm>
#include "ShortestPathManager.h"
#include "Graph.h"

using namespace std;

ShortestPathManager::ShortestPathManager(shared_ptr<IGraph> graph, int startVertex, int endVertex) :
    graph(graph), startVertex(startVertex), endVertex(endVertex),
    d(graph->countTop(), numeric_limits<int>::max()),
    visited(graph->countTop(), false),
    banned(graph->countTop(), false) {}

pair<int, vector<int>> ShortestPathManager::__getShortestPath(int startVertex, int endVertex) {
    const int SIZE = graph->countTop();
    
    d.assign(graph->countTop(), numeric_limits<int>::max()); 
    d[startVertex] = 0;

    int temp, minindex, min;
    do {
        minindex = numeric_limits<int>::max();
        min = numeric_limits<int>::max();
        for (int i = 0; i < SIZE; i++)
        {
            if ((visited[i] == false) && (d[i] < min))
            {
                min = d[i];
                minindex = i;
            }
        }
        if (minindex != numeric_limits<int>::max())
        {
            for (int i = 0; i < SIZE; i++)
            {
                if (graph->length_form_to(minindex, i) > 0)
                {
                    temp = min + graph->length_form_to(minindex, i);
                    if (temp < d[i])
                    {
                        d[i] = temp;
                    }
                }
            }
            visited[minindex] = true;
        }
    } while (minindex != endVertex && minindex != numeric_limits<int>::max());

    if (minindex == numeric_limits<int>::max())
        return { -1, {} };

    vector<int> shortestPath;
    shortestPath.push_back(endVertex);
    int indexPrevVertex = 0;
    int weight = d[endVertex];
    int currentVertex = endVertex;

    while (currentVertex != startVertex) {
        for (int i = 0; i < SIZE; ++i) {
            if (graph->length_form_to(i, currentVertex) != 0) {
                int temp = weight - graph->length_form_to(i, currentVertex);
                if (temp == d[i]) {
                    weight = temp;
                    currentVertex = i;
                    shortestPath.push_back(i);
                }
            }
        }
    }

    reverse(shortestPath.begin(), shortestPath.end());

    return make_pair(d[endVertex], shortestPath);
}

pair<int, vector<int>> ShortestPathManager::getShortestPath() {
    banned.assign(graph->countTop(), false);
    visited.assign(graph->countTop(), false);
    length_path_of_two_vertices.second.clear();

    auto [length, path] = __getShortestPath(startVertex, endVertex);
    for (auto bannedVertex : path) {
        banned[bannedVertex] = true;
    }
    return { length, path };
}

    
pair<int, vector<int>> ShortestPathManager::getNextShortestPath() {
    visited.assign(banned.begin(), banned.end());
    visited[startVertex] = false;
    visited[endVertex] = false;

    if (!length_path_of_two_vertices.second.empty()) {
        graph->changeEdge(length_path_of_two_vertices.second[0], length_path_of_two_vertices.second[1], -1);
    }

    auto [length, path] = __getShortestPath(startVertex, endVertex);
    if (path.size() == 2) {
        length_path_of_two_vertices = { length, path };
    }

    if (!length_path_of_two_vertices.second.empty()) {
        graph->changeEdge(length_path_of_two_vertices.second[0], length_path_of_two_vertices.second[1], length_path_of_two_vertices.first);
    }

    for (auto bannedVertex : path) {
        banned[bannedVertex] = true;
    }
    return { length, path };
}