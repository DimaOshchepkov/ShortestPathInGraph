#pragma once

#include "Graph.h"
#include <memory>
#include <vector>
#include <limits>

template<typename EdgeType>
class BasePathManager {
public: // TODO: ����� ���������� �� ������� � �������, ���� �� ���
    std::shared_ptr<IGraph<EdgeType>> graph; ///< ��������� �� ������ �����.
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
    BasePathManager(std::shared_ptr<IGraph<EdgeType>> graph, int startVertex, int endVertex);

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
template<typename EdgeType>
class DijkstraPathManager  final: public BasePathManager<EdgeType> {
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
    DijkstraPathManager(std::shared_ptr<IGraph<EdgeType>> graph, int startVertex, int endVertex);
};


template<typename EdgeType>
class BFSPathManager  final: public BasePathManager<EdgeType> {
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
    BFSPathManager(std::shared_ptr<IGraph<EdgeType>> graph, int startVertex, int endVertex);
};


