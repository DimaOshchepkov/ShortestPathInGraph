#pragma once

#pragma once

#include <string>
#include <vector>

using std::vector;
using std::string;

class IGraph {
public:
    virtual int length_form_to(int from, int to) const = 0;
    virtual int countTop() const = 0;
    virtual void changeEdge(int from, int to, int value) = 0;
    virtual vector<int> getVectorNeighbors(int vert) = 0;
    virtual void removeEdge(int start, int end) = 0;
};

class AdjencyMatrix : public IGraph {
private:
    vector<vector<int>> matrix;

public:
    AdjencyMatrix(string path);
    AdjencyMatrix(const AdjencyMatrix& other);
    AdjencyMatrix(AdjencyMatrix&& other) noexcept;
    AdjencyMatrix& operator=(const AdjencyMatrix& other);
    AdjencyMatrix& operator=(AdjencyMatrix&& other) noexcept;
    AdjencyMatrix(int countTop);

    int length_form_to(int from, int to) const override;
    int countTop() const override;
    void changeEdge(int from, int to, int value) override;
    vector<int> getVectorNeighbors(int vert) override;
    void removeEdge(int start, int end) override;
};

class AdjencyList : public IGraph {
private:
    std::vector<std::vector<std::pair<int, int>>> adjacencyList;

public:
    AdjencyList(int vertices);
    virtual int countTop() const override;
    virtual int length_form_to(int from, int to) const override;
    virtual void changeEdge(int from, int to, int value) override;
    virtual std::vector<int> getVectorNeighbors(int vert) override;

    // Конструктор из файла
    AdjencyList(std::string path);
    AdjencyList(const AdjencyList& other);
    AdjencyList(AdjencyList&& other) noexcept;
    AdjencyList& operator=(const AdjencyList& other);
    AdjencyList& operator=(AdjencyList&& other) noexcept;
    void removeEdge(int start, int end) override;
};