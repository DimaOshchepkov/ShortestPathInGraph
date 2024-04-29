#pragma once

#include "Graph.h"
#include <memory>
#include <vector>
#include <limits>

#include <type_traits>


template<class Derived, class Base>
concept IsDerivedFrom = std::is_base_of_v<Base, Derived>;

template<typename T>
concept NumericOrBool = std::is_arithmetic_v<T> || std::is_same_v<T, bool>;

template<NumericOrBool EdgeType, IsDerivedFrom<IGraph<EdgeType>> Graph>
class BasePathManager {
public: // TODO: ����� ���������� �� ������� � �������, ���� �� ���
    Graph& graph; ///< ������ �� ������ �����.
    std::vector<int> d; ///< ������ ���������� ���������� �� ��������� �������.
    std::vector<bool> visited; ///< ������, ���������� ���������� �������.
    int startVertex; ///< ��������� ������� ��� ������ ����������� ����.
    int endVertex; ///< �������� ������� ��� ������ ����������� ����.
    std::vector<bool> banned;
    std::pair<int, std::vector<int>> length_path_of_two_vertices; ///< ����� � ���� ����������� ���� ����� ����� ���������.

    /// \brief ��������� ����� ��� ��������� ����������� ���� ����� ���������� ���������.
    ///
    /// \param startVertex ��������� ������� ����.
    /// \param endVertex �������� ������� ����.
    /// \return ����, ���������� ����� ����������� ���� � ��� �������.
    virtual std::pair<int, std::vector<int>> __getShortestPath(int startVertex, int endVertex) = 0;

public:
    /// \brief ����������� ������ ShortestPathManager.
    ///
    /// \param graph ��������� �� ������ �����.
    /// \param startVertex ��������� ������� ��� ������ ����������� ����.
    /// \param endVertex �������� ������� ��� ������ ����������� ����.
    BasePathManager(Graph& graph, int startVertex, int endVertex);

    /// \brief ����� ��� ��������� ����������� ���� ����� ��������� � �������� ���������.
    /// ���������� ���������� ������� ���������� �����.
    ///
    /// \return ����, ���������� ����� ����������� ���� � ��� �������.
    std::pair<int, std::vector<int>> getShortestPath();

    /// \brief ����� ��� ��������� ���������� ����������� ���� ����� ��������� � �������� ���������.
    ///
    /// \return ����, ���������� ����� ����������� ���� � ��� �������.
    std::pair<int, std::vector<int>> getNextShortestPath();
};

/// \brief ����� ShortestPathManager ������������� �������� ��������� ��������
///        � ��������� ��������������� ��������� ���������� ���� � ����� ���������������,
///        �� ����� ���.
template<NumericOrBool EdgeType, IsDerivedFrom<IGraph<EdgeType>> Graph>
class DijkstraPathManager  final: public BasePathManager<EdgeType, Graph> {
private:
    /// \brief ��������� ����� ��� ��������� ����������� ���� ����� ���������� ���������.
    ///
    /// \param startVertex ��������� ������� ����.
    /// \param endVertex �������� ������� ����.
    /// \return ����, ���������� ����� ����������� ���� � ��� �������.
    virtual std::pair<int, std::vector<int>> __getShortestPath(int startVertex, int endVertex) override;

public:
    /// \brief ����������� ������ ShortestPathManager.
    ///
    /// \param graph ��������� �� ������ �����.
    /// \param startVertex ��������� ������� ��� ������ ����������� ����.
    /// \param endVertex �������� ������� ��� ������ ����������� ����.
    DijkstraPathManager(Graph& graph, int startVertex, int endVertex);
};


template<NumericOrBool EdgeType, IsDerivedFrom<IGraph<EdgeType>> Graph>
class BFSPathManager  final: public BasePathManager<EdgeType, Graph> {
private:
    /// \brief ��������� ����� ��� ��������� ����������� ���� ����� ���������� ���������.
    ///
    /// \param startVertex ��������� ������� ����.
    /// \param endVertex �������� ������� ����.
    /// \return ����, ���������� ����� ����������� ���� � ��� �������.
    virtual std::pair<int, std::vector<int>> __getShortestPath(int startVertex, int endVertex) override;

public:
    /// \brief ����������� ������ ShortestPathManager.
    ///
    /// \param graph ��������� �� ������ �����.
    /// \param startVertex ��������� ������� ��� ������ ����������� ����.
    /// \param endVertex �������� ������� ��� ������ ����������� ����.
    BFSPathManager(Graph& graph, int startVertex, int endVertex);
};


