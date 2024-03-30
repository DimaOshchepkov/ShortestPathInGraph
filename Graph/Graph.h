#pragma once


#include <string>
#include <vector>

using std::vector;
using std::string;

/// \brief ��������� IGraph ������������ ����� ��������� ��� ���� ����� �������� ����� � ������ ����������.
///
/// ���� ��������� ���������� ������, ������� ������ ���� ����������� � �������,
/// �������������� ���������� ������� �������� �����, ����� ��� ������ ��������� ��� ������� ���������.
template<typename EdgeType>
class IGraph {
public:
    /// \brief ����������� ����� ��� ��������� ����� ����� ����� ���������� ���������.
    ///
    /// \param from ��������� �������.
    /// \param to �������� �������.
    /// \return ����� ����� ����� ��������� from � to. ���� ����� ���, ������ -1
    virtual EdgeType length_form_to(int from, int to) const = 0;

    /// \brief ����������� ����� ��� ��������� ���������� ������ � �����.
    ///
    /// \return ���������� ������ � �����.
    virtual int countTop() const = 0;

    /// \brief ����������� ����� ��� ��������� ���� ����� ����� ���������� ���������.
    ///
    /// \param from ��������� ������� �����.
    /// \param to �������� ������� �����.
    /// \param value ����� �������� ���� �����.
    virtual void changeEdge(int from, int to, EdgeType value) = 0;

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
template<typename EdgeType>
class AdjencyMatrix : public IGraph<EdgeType>{
private:
    vector<vector<EdgeType>> matrix; /**< ������� ��������� �����. */

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
    EdgeType length_form_to(int from, int to) const override;

    /// \brief ����� ��� ��������� ���������� ������ � �����.
    ///
    /// \return ���������� ������ � �����.
    int countTop() const override;

    /// \brief ����� ��� ��������� ���� ����� ����� ���������� ���������.
    ///
    /// \param from ��������� ������� �����.
    /// \param to �������� ������� �����.
    /// \param value ����� �������� ���� �����.
    void changeEdge(int from, int to, EdgeType value) override;

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
template<typename EdgeType>
class AdjencyList : public IGraph<EdgeType>{
private:
    std::vector<std::vector<std::pair<int, EdgeType>>> adjacencyList; /**< ������ ��������� �����. */

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
    virtual EdgeType length_form_to(int from, int to) const override;

    /// \brief ����������� ����� ��� ��������� ���� ����� ����� ���������� ���������.
    ///
    /// \param from ��������� ������� �����.
    /// \param to �������� ������� �����.
    /// \param value ����� �������� ���� �����.
    virtual void changeEdge(int from, int to, EdgeType value) override;

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




