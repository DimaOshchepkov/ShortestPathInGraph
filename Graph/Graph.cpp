// Graph.cpp : Определяет функции для статической библиотеки.
//

#include "pch.h"
#include "framework.h"

#include "Graph.h"
#include <fstream>
#include <string>
#include <algorithm>
#include <stdexcept>


AdjencyMatrix::AdjencyMatrix(std::string path)
{
    std::ifstream file(path);

    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file " + path);
    }

    int countTop, countEdges;
    if (!(file >> countTop >> countEdges)) {
        throw std::runtime_error("Failed to read counts from file");
    }

    this->matrix = std::vector<std::vector<int>>(countTop, std::vector<int>(countTop, -1));
    for (int i = 0; i < countEdges; ++i) {
        int from, to, length;
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

AdjencyMatrix::AdjencyMatrix(const AdjencyMatrix& other) : matrix(other.matrix) {}

AdjencyMatrix::AdjencyMatrix(AdjencyMatrix&& other) noexcept
    : matrix(std::move(other.matrix)){
    
    other.~AdjencyMatrix();
}

AdjencyMatrix& AdjencyMatrix::operator=(const AdjencyMatrix& other) {
    if (this != &other) {
        AdjencyMatrix temp(other);
        swap(temp.matrix, matrix);
    }
    return *this;
}

AdjencyMatrix& AdjencyMatrix::operator=(AdjencyMatrix&& other) noexcept {
    if (this != &other) {
        AdjencyMatrix temp(std::move(other));
        swap(temp.matrix, matrix);
    }
    return *this;
}

AdjencyMatrix::AdjencyMatrix(int countTop) : matrix(vector<vector<int>>(countTop, vector<int>(countTop, 0))) {}


int AdjencyMatrix::length_form_to(int from, int to) const
{
    if (from < 0 || from >= matrix.size()) {
        throw std::runtime_error("Vertex " + std::to_string(from) + " is not exist");
    }

    if (to < 0 || to >= matrix.size()) {
        throw std::runtime_error("Vertex " + std::to_string(to) + " is not exist");
    }

    return matrix[from][to];
}

int AdjencyMatrix::countTop() const
{
    return matrix.size();
}

void AdjencyMatrix::changeEdge(int from, int to, int value)
{
    if (from < 0 || from >= matrix.size()) {
        throw std::runtime_error("Vertex " + std::to_string(from) + " is not exist");
    }

    if (to < 0 || to >= matrix.size()) {
        throw std::runtime_error("Vertex " + std::to_string(to) + " is not exist");
    }

    matrix[from][to] = value;
}

std::vector<int> AdjencyMatrix::getVectorNeighbors(int vert)
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

AdjencyList::AdjencyList(int vertices) : adjacencyList(vertices) {}


int AdjencyList::countTop() const {
    return adjacencyList.size();
}

int AdjencyList::length_form_to(int from, int to) const {
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
    return -1; // Если между вершинами нет ребра
}

void AdjencyList::changeEdge(int from, int to, int value) {
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

std::vector<int> AdjencyList::getVectorNeighbors(int vert) {
    std::vector<int> neighbors;
    neighbors.reserve(400);
    for (const auto& neighbor : adjacencyList[vert]) {
        neighbors.push_back(neighbor.first); 
    }
    return neighbors;
}

AdjencyList::AdjencyList(std::string path) {
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

AdjencyList::AdjencyList(const AdjencyList& other) : adjacencyList(other.adjacencyList) {}


AdjencyList::AdjencyList(AdjencyList&& other) noexcept : adjacencyList(std::move(other.adjacencyList)) {}

AdjencyList& AdjencyList::operator=(const AdjencyList& other) {
    if (this != &other) {
        AdjencyList temp(other);
        std::swap(adjacencyList, temp.adjacencyList);
    }
    return *this;
}

AdjencyList& AdjencyList::operator=(AdjencyList&& other) noexcept {
    if (this != &other) {
        adjacencyList = std::move(other.adjacencyList);
    }
    return *this;
}

void AdjencyList::removeEdge(int from, int to) {
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

void AdjencyMatrix::removeEdge(int from, int to) {
    if (from < 0 || from >= matrix.size()) {
        throw std::runtime_error("Vertex " + std::to_string(from) + " is not exist");
    }

    if (to < 0 || to >= matrix.size()) {
        throw std::runtime_error("Vertex " + std::to_string(to) + " is not exist");
    }

    matrix[from][to] = -1;
}