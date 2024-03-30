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




std::vector<std::string> paths = { "graph2048.txt", "graph4096.txt", "graph8192.txt", "graph100.txt"};

static void BM_Dijkstra_AdjMatrix(benchmark::State& state, const std::string& graphFileName, int from, int to) {
    AdjencyMatrix<int> matrix(getProjectDir() + "\\" + graphFileName);
    DijkstraPathManager<int> manager(std::make_shared<AdjencyMatrix<int>>(matrix), from, to);
    auto [length, path] = manager.getShortestPath();

    for (auto _ : state) {
        for (int i = 0; i < 5; i++) {
            benchmark::DoNotOptimize(manager.getNextShortestPath());
        }
        benchmark::DoNotOptimize(manager.getShortestPath());
    }
}

BENCHMARK_CAPTURE(BM_Dijkstra_AdjMatrix, graph_2048, "graph2048.txt", 0, 89)->Unit(benchmark::kMillisecond);
BENCHMARK_CAPTURE(BM_Dijkstra_AdjMatrix, graph_4096, "graph4096.txt", 0, 89)->Unit(benchmark::kMillisecond);
BENCHMARK_CAPTURE(BM_Dijkstra_AdjMatrix, graph_8192, "graph8192.txt", 0, 89)->Unit(benchmark::kMillisecond);
BENCHMARK_CAPTURE(BM_Dijkstra_AdjMatrix, graph_100, "graph100.txt", 0, 89)->Unit(benchmark::kMillisecond);
BENCHMARK_CAPTURE(BM_Dijkstra_AdjMatrix, graph_50, "graph50.txt", 0, 30)->Unit(benchmark::kMillisecond);


static void BM_Dijkstra_AdjList(benchmark::State& state, const std::string& graphFileName, int from, int to) {

    AdjencyList<int> matrix(getProjectDir() + "\\" + graphFileName);
    DijkstraPathManager<int> manager(make_shared<AdjencyList<int>>(matrix), from, to);
    auto [length, path] = manager.getShortestPath();

    for (auto _ : state) {
        for (int i = 0; i < 5; i++) {
            benchmark::DoNotOptimize(manager.getNextShortestPath());
        }
        benchmark::DoNotOptimize(manager.getShortestPath());
    }
}

BENCHMARK_CAPTURE(BM_Dijkstra_AdjList, graph_2048, "graph2048.txt", 0, 89)->Unit(benchmark::kMillisecond);
BENCHMARK_CAPTURE(BM_Dijkstra_AdjList, graph_4096, "graph4096.txt", 0, 89)->Unit(benchmark::kMillisecond);
BENCHMARK_CAPTURE(BM_Dijkstra_AdjList, graph_8192, "graph8192.txt", 0, 89)->Unit(benchmark::kMillisecond);
BENCHMARK_CAPTURE(BM_Dijkstra_AdjList, graph_100, "graph100.txt", 0, 89)->Unit(benchmark::kMillisecond);
BENCHMARK_CAPTURE(BM_Dijkstra_AdjList, graph_50, "graph50.txt", 0, 30)->Unit(benchmark::kMillisecond);

BENCHMARK_MAIN();