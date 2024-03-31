#include <Benchmark/benchmark.h>
#include <memory>
#include <iostream>
#include <string>

#include "DijkstraPathManager.h" 
#include "DijkstraPathManager.cpp" 

#include "Graph.h"
#include "Graph.cpp"

using namespace std;


#define STRINGIFY(x) #x

#define EXPAND(x) STRINGIFY(x)

string projectDir;

string getProjectDir() {
    if (!projectDir.empty())
        return projectDir;
    string s = EXPAND(UNITTESTPRJ);
    s.erase(0, 1); // erase the first quote
    s.erase(s.size() - 2); // erase the last quote and the dot
    projectDir = s;
    return projectDir;
}

string solutionDir;
string getSolutionDir() {
    if (!solutionDir.empty())
        return solutionDir;
    string s = EXPAND(UNITTESTPRJ);
    s.erase(0, 1); // erase the first quote
    s.erase(s.size() - 2); // erase the last quote and the dot

    // Находим позицию последнего символа '\'
    size_t found = s.find_last_of('\\');

    // Если найден символ '\', обрезаем строку по этой позиции
    if (found != std::string::npos) {
        s = s.substr(0, found);
    }

    solutionDir = s;
    return solutionDir;
}


static void BM_Dijkstra_AdjMatrix(benchmark::State& state, const std::string& graphFileName, int from, int to) {
    AdjencyMatrix<int> matrix(getSolutionDir() + "\\" + graphFileName);
    DijkstraPathManager<int> manager(std::make_shared<AdjencyMatrix<int>>(matrix), from, to);
    auto [length, path] = manager.getShortestPath();

    for (auto _ : state) {
        for (int i = 0; i < 4; i++) {
            auto res = manager.getNextShortestPath();
            benchmark::DoNotOptimize(res);
            if (res.first == -1) {
                std::cout << "Path is not exist!\n";
            }
        }
        benchmark::DoNotOptimize(manager.getShortestPath());
    }
}


BENCHMARK_CAPTURE(BM_Dijkstra_AdjMatrix, graph_2048_random_25persent_prob, "../Graphs/graph2048_random_25persent_prob.txt", 0, 89)->Unit(benchmark::kMillisecond);
BENCHMARK_CAPTURE(BM_Dijkstra_AdjMatrix, graph_4096_random_25persent_prob, "../Graphs/graph4096_random_25persent_prob.txt", 0, 89)->Unit(benchmark::kMillisecond);
BENCHMARK_CAPTURE(BM_Dijkstra_AdjMatrix, graph_8192_random_25persent_prob, "../Graphs/graph8192_random_25persent_prob.txt", 0, 89)->Unit(benchmark::kMillisecond);

BENCHMARK_CAPTURE(BM_Dijkstra_AdjMatrix, graph_2048_random_50persent_prob, "../Graphs/graph2048_random_50persent_prob.txt", 0, 89)->Unit(benchmark::kMillisecond);
BENCHMARK_CAPTURE(BM_Dijkstra_AdjMatrix, graph_4096_random_50persent_prob, "../Graphs/graph4096_random_50persent_prob.txt", 0, 89)->Unit(benchmark::kMillisecond);
BENCHMARK_CAPTURE(BM_Dijkstra_AdjMatrix, graph_8192_random_50persent_prob, "../Graphs/graph8192_random_50persent_prob.txt", 0, 89)->Unit(benchmark::kMillisecond);

BENCHMARK_CAPTURE(BM_Dijkstra_AdjMatrix, grid_graph_16, "../Graphs/grid_graph16.txt", 17, 254)->Unit(benchmark::kMillisecond);
BENCHMARK_CAPTURE(BM_Dijkstra_AdjMatrix, grid_graph_32, "../Graphs/grid_graph32.txt", 33, 1022)->Unit(benchmark::kMillisecond);
BENCHMARK_CAPTURE(BM_Dijkstra_AdjMatrix, grid_graph_64, "../Graphs/grid_graph64.txt", 160, 4094)->Unit(benchmark::kMillisecond);

BENCHMARK_CAPTURE(BM_Dijkstra_AdjMatrix, graph_100, "../Graphs/graph100.txt", 0, 89)->Unit(benchmark::kMillisecond);
BENCHMARK_CAPTURE(BM_Dijkstra_AdjMatrix, graph_50, "../Graphs/graph50.txt", 0, 30)->Unit(benchmark::kMillisecond);


static void BM_Dijkstra_AdjList(benchmark::State& state, const std::string& graphFileName, int from, int to) {

    AdjencyList<int> matrix(getSolutionDir() + "\\" + graphFileName);
    DijkstraPathManager<int> manager(make_shared<AdjencyList<int>>(matrix), from, to);
    auto [length, path] = manager.getShortestPath();

    for (auto _ : state) {
        for (int i = 0; i < 4; i++) {
            auto res = manager.getNextShortestPath();
            benchmark::DoNotOptimize(res);
            if (res.first == -1) {
                std::cout << "Path is not exist!\n";
            }
        }
        benchmark::DoNotOptimize(manager.getShortestPath());
    }
}

BENCHMARK_CAPTURE(BM_Dijkstra_AdjList, graph_2048_random_25persent_prob, "../Graphs/graph2048_random_25persent_prob.txt", 0, 89)->Unit(benchmark::kMillisecond);
BENCHMARK_CAPTURE(BM_Dijkstra_AdjList, graph_4096_random_25persent_prob, "../Graphs/graph4096_random_25persent_prob.txt", 0, 89)->Unit(benchmark::kMillisecond);
BENCHMARK_CAPTURE(BM_Dijkstra_AdjList, graph_8192_random_25persent_prob, "../Graphs/graph8192_random_25persent_prob.txt", 0, 89)->Unit(benchmark::kMillisecond);

BENCHMARK_CAPTURE(BM_Dijkstra_AdjList, graph_2048_random_50persent_prob, "../Graphs/graph2048_random_50persent_prob.txt", 0, 89)->Unit(benchmark::kMillisecond);
BENCHMARK_CAPTURE(BM_Dijkstra_AdjList, graph_4096_random_50persent_prob, "../Graphs/graph4096_random_50persent_prob.txt", 0, 89)->Unit(benchmark::kMillisecond);
BENCHMARK_CAPTURE(BM_Dijkstra_AdjList, graph_8192_random_50persent_prob, "../Graphs/graph8192_random_50persent_prob.txt", 0, 89)->Unit(benchmark::kMillisecond);

BENCHMARK_CAPTURE(BM_Dijkstra_AdjList, grid_graph_16, "../Graphs/grid_graph16.txt", 17, 254)->Unit(benchmark::kMillisecond);
BENCHMARK_CAPTURE(BM_Dijkstra_AdjList, grid_graph_32, "../Graphs/grid_graph32.txt", 33, 1022)->Unit(benchmark::kMillisecond);
BENCHMARK_CAPTURE(BM_Dijkstra_AdjList, grid_graph_64, "../Graphs/grid_graph64.txt", 160, 4094)->Unit(benchmark::kMillisecond);

BENCHMARK_CAPTURE(BM_Dijkstra_AdjList, graph_100, "../Graphs/graph100.txt", 0, 89)->Unit(benchmark::kMillisecond);
BENCHMARK_CAPTURE(BM_Dijkstra_AdjList, graph_50, "../Graphs/graph50.txt", 0, 30)->Unit(benchmark::kMillisecond);


static void BM_BFS_AdjMatrix(benchmark::State& state, const std::string& graphFileName, int from, int to) {
    AdjencyMatrix<int> matrix(getSolutionDir() + "\\" + graphFileName);
    BFSPathManager<int> manager(std::make_shared<AdjencyMatrix<int>>(matrix), from, to);
    auto [length, path] = manager.getShortestPath();

    for (auto _ : state) {
        for (int i = 0; i < 4; i++) {
            auto res = manager.getNextShortestPath();
            benchmark::DoNotOptimize(res);
            if (res.first == -1) {
                std::cout << "Path is not exist!\n";
            }
        }
        benchmark::DoNotOptimize(manager.getShortestPath());
    }
}

BENCHMARK_CAPTURE(BM_BFS_AdjMatrix, graph_2048_random_25persent_prob, "../Graphs/graph2048_random_25persent_prob.txt", 0, 89)->Unit(benchmark::kMillisecond);
BENCHMARK_CAPTURE(BM_BFS_AdjMatrix, graph_4096_random_25persent_prob, "../Graphs/graph4096_random_25persent_prob.txt", 0, 89)->Unit(benchmark::kMillisecond);
BENCHMARK_CAPTURE(BM_BFS_AdjMatrix, graph_8192_random_25persent_prob, "../Graphs/graph8192_random_25persent_prob.txt", 0, 89)->Unit(benchmark::kMillisecond);

BENCHMARK_CAPTURE(BM_BFS_AdjMatrix, graph_2048_random_50persent_prob, "../Graphs/graph2048_random_50persent_prob.txt", 0, 89)->Unit(benchmark::kMillisecond);
BENCHMARK_CAPTURE(BM_BFS_AdjMatrix, graph_4096_random_50persent_prob, "../Graphs/graph4096_random_50persent_prob.txt", 0, 89)->Unit(benchmark::kMillisecond);
BENCHMARK_CAPTURE(BM_BFS_AdjMatrix, graph_8192_random_50persent_prob, "../Graphs/graph8192_random_50persent_prob.txt", 0, 89)->Unit(benchmark::kMillisecond);

BENCHMARK_CAPTURE(BM_BFS_AdjMatrix, grid_graph_16, "../Graphs/grid_graph16.txt", 17, 254)->Unit(benchmark::kMillisecond);
BENCHMARK_CAPTURE(BM_BFS_AdjMatrix, grid_graph_32, "../Graphs/grid_graph32.txt", 33, 1022)->Unit(benchmark::kMillisecond);
BENCHMARK_CAPTURE(BM_BFS_AdjMatrix, grid_graph_64, "../Graphs/grid_graph64.txt", 160, 4094)->Unit(benchmark::kMillisecond);

BENCHMARK_CAPTURE(BM_BFS_AdjMatrix, graph_100, "../Graphs/graph100.txt", 0, 89)->Unit(benchmark::kMillisecond);
BENCHMARK_CAPTURE(BM_BFS_AdjMatrix, graph_50, "../Graphs/graph50.txt", 0, 30)->Unit(benchmark::kMillisecond);


static void BM_BFS_AdjList(benchmark::State& state, const std::string& graphFileName, int from, int to) {

    AdjencyList<int> matrix(getSolutionDir() + "\\" + graphFileName);
    DijkstraPathManager<int> manager(make_shared<AdjencyList<int>>(matrix), from, to);
    auto [length, path] = manager.getShortestPath();

    for (auto _ : state) {
        for (int i = 0; i < 4; i++) {
            auto res = manager.getNextShortestPath();
            benchmark::DoNotOptimize(res);
            if (res.first == -1) {
                std::cout << "Path is not exist!\n";
            }
        }
        benchmark::DoNotOptimize(manager.getShortestPath());
    }
}

BENCHMARK_CAPTURE(BM_BFS_AdjList, graph_2048_random_25persent_prob, "../Graphs/graph2048_random_25persent_prob.txt", 0, 89)->Unit(benchmark::kMillisecond);
BENCHMARK_CAPTURE(BM_BFS_AdjList, graph_4096_random_25persent_prob, "../Graphs/graph4096_random_25persent_prob.txt", 0, 89)->Unit(benchmark::kMillisecond);
BENCHMARK_CAPTURE(BM_BFS_AdjList, graph_8192_random_25persent_prob, "../Graphs/graph8192_random_25persent_prob.txt", 0, 89)->Unit(benchmark::kMillisecond);

BENCHMARK_CAPTURE(BM_BFS_AdjList, graph_2048_random_50persent_prob, "../Graphs/graph2048_random_50persent_prob.txt", 0, 89)->Unit(benchmark::kMillisecond);
BENCHMARK_CAPTURE(BM_BFS_AdjList, graph_4096_random_50persent_prob, "../Graphs/graph4096_random_50persent_prob.txt", 0, 89)->Unit(benchmark::kMillisecond);
BENCHMARK_CAPTURE(BM_BFS_AdjList, graph_8192_random_50persent_prob, "../Graphs/graph8192_random_50persent_prob.txt", 0, 89)->Unit(benchmark::kMillisecond);

BENCHMARK_CAPTURE(BM_BFS_AdjList, grid_graph_16, "../Graphs/grid_graph16.txt", 17, 254)->Unit(benchmark::kMillisecond);
BENCHMARK_CAPTURE(BM_BFS_AdjList, grid_graph_32, "../Graphs/grid_graph32.txt", 33, 1022)->Unit(benchmark::kMillisecond);
BENCHMARK_CAPTURE(BM_BFS_AdjList, grid_graph_64, "../Graphs/grid_graph64.txt", 160, 4094)->Unit(benchmark::kMillisecond);

BENCHMARK_CAPTURE(BM_BFS_AdjList, graph_100, "../Graphs/graph100.txt", 0, 89)->Unit(benchmark::kMillisecond);
BENCHMARK_CAPTURE(BM_BFS_AdjList, graph_50, "../Graphs/graph50.txt", 0, 30)->Unit(benchmark::kMillisecond);

BENCHMARK_MAIN();