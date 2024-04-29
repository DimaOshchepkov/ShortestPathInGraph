#include "pch.h"

#include <memory>
#include <iostream>
#include <fstream>
#include <random>
#include <vector>

using namespace std;

TEST(FindShortestPathTest, getShortestPath) {
    AdjencyMatrix<int> matrix(getProjectDir() + "\\graph57.txt");

    DijkstraPathManager<int, AdjencyMatrix<int>> manager(matrix, 0, 4);

    auto [length1, path1] = manager.getShortestPath();
    auto [length2, path2] = manager.getShortestPath();

    EXPECT_EQ(length1, 60);
    EXPECT_EQ(length2, 60);
}

TEST(FindShortestPathTest, getShortestPathBoolStorage) {
    AdjencyMatrix<bool> matrix(getProjectDir() + "\\graph57.txt");

    DijkstraPathManager<bool, AdjencyMatrix<bool>> manager(matrix, 0, 2);

    auto [length1, path1] = manager.getShortestPath();
    auto [length2, path2] = manager.getShortestPath();

    EXPECT_EQ(length1, 2);
    EXPECT_EQ(length2, 2);
}



TEST(FindShortestPathTest, getNextShortestPath) {
    AdjencyMatrix<int> matrix(getProjectDir() + "\\graph57.txt");

    DijkstraPathManager<int, AdjencyMatrix<int>> manager(matrix, 0, 4);

    auto [length1, path1] = manager.getNextShortestPath();
    auto [length2, path2] = manager.getNextShortestPath();
    auto [length3, path3] = manager.getNextShortestPath();

    EXPECT_EQ(length1, 60);
    EXPECT_EQ(length2, 100);
    EXPECT_EQ(length3, -1);
}

TEST(FindShortestPathTest, getNextShortestPathBoolStorage) {
    AdjencyMatrix<bool> matrix(getProjectDir() + "\\graph57.txt");

    DijkstraPathManager<bool, AdjencyMatrix<bool>> manager(matrix, 0, 4);

    auto [length1, path1] = manager.getNextShortestPath();
    auto [length2, path2] = manager.getNextShortestPath();
    auto [length3, path3] = manager.getNextShortestPath();
    auto [length4, path4] = manager.getNextShortestPath();

    EXPECT_EQ(length1, 1);
    EXPECT_EQ(length2, 2);
    EXPECT_EQ(length3, 3);
    EXPECT_EQ(length4, -1);
}

TEST(FindShortestPathTest, getNextShortestPath2) {
    AdjencyMatrix<int> matrix(getProjectDir() + "\\graph57.txt");

    DijkstraPathManager<int, AdjencyMatrix<int>> manager(matrix, 0, 4);

    auto [length1, path1] = manager.getNextShortestPath();
    auto [length2, path2] = manager.getNextShortestPath();
    auto [length3, path3] = manager.getNextShortestPath();

    EXPECT_EQ(length1, 60);
    EXPECT_EQ(length2, 100);
    EXPECT_EQ(length3, -1);

    auto [length4, path4] = manager.getShortestPath();
    auto [length5, path5] = manager.getNextShortestPath();

    EXPECT_EQ(length1, 60);
    EXPECT_EQ(length2, 100);
}




TEST(FindShortestPathTestAdjList, getShortestPathList) {
    AdjencyList<int> matrix(getProjectDir() + "\\graph57.txt");

    DijkstraPathManager<int, AdjencyList<int>> manager(matrix, 0, 4);

    auto [length1, path1] = manager.getShortestPath();
    auto [length2, path2] = manager.getShortestPath();

    EXPECT_EQ(length1, 60);
    EXPECT_EQ(length2, 60);
}



TEST(FindShortestPathTestAdjList, getNextShortestPathList) {
    AdjencyList<int> matrix(getProjectDir() + "\\graph57.txt");

    DijkstraPathManager<int, AdjencyList<int>> manager(matrix, 0, 4);

    auto [length1, path1] = manager.getNextShortestPath();
    auto [length2, path2] = manager.getNextShortestPath();
    auto [length3, path3] = manager.getNextShortestPath();

    EXPECT_EQ(length1, 60);
    EXPECT_EQ(length2, 100);
    EXPECT_EQ(length3, -1);
}

TEST(FindShortestPathTestAdjList, getNextShortestPathList2) {
    AdjencyList<int> matrix(getProjectDir() + "\\graph57.txt");

    DijkstraPathManager<int, AdjencyList<int>> manager(matrix, 0, 4);

    auto [length1, path1] = manager.getNextShortestPath();
    auto [length2, path2] = manager.getNextShortestPath();
    auto [length3, path3] = manager.getNextShortestPath();

    EXPECT_EQ(length1, 60);
    EXPECT_EQ(length2, 100);
    EXPECT_EQ(length3, -1);

    auto [length4, path4] = manager.getShortestPath();
    auto [length5, path5] = manager.getNextShortestPath();

    EXPECT_EQ(length1, 60);
    EXPECT_EQ(length2, 100);
}