#pragma once

#include "Graph.h"
#include <memory>
#include <vector>
#include <limits>

/// \brief ����� ShortestPathManager ������������� �������� ��������� ��������
///        � ��������� ��������������� ��������� ���������� ���� � ����� ���������������,
///        �� ����� ���.
class ShortestPathManager {
private:
    std::shared_ptr<IGraph> graph; ///< ��������� �� ������ �����.
    std::vector<int> d; ///< ������ ���������� ���������� �� ��������� �������.
    std::vector<bool> visited; ///< ������, ���������� ���������� �������.
    int startVertex; ///< ��������� ������� ��� ������ ����������� ����.
    int endVertex; ///< �������� ������� ��� ������ ����������� ����.
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
    ShortestPathManager(std::shared_ptr<IGraph> graph, int startVertex, int endVertex);

    /// \brief ����� ��� ��������� ����������� ���� ����� ��������� � �������� ���������.
    /// ���������� ���������� ������� ���������� �����.
    ///
    /// \return ����, ���������� ����� ����������� ���� � ��� �������.
    std::pair<int, std::vector<int>> getShortestPath();

    /// \brief ����� ��� ��������� ���������� ����������� ���� ����� ��������� � �������� ���������.
    ///
    /// \return ����, ���������� ����� ����������� ���� � ��� �������.
    std::pair<int, std::vector<int>> getNextShortestPath();


    void resetEnv();
};

