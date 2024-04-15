#pragma once

#include <vector>
#include <string>
#include "Graph.h"

template<>
class AdjencyList<bool>  final: public IGraph<bool> {
private:
    std::vector<std::vector<int>> adjacencyList; /**< ������ ��������� �����. */

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
    virtual bool length_form_to(int from, int to) const override;

    /// \brief ����������� ����� ��� ��������� ���� ����� ����� ���������� ���������.
    ///
    /// \param from ��������� ������� �����.
    /// \param to �������� ������� �����.
    /// \param value ����� �������� ���� �����.
    virtual void changeEdge(int from, int to, bool value) override;

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