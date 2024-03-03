#pragma once

#pragma once

#include <string>
#include <vector>

using std::vector;
using std::string;

class IGraph {
public:
    virtual vector<int>& operator[](int row) = 0;
    virtual const vector<int>& operator[](int row) const = 0;
    virtual int length_form_to(int from, int to) const = 0;
    virtual int countTop() const = 0;
    virtual void changeEdge(int from, int to, int value) = 0;
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

    vector<int>& operator[](int row) override;
    const vector<int>& operator[](int row) const override;
    int length_form_to(int from, int to) const override;
    int countTop() const override;
    void changeEdge(int from, int to, int value) override;
};
