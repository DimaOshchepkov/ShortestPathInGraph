#pragma once

#pragma once

#include <string>
#include <vector>

using std::vector;
using std::string;

/// \brief Интерфейс IGraph представляет общий интерфейс для всех видов хранения графа в памяти компьютера.
///
/// Этот интерфейс определяет методы, которые должны быть реализованы в классах,
/// представляющих конкретные способы хранения графа, такие как список смежности или матрица смежности.
class IGraph {
public:
    /// \brief Виртуальный метод для получения длины ребра между указанными вершинами.
    ///
    /// \param from Начальная вершина.
    /// \param to Конечная вершина.
    /// \return Длина ребра между вершинами from и to. Если ребра нет, вернет -1
    virtual int length_form_to(int from, int to) const = 0;

    /// \brief Виртуальный метод для получения количества вершин в графе.
    ///
    /// \return Количество вершин в графе.
    virtual int countTop() const = 0;

    /// \brief Виртуальный метод для изменения веса ребра между указанными вершинами.
    ///
    /// \param from Начальная вершина ребра.
    /// \param to Конечная вершина ребра.
    /// \param value Новое значение веса ребра.
    virtual void changeEdge(int from, int to, int value) = 0;

    /// \brief Виртуальный метод для получения вектора смежных вершин для указанной вершины.
    ///
    /// \param vert Вершина, для которой требуется получить смежные вершины.
    /// \return Вектор смежных вершин для указанной вершины.
    virtual vector<int> getVectorNeighbors(int vert) = 0;

    /// \brief Виртуальный метод для удаления ребра между указанными вершинами.
    ///
    /// \param start Начальная вершина ребра.
    /// \param end Конечная вершина ребра.
    virtual void removeEdge(int start, int end) = 0;
};

/// \brief Класс AdjencyMatrix представляет реализацию интерфейса IGraph,
///        хранящую граф в виде матрицы смежности.
class AdjencyMatrix : public IGraph {
private:
    vector<vector<int>> matrix; /**< Матрица смежности графа. */

public:
    /// \brief Конструктор класса, загружающий граф из файла по указанному пути.
    ///
    /// \param path Полный путь к файлу, содержащему матрицу смежности графа.
    AdjencyMatrix(string path);

    /// \brief Конструктор копирования.
    ///
    /// \param other Объект класса AdjencyMatrix, который нужно скопировать.
    AdjencyMatrix(const AdjencyMatrix& other);

    /// \brief Конструктор перемещения.
    ///
    /// \param other Объект класса AdjencyMatrix, который нужно переместить.
    AdjencyMatrix(AdjencyMatrix&& other) noexcept;

    /// \brief Оператор присваивания для копирования.
    ///
    /// \param other Объект класса AdjencyMatrix, который нужно скопировать.
    /// \return Ссылка на объект класса AdjencyMatrix после присваивания.
    AdjencyMatrix& operator=(const AdjencyMatrix& other);

    /// \brief Оператор присваивания для перемещения.
    ///
    /// \param other Объект класса AdjencyMatrix, который нужно переместить.
    /// \return Ссылка на объект класса AdjencyMatrix после присваивания.
    AdjencyMatrix& operator=(AdjencyMatrix&& other) noexcept;

    /// \brief Конструктор класса, создающий пустую матрицу смежности для указанного количества вершин.
    ///
    /// \param countTop Количество вершин в графе.
    AdjencyMatrix(int countTop);

    /// \brief Метод для получения длины ребра между указанными вершинами.
    ///
    /// \param from Начальная вершина.
    /// \param to Конечная вершина.
    /// \return Длина ребра между вершинами from и to. Если ребра нет, вернет -1
    int length_form_to(int from, int to) const override;

    /// \brief Метод для получения количества вершин в графе.
    ///
    /// \return Количество вершин в графе.
    int countTop() const override;

    /// \brief Метод для изменения веса ребра между указанными вершинами.
    ///
    /// \param from Начальная вершина ребра.
    /// \param to Конечная вершина ребра.
    /// \param value Новое значение веса ребра.
    void changeEdge(int from, int to, int value) override;

    /// \brief Метод для получения вектора смежных вершин для указанной вершины.
    ///
    /// \param vert Вершина, для которой требуется получить смежные вершины.
    /// \return Вектор смежных вершин для указанной вершины.
    vector<int> getVectorNeighbors(int vert) override;

    /// \brief Метод для удаления ребра между указанными вершинами. Этот метод просто заменяет нужно поле
    /// на -1.
    ///
    /// \param start Начальная вершина ребра.
    /// \param end Конечная вершина ребра.
    void removeEdge(int start, int end) override;
};


/// \brief Класс AdjencyList представляет реализацию интерфейса IGraph,
///        хранящую граф в виде списка смежности.
class AdjencyList : public IGraph {
private:
    std::vector<std::vector<std::pair<int, int>>> adjacencyList; /**< Список смежности графа. */

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
    virtual int length_form_to(int from, int to) const override;

    /// \brief Виртуальный метод для изменения веса ребра между указанными вершинами.
    ///
    /// \param from Начальная вершина ребра.
    /// \param to Конечная вершина ребра.
    /// \param value Новое значение веса ребра.
    virtual void changeEdge(int from, int to, int value) override;

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