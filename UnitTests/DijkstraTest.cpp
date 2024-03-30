#include "pch.h"

#include <memory>
#include <iostream>
#include <fstream>
#include <random>
#include <vector>

using namespace std;

TEST(FindShortestPathTest, getShortestPath) {
    AdjencyMatrix<int> matrix(getProjectDir() + "\\graph57.txt");

    DijkstraPathManager<int> manager(make_shared<AdjencyMatrix<int>>(matrix), 0, 4);

    auto [length1, path1] = manager.getShortestPath();
    auto [length2, path2] = manager.getShortestPath();

    EXPECT_EQ(length1, 60);
    EXPECT_EQ(length2, 60);
}



TEST(FindShortestPathTest, getNextShortestPath) {
    AdjencyMatrix<int> matrix(getProjectDir() + "\\graph57.txt");

    DijkstraPathManager<int> manager(make_shared<AdjencyMatrix<int>>(matrix), 0, 4);

    auto [length1, path1] = manager.getNextShortestPath();
    auto [length2, path2] = manager.getNextShortestPath();
    auto [length3, path3] = manager.getNextShortestPath();

    EXPECT_EQ(length1, 60);
    EXPECT_EQ(length2, 100);
    EXPECT_EQ(length3, -1);
}

TEST(FindShortestPathTest, getNextShortestPath2) {
    AdjencyMatrix<int> matrix(getProjectDir() + "\\graph57.txt");

    DijkstraPathManager<int> manager(make_shared<AdjencyMatrix<int>>(matrix), 0, 4);

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

    DijkstraPathManager<int> manager(make_shared<AdjencyList<int>>(matrix), 0, 4);

    auto [length1, path1] = manager.getShortestPath();
    auto [length2, path2] = manager.getShortestPath();

    EXPECT_EQ(length1, 60);
    EXPECT_EQ(length2, 60);
}



TEST(FindShortestPathTestAdjList, getNextShortestPathList) {
    AdjencyList<int> matrix(getProjectDir() + "\\graph57.txt");

    DijkstraPathManager<int> manager(make_shared<AdjencyList<int>>(matrix), 0, 4);

    auto [length1, path1] = manager.getNextShortestPath();
    auto [length2, path2] = manager.getNextShortestPath();
    auto [length3, path3] = manager.getNextShortestPath();

    EXPECT_EQ(length1, 60);
    EXPECT_EQ(length2, 100);
    EXPECT_EQ(length3, -1);
}

TEST(FindShortestPathTestAdjList, getNextShortestPathList2) {
    AdjencyList<int> matrix(getProjectDir() + "\\graph57.txt");

    DijkstraPathManager<int> manager(make_shared<AdjencyList<int>>(matrix), 0, 4);

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