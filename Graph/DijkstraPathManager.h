#pragma once

#include "Graph.h"
#include <memory>
#include <vector>
#include <limits>

/// \brief ����� ShortestPathManager ������������� �������� ��������� ��������
///        � ��������� ��������������� ��������� ���������� ���� � ����� ���������������,
///        �� ����� ���.

template<typename EdgeType>
class DijkstraPathManager {
private:
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
    std::pair<int, std::vector<int>> __getShortestPath(int startVertex, int endVertex);

public:
    /// \brief ����������� ������ ShortestPathManager.
    ///
    /// \param graph ��������� �� ������ �����.
    /// \param startVertex ��������� ������� ��� ������ ����������� ����.
    /// \param endVertex �������� ������� ��� ������ ����������� ����.
    DijkstraPathManager(std::shared_ptr<IGraph<EdgeType>> graph, int startVertex, int endVertex);

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

