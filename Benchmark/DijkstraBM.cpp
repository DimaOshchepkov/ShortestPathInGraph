#include <Benchmark/benchmark.h>
#include <memory>
#include <iostream>
#include <string>

#include "ShortestPathManager.h" 

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


std::vector<std::string> paths = { "graph2048.txt", "graph4096.txt", "graph8192.txt" };

static void BM_ShortestPath_AdjMatrix(benchmark::State& state) {
    std::string graphFileName = paths[state.range(0)];
    int from = state.range(1);
    int to = state.range(2);

    AdjencyMatrix matrix(getProjectDir() + "\\" + graphFileName);
    ShortestPathManager manager(make_shared<AdjencyMatrix>(matrix), from, to);
    auto [length, path] = manager.getShortestPath();

    for (auto _ : state) {
        benchmark::DoNotOptimize(manager.getShortestPath());
    }
}

BENCHMARK(BM_ShortestPath_AdjMatrix)->Unit(benchmark::kMillisecond)
->Args({ 0, 0, 89})
->Args({ 1, 0, 89 })
->Args({ 2, 0, 89 });

static void BM_ShortestPath_AdjList(benchmark::State& state) {
    std::string graphFileName = paths[state.range(0)];
    int from = state.range(1);
    int to = state.range(2);

    AdjencyList matrix(getProjectDir() + "\\" + graphFileName);
    ShortestPathManager manager(make_shared<AdjencyList>(matrix), from, to);
    auto [length, path] = manager.getShortestPath();

    for (auto _ : state) {
        benchmark::DoNotOptimize(manager.getShortestPath());
    }
}

BENCHMARK(BM_ShortestPath_AdjList)->Unit(benchmark::kMillisecond)
->Args({ 0, 0, 89 })
->Args({ 1, 0, 89 })
->Args({ 2, 0, 89 });

BENCHMARK_MAIN();