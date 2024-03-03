// Graph.cpp : Определяет функции для статической библиотеки.
//

#include "pch.h"
#include "framework.h"

#include "Graph.h"
#include <fstream>
#include <string>
#include <algorithm>
#include <stdexcept>

using std::string;

AdjencyMatrix::AdjencyMatrix(string path)
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


vector<int>& AdjencyMatrix::operator[](int row) {
    return matrix[row];
}

const vector<int>& AdjencyMatrix::operator[](int row) const {
    return matrix[row];
}

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



