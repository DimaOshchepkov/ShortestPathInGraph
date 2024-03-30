#include "pch.h"
#include "framework.h"

#include "Graph_bool.h"
#include <stdexcept>
#include <fstream>

bool AdjencyList<bool>::length_form_to(int from, int to) const {
    if (from < 0 || from >= adjacencyList.size()) {
        throw std::runtime_error("Vertex " + std::to_string(from) + " is not exist");
    }

    if (to < 0 || to >= adjacencyList.size()) {
        throw std::runtime_error("Vertex " + std::to_string(to) + " is not exist");
    }

    auto it = std::find(adjacencyList[from].begin(), adjacencyList[from].end(), to);
    return it != adjacencyList[from].end(); // Если между вершинами нет ребра
}

void AdjencyList<bool>::changeEdge(int from, int to, bool value)
{
    if (from < 0 || from >= adjacencyList.size()) {
        throw std::runtime_error("Vertex " + std::to_string(from) + " is not exist");
    }

    if (to < 0 || to >= adjacencyList.size()) {
        throw std::runtime_error("Vertex " + std::to_string(to) + " is not exist");
    }

    auto it = std::find(adjacencyList[from].begin(), adjacencyList[from].end(), to);
    if (it != adjacencyList[from].end() && !value) {
        adjacencyList[from].erase(it);
    }
    if (it == adjacencyList[from].end() && value) {
        adjacencyList[from].push_back(value);
    }
}

std::vector<int> AdjencyList<bool>::getVectorNeighbors(int vert) {
    return std::vector(adjacencyList[vert]);
}

AdjencyList<bool>::AdjencyList(std::string path) {
    std::ifstream file(path);

    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file " + path);
    }

    int countTop, countEdges;
    if (!(file >> countTop >> countEdges)) {
        throw std::runtime_error("Failed to read counts from file");
    }

    this->adjacencyList = std::vector<std::vector<int>>(countTop);
    for (int i = 0; i < countEdges; ++i) {
        int from, to, length;
        if (!(file >> from >> to >> length)) {
            throw std::runtime_error("Failed to read edge from file");
        }
        if (from < 0 || from >= countTop || to < 0 || to >= countTop) {
            throw std::runtime_error("Invalid edge indices in file");
        }
        this->adjacencyList[from].push_back(to);
    }
    file.close();
}


void AdjencyList<bool>::removeEdge(int from, int to) {
    if (from < 0 || from >= adjacencyList.size()) {
        throw std::runtime_error("Vertex " + std::to_string(from) + " is not exist");
    }

    if (to < 0 || to >= adjacencyList.size()) {
        throw std::runtime_error("Vertex " + std::to_string(to) + " is not exist");
    }

    auto it = std::find(adjacencyList[from].begin(), adjacencyList[from].end(), to);

    if (it != adjacencyList[from].end()) {
        adjacencyList[from].erase(it);
    }
}

AdjencyList<bool>::AdjencyList(int vertices) : adjacencyList(vertices) {}

int AdjencyList<bool>::countTop() const {
    return adjacencyList.size();
}

AdjencyList<bool>::AdjencyList(const AdjencyList<bool>& other) :
    adjacencyList(other.adjacencyList) {}

AdjencyList<bool>::AdjencyList(AdjencyList<bool>&& other) noexcept :
    adjacencyList(std::move(other.adjacencyList)) {}

AdjencyList<bool>& AdjencyList<bool>::operator=(const AdjencyList<bool>& other) {
    if (this != &other) {
        AdjencyList temp(other);
        std::swap(adjacencyList, temp.adjacencyList);
    }
    return *this;
}

AdjencyList<bool>& AdjencyList<bool>::operator=(AdjencyList<bool>&& other) noexcept {
    if (this != &other) {
        adjacencyList = std::move(other.adjacencyList);
    }
    return *this;
}