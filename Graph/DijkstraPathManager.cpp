#include "pch.h"
#include "framework.h"

#include <algorithm>
#include <queue> // для использования priority_queue
#include <utility> // для использования std::pair
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
    /// Тип для хранения расстояний и вершин
    typedef std::pair<int, int> Pair; // <расстояние, вершина>

    /// Создаем структуру для сравнения пар
    struct ComparePair {
        /// \brief Оператор сравнения пар.
        ///
        /// \param a Первая пара.
        /// \param b Вторая пара.
        /// \return True, если расстояние первой пары больше расстояния второй пары, иначе false.
        bool operator()(Pair const& a, Pair const& b) {
            return a.first > b.first; // сравниваем по расстоянию
        }
    };

    /// Инициализация кучи
    std::priority_queue<Pair, std::vector<Pair>, ComparePair> pq;

    /// Заменяем инициализацию массива d на вставку пар в кучу
    pq.push(std::make_pair(0, startVertex)); // начальное расстояние до стартовой вершины равно 0
    this->d.assign(this->graph.countTop(), numeric_limits<int>::max());
    this->d[startVertex] = 0;

    /// Итерации алгоритма Дейкстры
    int dist, u;
    do {
        if (pq.empty()) {
            return { -1, {} };
        }
        Pair top = pq.top(); pq.pop();
        dist = top.first;
        u = top.second;

        /// Проверка, посещали ли мы эту вершину
        if (this->visited[u]) continue;
        this->visited[u] = true;

        /// Перебор соседей вершины u
        for (int i : this->graph.getVectorNeighbors(u)) {
            int v = i;
            int weight = this->graph.length_form_to(u, i);

            /// Обновление расстояния до вершины v
            if (dist + weight < this->d[v]) {
                this->d[v] = dist + weight;
                pq.push(std::make_pair(this->d[v], v)); // вставляем в кучу с новым расстоянием
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
    /// Начальные вершины должны быть в любом случае
    visited = banned;
    visited[startVertex] = false;
    visited[endVertex] = false;

    /// Обработка особого случая, когда путь состоити только из начальной и конечной вершины
    if (!length_path_of_two_vertices.second.empty()) {
        graph.removeEdge(length_path_of_two_vertices.second[0], length_path_of_two_vertices.second[1]);
    }

    auto [length, path] = __getShortestPath(startVertex, endVertex);
    if (path.size() == 2) {
        length_path_of_two_vertices = { length, path };
    }

    /// Обработка особого случая, когда путь состоити только из начальной и конечной вершины
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
    vector<int> prev(this->graph.countTop(), -1); // Вектор для хранения предыдущих вершин

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
                prev[neighbor] = current; // Запоминаем предыдущую вершину
                if (neighbor == endVertex) {
                    is_find = true;
                    break;
                }
            }
        }
    }

    vector<int> path;
    int current = endVertex;
    while (current != -1) { // Пока есть предыдущая вершина
        path.push_back(current);
        current = prev[current];
    }
    reverse(path.begin(), path.end()); // Переворачиваем путь

    return { path.size() - 1, path };
}

template<NumericOrBool EdgeType, IsDerivedFrom<IGraph<EdgeType>> Graph>
BFSPathManager<EdgeType, Graph>::BFSPathManager(Graph& graph, int startVertex, int endVertex) :
    BasePathManager<EdgeType, Graph>(graph, startVertex, endVertex) {};