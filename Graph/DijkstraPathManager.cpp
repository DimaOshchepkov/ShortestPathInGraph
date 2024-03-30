#include "pch.h"
#include "framework.h"

#include <algorithm>
#include <queue> // дл€ использовани€ priority_queue
#include <utility> // дл€ использовани€ std::pair
#include "ShortestPathManager.h"
#include "Graph.h"

using namespace std;

DijkstraPathManager::DijkstraPathManager(shared_ptr<IGraph> graph, int startVertex, int endVertex) :
    graph(graph), startVertex(startVertex), endVertex(endVertex),
    d(graph->countTop(), numeric_limits<int>::max()),
    visited(graph->countTop(), false) {}

pair<int, vector<int>> DijkstraPathManager::__getShortestPath(int startVertex, int endVertex) {
    const int SIZE = graph->countTop();
    /// “ип дл€ хранени€ рассто€ний и вершин
    typedef std::pair<int, int> Pair; // <рассто€ние, вершина>

    /// —оздаем структуру дл€ сравнени€ пар
    struct ComparePair {
        /// \brief ќператор сравнени€ пар.
        ///
        /// \param a ѕерва€ пара.
        /// \param b ¬тора€ пара.
        /// \return True, если рассто€ние первой пары больше рассто€ни€ второй пары, иначе false.
        bool operator()(Pair const& a, Pair const& b) {
            return a.first > b.first; // сравниваем по рассто€нию
        }
    };

    /// »нициализаци€ кучи
    std::priority_queue<Pair, std::vector<Pair>, ComparePair> pq;

    /// «амен€ем инициализацию массива d на вставку пар в кучу
    pq.push(std::make_pair(0, startVertex)); // начальное рассто€ние до стартовой вершины равно 0
    d.assign(graph->countTop(), numeric_limits<int>::max());
    d[startVertex] = 0;

    /// »терации алгоритма ƒейкстры
    int dist, u;
    do {
        if (pq.empty()) {
            return { -1, {} };
        }
        Pair top = pq.top(); pq.pop();
        dist = top.first;
        u = top.second;

        /// ѕроверка, посещали ли мы эту вершину
        if (visited[u]) continue;
        visited[u] = true;

        /// ѕеребор соседей вершины u
        for (int i : graph->getVectorNeighbors(u)) {
            int v = i;
            int weight = graph->length_form_to(u, i);

            /// ќбновление рассто€ни€ до вершины v
            if (dist + weight < d[v]) {
                d[v] = dist + weight;
                pq.push(std::make_pair(d[v], v)); // вставл€ем в кучу с новым рассто€нием
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
    /// Ќачальные вершины должны быть в любом случае
    visited[startVertex] = false;
    visited[endVertex] = false;

    /// ќбработка особого случа€, когда путь состоити только из начальной и конечной вершины
    if (!length_path_of_two_vertices.second.empty()) {
        graph->removeEdge(length_path_of_two_vertices.second[0], length_path_of_two_vertices.second[1]);
    }

    auto [length, path] = __getShortestPath(startVertex, endVertex);
    if (path.size() == 2) {
        length_path_of_two_vertices = { length, path };
    }

    /// ќбработка особого случа€, когда путь состоити только из начальной и конечной вершины
    if (!length_path_of_two_vertices.second.empty()) {
        graph->changeEdge(length_path_of_two_vertices.second[0], length_path_of_two_vertices.second[1], length_path_of_two_vertices.first);
    }

    for (auto bannedVertex : path) {
        visited[bannedVertex] = true;
    }
    return { length, path };
}
