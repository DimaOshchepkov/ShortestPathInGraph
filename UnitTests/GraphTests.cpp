#include "pch.h"

TEST(AdjencyMatrixTest, FileInput) {
    AdjencyMatrix<int> matrix(getProjectDir() + "\\graph45.txt");

    ASSERT_EQ(matrix.length_form_to(0, 1), 10);
    ASSERT_EQ(matrix.length_form_to(0, 2), 15);
    ASSERT_EQ(matrix.length_form_to(1, 2), 20);
    ASSERT_EQ(matrix.length_form_to(2, 3), 5);
    ASSERT_EQ(matrix.length_form_to(3, 1), 7);
}

TEST(AdjencyMatrixTestDoubleStorage, FileInput) {
    AdjencyMatrix<double> matrix(getProjectDir() + "\\graph45.txt");

    ASSERT_DOUBLE_EQ(matrix.length_form_to(0, 1), 10);
    ASSERT_DOUBLE_EQ(matrix.length_form_to(0, 2), 15);
    ASSERT_DOUBLE_EQ(matrix.length_form_to(1, 2), 20);
    ASSERT_DOUBLE_EQ(matrix.length_form_to(2, 3), 5);
    ASSERT_DOUBLE_EQ(matrix.length_form_to(3, 1), 7);
}

TEST(AdjencyMatrixTestBoolStorage, FileInput) {
    AdjencyMatrix<bool> matrix(getProjectDir() + "\\graph45.txt");

    ASSERT_EQ(matrix.length_form_to(0, 1), true);
    ASSERT_EQ(matrix.length_form_to(0, 2), true);
    ASSERT_EQ(matrix.length_form_to(1, 2), true);
    ASSERT_EQ(matrix.length_form_to(2, 3), true);
    ASSERT_EQ(matrix.length_form_to(3, 1), true);
}

TEST(AdjencyMatrixTest, InvalidVertexIndices) {
    AdjencyMatrix<int> matrix(getProjectDir() + "\\graph45.txt");

    ASSERT_THROW(matrix.length_form_to(-1, 1), std::runtime_error);
    ASSERT_THROW(matrix.length_form_to(4, 1), std::runtime_error);

    ASSERT_THROW(matrix.length_form_to(0, -1), std::runtime_error);
    ASSERT_THROW(matrix.length_form_to(0, 4), std::runtime_error);
}

TEST(AdjencyMatrixTestBoolStorage, InvalidVertexIndices) {
    AdjencyMatrix<bool> matrix(getProjectDir() + "\\graph45.txt");

    ASSERT_THROW(matrix.length_form_to(-1, 1), std::runtime_error);
    ASSERT_THROW(matrix.length_form_to(4, 1), std::runtime_error);

    ASSERT_THROW(matrix.length_form_to(0, -1), std::runtime_error);
    ASSERT_THROW(matrix.length_form_to(0, 4), std::runtime_error);
}

TEST(AdjencyMatrixTest, NoEdgeExists) {
    AdjencyMatrix<int> matrix(getProjectDir() + "\\graph45.txt");

    ASSERT_EQ(matrix.length_form_to(0, 3), 0);  
    ASSERT_EQ(matrix.length_form_to(1, 3), 0);  
    ASSERT_EQ(matrix.length_form_to(3, 0), 0); 
}

TEST(AdjencyMatrixTestBoolStorage, NoEdgeExists) {
    AdjencyMatrix<bool> matrix(getProjectDir() + "\\graph45.txt");

    ASSERT_EQ(matrix.length_form_to(0, 3), false);
    ASSERT_EQ(matrix.length_form_to(1, 3), false);
    ASSERT_EQ(matrix.length_form_to(3, 0), false);
}

TEST(AdjencyMatrixTest, ListFileInput) {
    AdjencyList<int> matrix(getProjectDir() + "\\graph45.txt");

    ASSERT_EQ(matrix.length_form_to(0, 1), 10);
    ASSERT_EQ(matrix.length_form_to(0, 2), 15);
    ASSERT_EQ(matrix.length_form_to(1, 2), 20);
    ASSERT_EQ(matrix.length_form_to(2, 3), 5);
    ASSERT_EQ(matrix.length_form_to(3, 1), 7);
}

TEST(AdjencyMatrixTestBoolStorage, ListFileInput) {
    AdjencyList<bool> matrix(getProjectDir() + "\\graph45.txt");

    ASSERT_EQ(matrix.length_form_to(0, 1), true);
    ASSERT_EQ(matrix.length_form_to(0, 2), true);
    ASSERT_EQ(matrix.length_form_to(1, 2), true);
    ASSERT_EQ(matrix.length_form_to(2, 3), true);
    ASSERT_EQ(matrix.length_form_to(3, 1), true);
}

TEST(AdjacencyListTest, ListInvalidVertexIndices) {
    AdjencyList<int> matrix(getProjectDir() + "\\graph45.txt");

    ASSERT_THROW(matrix.length_form_to(-1, 1), std::runtime_error);
    ASSERT_THROW(matrix.length_form_to(4, 1), std::runtime_error);

    ASSERT_THROW(matrix.length_form_to(0, -1), std::runtime_error);
    ASSERT_THROW(matrix.length_form_to(0, 4), std::runtime_error);
}

TEST(AdjacencyListTest, ListNoEdgeExists) {
    AdjencyList<int> matrix(getProjectDir() + "\\graph45.txt");

    ASSERT_EQ(matrix.length_form_to(0, 3), 0);  
    ASSERT_EQ(matrix.length_form_to(1, 3), 0);  
    ASSERT_EQ(matrix.length_form_to(3, 0), 0);  
}

TEST(AdjacencyListTestBoolStorage, ListNoEdgeExists) {
    AdjencyList<bool> matrix(getProjectDir() + "\\graph45.txt");

    ASSERT_EQ(matrix.length_form_to(0, 3), false);
    ASSERT_EQ(matrix.length_form_to(1, 3), false);
    ASSERT_EQ(matrix.length_form_to(3, 0), false);
}


TEST(AdjencyMapTest, ListFileInput) {
    AdjencyMap<int> matrix(getProjectDir() + "\\graph45.txt");

    ASSERT_EQ(matrix.length_form_to(0, 1), 10);
    ASSERT_EQ(matrix.length_form_to(0, 2), 15);
    ASSERT_EQ(matrix.length_form_to(1, 2), 20);
    ASSERT_EQ(matrix.length_form_to(2, 3), 5);
    ASSERT_EQ(matrix.length_form_to(3, 1), 7);
}