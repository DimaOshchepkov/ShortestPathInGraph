#pragma once

#include <vector>
#include <string>
#include "Graph.h"

template<>
class AdjencyList<bool>  final: public IGraph<bool> {
private:
    std::vector<std::vector<int>> adjacencyList; /**< Список смежности графа. */

public:
    /// \brief Конструктор класса, создающий пустой список смежности для указанного количества вершин.
    ///
    /// \param vertices Количество вершин в графе.
    AdjencyList(int vertices);

    /// \brief Виртуальный метод для получения количества вершин в графе.
    ///
    /// \return Количество вершин в графе.
    virtual int countTop() const override;

    /// \brief Виртуальный метод для получения длины ребра между указанными вершинами.
    ///
    /// \param from Начальная вершина.
    /// \param to Конечная вершина.
    /// \return Длина ребра между вершинами from и to. Если вершины нет, вернет -1.
    virtual bool length_form_to(int from, int to) const override;

    /// \brief Виртуальный метод для изменения веса ребра между указанными вершинами.
    ///
    /// \param from Начальная вершина ребра.
    /// \param to Конечная вершина ребра.
    /// \param value Новое значение веса ребра.
    virtual void changeEdge(int from, int to, bool value) override;

    /// \brief Виртуальный метод для получения вектора смежных вершин для указанной вершины.
    ///
    /// \param vert Вершина, для которой требуется получить смежные вершины.
    /// \return Вектор смежных вершин для указанной вершины.
    virtual std::vector<int> getVectorNeighbors(int vert) override;

    /// \brief Конструктор класса, загружающий граф из файла по указанному пути.
    ///
    /// \param path Путь к файлу, содержащему список смежности графа.
    AdjencyList(std::string path);

    /// \brief Конструктор копирования.
    ///
    /// \param other Объект класса AdjencyList, который нужно скопировать.
    AdjencyList(const AdjencyList& other);

    /// \brief Конструктор перемещения.
    ///
    /// \param other Объект класса AdjencyList, который нужно переместить.
    AdjencyList(AdjencyList&& other) noexcept;

    /// \brief Оператор присваивания для копирования.
    ///
    /// \param other Объект класса AdjencyList, который нужно скопировать.
    /// \return Ссылка на объект класса AdjencyList после присваивания.
    AdjencyList& operator=(const AdjencyList& other);

    /// \brief Оператор присваивания для перемещения.
    ///
    /// \param other Объект класса AdjencyList, который нужно переместить.
    /// \return Ссылка на объект класса AdjencyList после присваивания.
    AdjencyList& operator=(AdjencyList&& other) noexcept;

    /// \brief Метод для удаления ребра между указанными вершинами.
    ///
    /// \param start Начальная вершина ребра.
    /// \param end Конечная вершина ребра.
    void removeEdge(int start, int end) override;
};