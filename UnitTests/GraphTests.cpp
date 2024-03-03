#include "pch.h"

TEST(AdjencyMatrixTest, FileInput) {
    AdjencyMatrix matrix(getProjectDir() + "\\graph45.txt");

    ASSERT_EQ(matrix.length_form_to(0, 1), 10);
    ASSERT_EQ(matrix.length_form_to(0, 2), 15);
    ASSERT_EQ(matrix.length_form_to(1, 2), 20);
    ASSERT_EQ(matrix.length_form_to(2, 3), 5);
    ASSERT_EQ(matrix.length_form_to(3, 1), 7);
}

// Тест для проверки бросания исключения при неверных индексах вершин
TEST(AdjencyMatrixTest, InvalidVertexIndices) {
    AdjencyMatrix matrix(getProjectDir() + "\\graph45.txt");

    // Проверка бросания исключения при неверном индексе "from"
    ASSERT_THROW(matrix.length_form_to(-1, 1), std::runtime_error);
    ASSERT_THROW(matrix.length_form_to(4, 1), std::runtime_error);

    // Проверка бросания исключения при неверном индексе "to"
    ASSERT_THROW(matrix.length_form_to(0, -1), std::runtime_error);
    ASSERT_THROW(matrix.length_form_to(0, 4), std::runtime_error);
}

TEST(AdjencyMatrixTest, NoEdgeExists) {
    AdjencyMatrix matrix(getProjectDir() + "\\graph45.txt");

    // Проверка возврата -1 при отсутствии связи между вершинами
    ASSERT_EQ(matrix.length_form_to(0, 3), -1);  // Нет связи между 0 и 3
    ASSERT_EQ(matrix.length_form_to(1, 3), -1);  // Нет связи между 1 и 3
    ASSERT_EQ(matrix.length_form_to(3, 0), -1);  // Нет связи между 3 и 0
}

TEST(AdjencyMatrixTest, ListFileInput) {
    AdjencyList matrix(getProjectDir() + "\\graph45.txt");

    ASSERT_EQ(matrix.length_form_to(0, 1), 10);
    ASSERT_EQ(matrix.length_form_to(0, 2), 15);
    ASSERT_EQ(matrix.length_form_to(1, 2), 20);
    ASSERT_EQ(matrix.length_form_to(2, 3), 5);
    ASSERT_EQ(matrix.length_form_to(3, 1), 7);
}

// Тест для проверки бросания исключения при неверных индексах вершин
TEST(AdjacencyListTest, ListInvalidVertexIndices) {
    AdjencyList matrix(getProjectDir() + "\\graph45.txt");

    // Проверка бросания исключения при неверном индексе "from"
    ASSERT_THROW(matrix.length_form_to(-1, 1), std::runtime_error);
    ASSERT_THROW(matrix.length_form_to(4, 1), std::runtime_error);

    // Проверка бросания исключения при неверном индексе "to"
    ASSERT_THROW(matrix.length_form_to(0, -1), std::runtime_error);
    ASSERT_THROW(matrix.length_form_to(0, 4), std::runtime_error);
}

TEST(AdjacencyListTest, ListNoEdgeExists) {
    AdjencyList matrix(getProjectDir() + "\\graph45.txt");

    // Проверка возврата -1 при отсутствии связи между вершинами
    ASSERT_EQ(matrix.length_form_to(0, 3), -1);  // Нет связи между 0 и 3
    ASSERT_EQ(matrix.length_form_to(1, 3), -1);  // Нет связи между 1 и 3
    ASSERT_EQ(matrix.length_form_to(3, 0), -1);  // Нет связи между 3 и 0
}