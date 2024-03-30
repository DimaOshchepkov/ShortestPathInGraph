#include "pch.h"
#include "framework.h"

#include <algorithm>
#include <queue> // ��� ������������� priority_queue
#include <utility> // ��� ������������� std::pair
#include "ShortestPathManager.h"
#include "Graph.h"

using namespace std;

DijkstraPathManager::DijkstraPathManager(shared_ptr<IGraph> graph, int startVertex, int endVertex) :
    graph(graph), startVertex(startVertex), endVertex(endVertex),
    d(graph->countTop(), numeric_limits<int>::max()),
    visited(graph->countTop(), false) {}

pair<int, vector<int>> DijkstraPathManager::__getShortestPath(int startVertex, int endVertex) {
    const int SIZE = graph->countTop();
    /// ��� ��� �������� ���������� � ������
    typedef std::pair<int, int> Pair; // <����������, �������>

    /// ������� ��������� ��� ��������� ���
    struct ComparePair {
        /// \brief �������� ��������� ���.
        ///
        /// \param a ������ ����.
        /// \param b ������ ����.
        /// \return True, ���� ���������� ������ ���� ������ ���������� ������ ����, ����� false.
        bool operator()(Pair const& a, Pair const& b) {
            return a.first > b.first; // ���������� �� ����������
        }
    };

    /// ������������� ����
    std::priority_queue<Pair, std::vector<Pair>, ComparePair> pq;

    /// �������� ������������� ������� d �� ������� ��� � ����
    pq.push(std::make_pair(0, startVertex)); // ��������� ���������� �� ��������� ������� ����� 0
    d.assign(graph->countTop(), numeric_limits<int>::max());
    d[startVertex] = 0;

    /// �������� ��������� ��������
    int dist, u;
    do {
        if (pq.empty()) {
            return { -1, {} };
        }
        Pair top = pq.top(); pq.pop();
        dist = top.first;
        u = top.second;

        /// ��������, �������� �� �� ��� �������
        if (visited[u]) continue;
        visited[u] = true;

        /// ������� ������� ������� u
        for (int i : graph->getVectorNeighbors(u)) {
            int v = i;
            int weight = graph->length_form_to(u, i);

            /// ���������� ���������� �� ������� v
            if (dist + weight < d[v]) {
                d[v] = dist + weight;
                pq.push(std::make_pair(d[v], v)); // ��������� � ���� � ����� �����������
            }
        }


    } while (u != endVertex && dist != numeric_limits<int>::max());

    

    vector<int> shortestPath;
    shortestPath.push_back(endVertex);
    int indexPrevVertex = 0;
    int weight = d[endVertex];
    int currentVertex = endVertex;

    while (currentVertex != startVertex) {
        for (int i = 0; i < SIZE; ++i) {
            if (graph->length_form_to(i, currentVertex) > 0) {
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

pair<int, vector<int>> DijkstraPathManager::getShortestPath() {
    visited.assign(graph->countTop(), false);
    length_path_of_two_vertices.second.clear();

    auto [length, path] = __getShortestPath(startVertex, endVertex);
    for (auto bannedVertex : path) {
        visited[bannedVertex] = true;
    }
    return { length, path };
}

    
pair<int, vector<int>> DijkstraPathManager::getNextShortestPath() {
    /// ��������� ������� ������ ���� � ����� ������
    visited[startVertex] = false;
    visited[endVertex] = false;

    /// ��������� ������� ������, ����� ���� �������� ������ �� ��������� � �������� �������
    if (!length_path_of_two_vertices.second.empty()) {
        graph->removeEdge(length_path_of_two_vertices.second[0], length_path_of_two_vertices.second[1]);
    }

    auto [length, path] = __getShortestPath(startVertex, endVertex);
    if (path.size() == 2) {
        length_path_of_two_vertices = { length, path };
    }

    /// ��������� ������� ������, ����� ���� �������� ������ �� ��������� � �������� �������
    if (!length_path_of_two_vertices.second.empty()) {
        graph->changeEdge(length_path_of_two_vertices.second[0], length_path_of_two_vertices.second[1], length_path_of_two_vertices.first);
    }

    for (auto bannedVertex : path) {
        visited[bannedVertex] = true;
    }
    return { length, path };
}
