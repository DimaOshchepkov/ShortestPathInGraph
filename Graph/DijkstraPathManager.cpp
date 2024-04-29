#include "pch.h"
#include "framework.h"

#include <algorithm>
#include <queue> // ��� ������������� priority_queue
#include <utility> // ��� ������������� std::pair
#include "DijkstraPathManager.h"
#include "Graph.h"

using namespace std;

template<NumericOrBool EdgeType, IsDerivedFrom<IGraph<EdgeType>> Graph>
BasePathManager<EdgeType, Graph>::BasePathManager(Graph& graph, int startVertex, int endVertex) :
    graph(graph), startVertex(startVertex), endVertex(endVertex),
    d(graph.countTop(), numeric_limits<int>::max()),
    visited(graph.countTop(), false),
    banned(graph.countTop(), false) {}

template<NumericOrBool EdgeType, IsDerivedFrom<IGraph<EdgeType>> Graph>
pair<int, vector<int>> DijkstraPathManager<EdgeType, Graph>::__getShortestPath(int startVertex, int endVertex) {
    const int SIZE = this->graph.countTop();
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
    this->d.assign(this->graph.countTop(), numeric_limits<int>::max());
    this->d[startVertex] = 0;

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
        if (this->visited[u]) continue;
        this->visited[u] = true;

        /// ������� ������� ������� u
        for (int i : this->graph.getVectorNeighbors(u)) {
            int v = i;
            int weight = this->graph.length_form_to(u, i);

            /// ���������� ���������� �� ������� v
            if (dist + weight < this->d[v]) {
                this->d[v] = dist + weight;
                pq.push(std::make_pair(this->d[v], v)); // ��������� � ���� � ����� �����������
            }
        }


    } while (u != endVertex && dist != numeric_limits<int>::max());

    

    vector<int> shortestPath;
    shortestPath.push_back(endVertex);
    int indexPrevVertex = 0;
    int weight = this->d[endVertex];
    int currentVertex = endVertex;

    while (currentVertex != startVertex) {
        for (int i = 0; i < SIZE; ++i) {
            if (this->graph.length_form_to(i, currentVertex) > 0) {
                int temp = weight - this->graph.length_form_to(i, currentVertex);
                if (temp == this->d[i]) {
                    weight = temp;
                    currentVertex = i;
                    shortestPath.push_back(i);
                }
            }
        }
    }

    reverse(shortestPath.begin(), shortestPath.end());

    return make_pair(this->d[endVertex], shortestPath);
}

template<NumericOrBool EdgeType, IsDerivedFrom<IGraph<EdgeType>> Graph>
DijkstraPathManager<EdgeType, Graph>::DijkstraPathManager(Graph& graph, int startVertex, int endVertex) :
        BasePathManager<EdgeType, Graph>(graph, startVertex, endVertex){}

template<NumericOrBool EdgeType, IsDerivedFrom<IGraph<EdgeType>> Graph>
pair<int, vector<int>> BasePathManager<EdgeType, Graph>::getShortestPath() {
    visited.assign(graph.countTop(), false);
    banned.assign(graph.countTop(), false);
    length_path_of_two_vertices.second.clear();

    auto [length, path] = __getShortestPath(startVertex, endVertex);
    for (auto bannedVertex : path) {
        banned[bannedVertex] = true;
    }
    return { length, path };
}

template<NumericOrBool EdgeType, IsDerivedFrom<IGraph<EdgeType>> Graph>
pair<int, vector<int>> BasePathManager<EdgeType, Graph>::getNextShortestPath() {
    /// ��������� ������� ������ ���� � ����� ������
    visited = banned;
    visited[startVertex] = false;
    visited[endVertex] = false;

    /// ��������� ������� ������, ����� ���� �������� ������ �� ��������� � �������� �������
    if (!length_path_of_two_vertices.second.empty()) {
        graph.removeEdge(length_path_of_two_vertices.second[0], length_path_of_two_vertices.second[1]);
    }

    auto [length, path] = __getShortestPath(startVertex, endVertex);
    if (path.size() == 2) {
        length_path_of_two_vertices = { length, path };
    }

    /// ��������� ������� ������, ����� ���� �������� ������ �� ��������� � �������� �������
    if (!length_path_of_two_vertices.second.empty()) {
        graph.changeEdge(length_path_of_two_vertices.second[0], length_path_of_two_vertices.second[1], length_path_of_two_vertices.first);
    }

    for (auto bannedVertex : path) {
        banned[bannedVertex] = true;
    }
    return { length, path };
}

template<NumericOrBool EdgeType, IsDerivedFrom<IGraph<EdgeType>> Graph>
std::pair<int, std::vector<int>> BFSPathManager<EdgeType, Graph>::__getShortestPath(int startVertex, int endVertex)
{
    queue<int> q;
    q.push(startVertex);
    vector<int> prev(this->graph.countTop(), -1); // ������ ��� �������� ���������� ������

    bool is_find = false;
    while (!is_find) {
        if (q.empty()) {
            return { -1, {} };
        }
        int current = q.front();
        q.pop();
        this->visited[current] = true;
        if (current == endVertex) break;

        for (int neighbor : this->graph.getVectorNeighbors(current)) {

            if (!this->visited[neighbor]) {
                q.push(neighbor);
                prev[neighbor] = current; // ���������� ���������� �������
                if (neighbor == endVertex) {
                    is_find = true;
                    break;
                }
            }
        }
    }

    vector<int> path;
    int current = endVertex;
    while (current != -1) { // ���� ���� ���������� �������
        path.push_back(current);
        current = prev[current];
    }
    reverse(path.begin(), path.end()); // �������������� ����

    return { path.size() - 1, path };
}

template<NumericOrBool EdgeType, IsDerivedFrom<IGraph<EdgeType>> Graph>
BFSPathManager<EdgeType, Graph>::BFSPathManager(Graph& graph, int startVertex, int endVertex) :
    BasePathManager<EdgeType, Graph>(graph, startVertex, endVertex) {};