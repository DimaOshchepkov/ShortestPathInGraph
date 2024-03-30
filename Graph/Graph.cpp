// Graph.cpp : Определяет функции для статической библиотеки.
//

#include "pch.h"
#include "framework.h"

#include "Graph.h"
#include <fstream>
#include <string>
#include <algorithm>
#include <stdexcept>

template<typename EdgeType>
AdjencyMatrix<EdgeType>::AdjencyMatrix(std::string path)
{
    std::ifstream file(path);

    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file " + path);
    }

    int countTop, countEdges;
    if (!(file >> countTop >> countEdges)) {
        throw std::runtime_error("Failed to read counts from file");
    }

    this->matrix = std::vector<std::vector<EdgeType>>(countTop, std::vector<EdgeType>(countTop, 0));
    for (int i = 0; i < countEdges; ++i) {
        int from, to;
        EdgeType length;
        if (!(file >> from >> to >> length)) {
            throw std::runtime_error("Failed to read edge from file");
        }
        if (from < 0 || from >= countTop || to < 0 || to >= countTop) {
            throw std::runtime_error("Invalid edge indices in file");
        }
        matrix[from][to] = length;
    }
    file.close();
}

template<typename EdgeType>
AdjencyMatrix<EdgeType>::AdjencyMatrix(const AdjencyMatrix& other) : matrix(other.matrix) {}

template<typename EdgeType>
AdjencyMatrix<EdgeType>::AdjencyMatrix(AdjencyMatrix<EdgeType>&& other) noexcept
    : matrix(std::move(other.matrix)){
    
    other.~AdjencyMatrix();
}

template<typename EdgeType>
AdjencyMatrix<EdgeType>& AdjencyMatrix<EdgeType>::operator=(const AdjencyMatrix<EdgeType>& other) {
    if (this != &other) {
        AdjencyMatrix temp(other);
        swap(temp.matrix, matrix);
    }
    return *this;
}

template<typename EdgeType>
AdjencyMatrix<EdgeType>& AdjencyMatrix<EdgeType>::operator=(AdjencyMatrix<EdgeType>&& other) noexcept {
    if (this != &other) {
        AdjencyMatrix temp(std::move(other));
        swap(temp.matrix, matrix);
    }
    return *this;
}

template<typename EdgeType>
AdjencyMatrix<EdgeType>::AdjencyMatrix(int countTop) : matrix(vector<vector<EdgeType>>(countTop, vector<EdgeType>(countTop, 0))) {}


template<typename EdgeType>
EdgeType AdjencyMatrix<EdgeType>::length_form_to(int from, int to) const
{
    if (from < 0 || from >= matrix.size()) {
        throw std::runtime_error("Vertex " + std::to_string(from) + " is not exist");
    }

    if (to < 0 || to >= matrix.size()) {
        throw std::runtime_error("Vertex " + std::to_string(to) + " is not exist");
    }

    return matrix[from][to];
}

template<typename EdgeType>
int AdjencyMatrix<EdgeType>::countTop() const
{
    return matrix.size();
}

template<typename EdgeType>
void AdjencyMatrix<EdgeType>::changeEdge(int from, int to, EdgeType value)
{
    if (from < 0 || from >= matrix.size()) {
        throw std::runtime_error("Vertex " + std::to_string(from) + " is not exist");
    }

    if (to < 0 || to >= matrix.size()) {
        throw std::runtime_error("Vertex " + std::to_string(to) + " is not exist");
    }

    matrix[from][to] = value;
}

template<typename EdgeType>
std::vector<int> AdjencyMatrix<EdgeType>::getVectorNeighbors(int vert)
{
    std::vector<int> result;
    result.reserve(400);

    for (size_t i = 0; i < matrix[vert].size(); ++i) {
        if (matrix[vert][i] > 0) {
            result.push_back(i);
        }
    }

    return result;
}

template<typename EdgeType>
AdjencyList<EdgeType>::AdjencyList(int vertices) : adjacencyList(vertices) {}

template<typename EdgeType>
int AdjencyList<EdgeType>::countTop() const {
    return adjacencyList.size();
}

template<typename EdgeType>
EdgeType AdjencyList<EdgeType>::length_form_to(int from, int to) const {
    if (from < 0 || from >= adjacencyList.size()) {
        throw std::runtime_error("Vertex " + std::to_string(from) + " is not exist");
    }

    if (to < 0 || to >= adjacencyList.size()) {
        throw std::runtime_error("Vertex " + std::to_string(to) + " is not exist");
    }

    for (const auto& neighbor : adjacencyList[from]) {
        if (neighbor.first == to) {
            return neighbor.second; // Возвращаем вес ребра
        }
    }
    return 0; // Если между вершинами нет ребра
}

template<typename EdgeType>
void AdjencyList<EdgeType>::changeEdge(int from, int to, EdgeType value) {
    if (from < 0 || from >= adjacencyList.size()) {
        throw std::runtime_error("Vertex " + std::to_string(from) + " is not exist");
    }

    if (to < 0 || to >= adjacencyList.size()) {
        throw std::runtime_error("Vertex " + std::to_string(to) + " is not exist");
    }

    for (auto& neighbor : adjacencyList[from]) {
        if (neighbor.first == to) {
            neighbor.second = value; 
            return;
        }
    }
    adjacencyList[from].push_back(std::make_pair(to, value));
}

template<typename EdgeType>
std::vector<int> AdjencyList<EdgeType>::getVectorNeighbors(int vert) {
    std::vector<int> neighbors;
    neighbors.reserve(400);
    for (const auto& neighbor : adjacencyList[vert]) {
        neighbors.push_back(neighbor.first); 
    }
    return neighbors;
}

template<typename EdgeType>
AdjencyList<EdgeType>::AdjencyList(std::string path) {
    std::ifstream file(path);

    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file " + path);
    }

    int countTop, countEdges;
    if (!(file >> countTop >> countEdges)) {
        throw std::runtime_error("Failed to read counts from file");
    }

    this->adjacencyList = std::vector<std::vector<std::pair<int, int>>>(countTop);
    for (int i = 0; i < countEdges; ++i) {
        int from, to, length;
        if (!(file >> from >> to >> length)) {
            throw std::runtime_error("Failed to read edge from file");
        }
        if (from < 0 || from >= countTop || to < 0 || to >= countTop) {
            throw std::runtime_error("Invalid edge indices in file");
        }
        this->adjacencyList[from].push_back({ to, length });
    }
    file.close();
}

template<typename EdgeType>
AdjencyList<EdgeType>::AdjencyList(const AdjencyList<EdgeType>& other) : adjacencyList(other.adjacencyList) {}

template<typename EdgeType>
AdjencyList<EdgeType>::AdjencyList(AdjencyList<EdgeType>&& other) noexcept : adjacencyList(std::move(other.adjacencyList)) {}

template<typename EdgeType>
AdjencyList<EdgeType>& AdjencyList<EdgeType>::operator=(const AdjencyList<EdgeType>& other) {
    if (this != &other) {
        AdjencyList temp(other);
        std::swap(adjacencyList, temp.adjacencyList);
    }
    return *this;
}

template<typename EdgeType>
AdjencyList<EdgeType>& AdjencyList<EdgeType>::operator=(AdjencyList<EdgeType>&& other) noexcept {
    if (this != &other) {
        adjacencyList = std::move(other.adjacencyList);
    }
    return *this;
}

template<typename EdgeType>
void AdjencyList<EdgeType>::removeEdge(int from, int to) {
    if (from < 0 || from >= adjacencyList.size()) {
        throw std::runtime_error("Vertex " + std::to_string(from) + " is not exist");
    }

    if (to < 0 || to >= adjacencyList.size()) {
        throw std::runtime_error("Vertex " + std::to_string(to) + " is not exist");
    }

    for (auto neighbor_iter = adjacencyList[from].begin();
        neighbor_iter != adjacencyList[from].end(); neighbor_iter++) {
        if ((*neighbor_iter).first == to) {
            adjacencyList[from].erase(neighbor_iter);
            return;
        }
    }
}

template<typename EdgeType>
void AdjencyMatrix<EdgeType>::removeEdge(int from, int to) {
    if (from < 0 || from >= matrix.size()) {
        throw std::runtime_error("Vertex " + std::to_string(from) + " is not exist");
    }

    if (to < 0 || to >= matrix.size()) {
        throw std::runtime_error("Vertex " + std::to_string(to) + " is not exist");
    }

    matrix[from][to] = 0;
}