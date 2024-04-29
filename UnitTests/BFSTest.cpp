#include "pch.h"

#include <memory>
#include <iostream>
#include <fstream>
#include <random>
#include <vector>

using namespace std;


TEST(FindShortestPathTestBFS, getShortestPathBoolStorage) {
    AdjencyMatrix<bool> matrix(getProjectDir() + "\\graph57.txt");

    BFSPathManager<bool, AdjencyMatrix<bool>> manager(matrix, 0, 2);

    auto [length1, path1] = manager.getShortestPath();
    auto [length2, path2] = manager.getShortestPath();

    EXPECT_EQ(length1, 2);
    EXPECT_EQ(length2, 2);
}

TEST(FindShortestPathTestBFS, getNextShortestPathBoolStorage) {
    AdjencyMatrix<bool> matrix(getProjectDir() + "\\graph57.txt");

    BFSPathManager<bool, AdjencyMatrix<bool>> manager(matrix, 0, 4);

    auto [length1, path1] = manager.getNextShortestPath();
    auto [length2, path2] = manager.getNextShortestPath();
    auto [length3, path3] = manager.getNextShortestPath();
    auto [length4, path4] = manager.getNextShortestPath();

    EXPECT_EQ(length1, 1);
    EXPECT_EQ(length2, 2);
    EXPECT_EQ(length3, 3);
    EXPECT_EQ(length4, -1);
}

TEST(FindShortestPathTestBFS, getNextShortestPathBoolStorage_711) {
    AdjencyMatrix<bool> matrix(getProjectDir() + "\\graph711.txt");

    BFSPathManager<bool, AdjencyMatrix<bool>>manager(matrix, 0, 6);

    auto [length1, path1] = manager.getNextShortestPath();
    auto [length2, path2] = manager.getNextShortestPath();
    auto [length3, path3] = manager.getNextShortestPath();
    auto [length4, path4] = manager.getNextShortestPath();

    EXPECT_EQ(length1, 3);
    EXPECT_EQ(length2, 3);
    EXPECT_EQ(length3, -1);
    EXPECT_EQ(length4, -1);
}
