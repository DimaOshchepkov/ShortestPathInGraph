#include "pch.h"

#include <memory>

using namespace std;
TEST(FindShortestPathTest, getShortestPath) {
    AdjencyMatrix matrix(getProjectDir() + "\\graph57.txt");

    ShortestPathManager manager(make_shared<AdjencyMatrix>(matrix), 0, 4);

    auto [length1, path1] = manager.getShortestPath();
    auto [length2, path2] = manager.getShortestPath();

    EXPECT_EQ(length1, 60);
    EXPECT_EQ(length2, 60);
}



TEST(FindShortestPathTest, getNextShortestPath) {
    AdjencyMatrix matrix(getProjectDir() + "\\graph57.txt");

    ShortestPathManager manager(make_shared<AdjencyMatrix>(matrix), 0, 4);

    auto [length1, path1] = manager.getNextShortestPath();
    auto [length2, path2] = manager.getNextShortestPath();
    auto [length3, path3] = manager.getNextShortestPath();

    EXPECT_EQ(length1, 60);
    EXPECT_EQ(length2, 100);
    EXPECT_EQ(length3, -1);
}

TEST(FindShortestPathTest, getNextShortestPath2) {
    AdjencyMatrix matrix(getProjectDir() + "\\graph57.txt");

    ShortestPathManager manager(make_shared<AdjencyMatrix>(matrix), 0, 4);

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