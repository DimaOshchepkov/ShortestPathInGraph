#pragma once

#include "Graph.h"
#include <memory>
#include <vector>
#include <limits>

template<typename EdgeType>
class BasePathManager {
public: // TODO: Нужно переделать на геттеры и сеттеры, если по уму
    std::shared_ptr<IGraph<EdgeType>> graph; ///< Указатель на объект графа.
    std::vector<int> d; ///< Вектор кратчайших расстояний от стартовой вершины.
    std::vector<bool> visited; ///< Вектор, отмечающий посещенные вершины.
    int startVertex; ///< Начальная вершина для поиска кратчайшего пути.
    int endVertex; ///< Конечная вершина для поиска кратчайшего пути.
    std::vector<bool> banned;
    std::pair<int, std::vector<int>> length_path_of_two_vertices; ///< Длина и путь кратчайшего пути между двумя вершинами.

    /// \brief Приватный метод для получения кратчайшего пути между указанными вершинами.
    ///
    /// \param startVertex Начальная вершина пути.
    /// \param endVertex Конечная вершина пути.
    /// \return Пара, содержащая длину кратчайшего пути и его маршрут.
    virtual std::pair<int, std::vector<int>> __getShortestPath(int startVertex, int endVertex) = 0;

public:
    /// \brief Конструктор класса ShortestPathManager.
    ///
    /// \param graph Указатель на объект графа.
    /// \param startVertex Начальная вершина для поиска кратчайшего пути.
    /// \param endVertex Конечная вершина для поиска кратчайшего пути.
    BasePathManager(std::shared_ptr<IGraph<EdgeType>> graph, int startVertex, int endVertex);

    /// \brief Метод для получения кратчайшего пути между начальной и конечной вершинами.
    /// Сбрасывает предыдущую цепочку кратчайших путей.
    ///
    /// \return Пара, содержащая длину кратчайшего пути и его маршрут.
    std::pair<int, std::vector<int>> getShortestPath();

    /// \brief Метод для получения следующего кратчайшего пути между начальной и конечной вершинами.
    ///
    /// \return Пара, содержащая длину кратчайшего пути и его маршрут.
    std::pair<int, std::vector<int>> getNextShortestPath();
};

/// \brief Класс ShortestPathManager инкапсулирует контекст алгоритма Дейкстры
///        и позволяет последовательно вычленять кратчайшие пути в графе последовательно,
///        не меняя его.
template<typename EdgeType>
class DijkstraPathManager  final: public BasePathManager<EdgeType> {
private:
    /// \brief Приватный метод для получения кратчайшего пути между указанными вершинами.
    ///
    /// \param startVertex Начальная вершина пути.
    /// \param endVertex Конечная вершина пути.
    /// \return Пара, содержащая длину кратчайшего пути и его маршрут.
    virtual std::pair<int, std::vector<int>> __getShortestPath(int startVertex, int endVertex) override;

public:
    /// \brief Конструктор класса ShortestPathManager.
    ///
    /// \param graph Указатель на объект графа.
    /// \param startVertex Начальная вершина для поиска кратчайшего пути.
    /// \param endVertex Конечная вершина для поиска кратчайшего пути.
    DijkstraPathManager(std::shared_ptr<IGraph<EdgeType>> graph, int startVertex, int endVertex);
};


template<typename EdgeType>
class BFSPathManager  final: public BasePathManager<EdgeType> {
private:
    /// \brief Приватный метод для получения кратчайшего пути между указанными вершинами.
    ///
    /// \param startVertex Начальная вершина пути.
    /// \param endVertex Конечная вершина пути.
    /// \return Пара, содержащая длину кратчайшего пути и его маршрут.
    virtual std::pair<int, std::vector<int>> __getShortestPath(int startVertex, int endVertex) override;

public:
    /// \brief Конструктор класса ShortestPathManager.
    ///
    /// \param graph Указатель на объект графа.
    /// \param startVertex Начальная вершина для поиска кратчайшего пути.
    /// \param endVertex Конечная вершина для поиска кратчайшего пути.
    BFSPathManager(std::shared_ptr<IGraph<EdgeType>> graph, int startVertex, int endVertex);
};


