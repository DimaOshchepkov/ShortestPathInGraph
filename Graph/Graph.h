#pragma once

#pragma once

#include <string>
#include <vector>

using std::vector;
using std::string;

/// \brief ��������� IGraph ������������ ����� ��������� ��� ���� ����� �������� ����� � ������ ����������.
///
/// ���� ��������� ���������� ������, ������� ������ ���� ����������� � �������,
/// �������������� ���������� ������� �������� �����, ����� ��� ������ ��������� ��� ������� ���������.
class IGraph {
public:
    /// \brief ����������� ����� ��� ��������� ����� ����� ����� ���������� ���������.
    ///
    /// \param from ��������� �������.
    /// \param to �������� �������.
    /// \return ����� ����� ����� ��������� from � to. ���� ����� ���, ������ -1
    virtual int length_form_to(int from, int to) const = 0;

    /// \brief ����������� ����� ��� ��������� ���������� ������ � �����.
    ///
    /// \return ���������� ������ � �����.
    virtual int countTop() const = 0;

    /// \brief ����������� ����� ��� ��������� ���� ����� ����� ���������� ���������.
    ///
    /// \param from ��������� ������� �����.
    /// \param to �������� ������� �����.
    /// \param value ����� �������� ���� �����.
    virtual void changeEdge(int from, int to, int value) = 0;

    /// \brief ����������� ����� ��� ��������� ������� ������� ������ ��� ��������� �������.
    ///
    /// \param vert �������, ��� ������� ��������� �������� ������� �������.
    /// \return ������ ������� ������ ��� ��������� �������.
    virtual vector<int> getVectorNeighbors(int vert) = 0;

    /// \brief ����������� ����� ��� �������� ����� ����� ���������� ���������.
    ///
    /// \param start ��������� ������� �����.
    /// \param end �������� ������� �����.
    virtual void removeEdge(int start, int end) = 0;
};

/// \brief ����� AdjencyMatrix ������������ ���������� ���������� IGraph,
///        �������� ���� � ���� ������� ���������.
class AdjencyMatrix : public IGraph {
private:
    vector<vector<int>> matrix; /**< ������� ��������� �����. */

public:
    /// \brief ����������� ������, ����������� ���� �� ����� �� ���������� ����.
    ///
    /// \param path ������ ���� � �����, ����������� ������� ��������� �����.
    AdjencyMatrix(string path);

    /// \brief ����������� �����������.
    ///
    /// \param other ������ ������ AdjencyMatrix, ������� ����� �����������.
    AdjencyMatrix(const AdjencyMatrix& other);

    /// \brief ����������� �����������.
    ///
    /// \param other ������ ������ AdjencyMatrix, ������� ����� �����������.
    AdjencyMatrix(AdjencyMatrix&& other) noexcept;

    /// \brief �������� ������������ ��� �����������.
    ///
    /// \param other ������ ������ AdjencyMatrix, ������� ����� �����������.
    /// \return ������ �� ������ ������ AdjencyMatrix ����� ������������.
    AdjencyMatrix& operator=(const AdjencyMatrix& other);

    /// \brief �������� ������������ ��� �����������.
    ///
    /// \param other ������ ������ AdjencyMatrix, ������� ����� �����������.
    /// \return ������ �� ������ ������ AdjencyMatrix ����� ������������.
    AdjencyMatrix& operator=(AdjencyMatrix&& other) noexcept;

    /// \brief ����������� ������, ��������� ������ ������� ��������� ��� ���������� ���������� ������.
    ///
    /// \param countTop ���������� ������ � �����.
    AdjencyMatrix(int countTop);

    /// \brief ����� ��� ��������� ����� ����� ����� ���������� ���������.
    ///
    /// \param from ��������� �������.
    /// \param to �������� �������.
    /// \return ����� ����� ����� ��������� from � to. ���� ����� ���, ������ -1
    int length_form_to(int from, int to) const override;

    /// \brief ����� ��� ��������� ���������� ������ � �����.
    ///
    /// \return ���������� ������ � �����.
    int countTop() const override;

    /// \brief ����� ��� ��������� ���� ����� ����� ���������� ���������.
    ///
    /// \param from ��������� ������� �����.
    /// \param to �������� ������� �����.
    /// \param value ����� �������� ���� �����.
    void changeEdge(int from, int to, int value) override;

    /// \brief ����� ��� ��������� ������� ������� ������ ��� ��������� �������.
    ///
    /// \param vert �������, ��� ������� ��������� �������� ������� �������.
    /// \return ������ ������� ������ ��� ��������� �������.
    vector<int> getVectorNeighbors(int vert) override;

    /// \brief ����� ��� �������� ����� ����� ���������� ���������. ���� ����� ������ �������� ����� ����
    /// �� -1.
    ///
    /// \param start ��������� ������� �����.
    /// \param end �������� ������� �����.
    void removeEdge(int start, int end) override;
};


/// \brief ����� AdjencyList ������������ ���������� ���������� IGraph,
///        �������� ���� � ���� ������ ���������.
class AdjencyList : public IGraph {
private:
    std::vector<std::vector<std::pair<int, int>>> adjacencyList; /**< ������ ��������� �����. */

public:
    /// \brief ����������� ������, ��������� ������ ������ ��������� ��� ���������� ���������� ������.
    ///
    /// \param vertices ���������� ������ � �����.
    AdjencyList(int vertices);

    /// \brief ����������� ����� ��� ��������� ���������� ������ � �����.
    ///
    /// \return ���������� ������ � �����.
    virtual int countTop() const override;

    /// \brief ����������� ����� ��� ��������� ����� ����� ����� ���������� ���������.
    ///
    /// \param from ��������� �������.
    /// \param to �������� �������.
    /// \return ����� ����� ����� ��������� from � to. ���� ������� ���, ������ -1.
    virtual int length_form_to(int from, int to) const override;

    /// \brief ����������� ����� ��� ��������� ���� ����� ����� ���������� ���������.
    ///
    /// \param from ��������� ������� �����.
    /// \param to �������� ������� �����.
    /// \param value ����� �������� ���� �����.
    virtual void changeEdge(int from, int to, int value) override;

    /// \brief ����������� ����� ��� ��������� ������� ������� ������ ��� ��������� �������.
    ///
    /// \param vert �������, ��� ������� ��������� �������� ������� �������.
    /// \return ������ ������� ������ ��� ��������� �������.
    virtual std::vector<int> getVectorNeighbors(int vert) override;

    /// \brief ����������� ������, ����������� ���� �� ����� �� ���������� ����.
    ///
    /// \param path ���� � �����, ����������� ������ ��������� �����.
    AdjencyList(std::string path);

    /// \brief ����������� �����������.
    ///
    /// \param other ������ ������ AdjencyList, ������� ����� �����������.
    AdjencyList(const AdjencyList& other);

    /// \brief ����������� �����������.
    ///
    /// \param other ������ ������ AdjencyList, ������� ����� �����������.
    AdjencyList(AdjencyList&& other) noexcept;

    /// \brief �������� ������������ ��� �����������.
    ///
    /// \param other ������ ������ AdjencyList, ������� ����� �����������.
    /// \return ������ �� ������ ������ AdjencyList ����� ������������.
    AdjencyList& operator=(const AdjencyList& other);

    /// \brief �������� ������������ ��� �����������.
    ///
    /// \param other ������ ������ AdjencyList, ������� ����� �����������.
    /// \return ������ �� ������ ������ AdjencyList ����� ������������.
    AdjencyList& operator=(AdjencyList&& other) noexcept;

    /// \brief ����� ��� �������� ����� ����� ���������� ���������.
    ///
    /// \param start ��������� ������� �����.
    /// \param end �������� ������� �����.
    void removeEdge(int start, int end) override;
};