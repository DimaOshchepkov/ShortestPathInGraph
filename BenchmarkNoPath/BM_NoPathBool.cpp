#include <Benchmark/benchmark.h>
#include <memory>
#include <iostream>
#include <string>

#include <format>

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
    string s = EXPAND(SOLDIR);
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
    AdjencyMatrix<bool> matrix(getProjectDir() + "\\" + graphFileName);
    DijkstraPathManager<bool> manager(std::make_shared<AdjencyMatrix<bool>>(matrix), from, to);
    auto [length, path] = manager.getShortestPath();

    for (auto _ : state) {
        for (int i = 0; i < 4; i++) {
            auto res = manager.getNextShortestPath();
            benchmark::DoNotOptimize(res);
            
        }
        benchmark::DoNotOptimize(manager.getShortestPath());
    }
}



static void BM_Dijkstra_AdjList(benchmark::State& state, const std::string& graphFileName, int from, int to) {

    AdjencyList<bool> matrix(getProjectDir() + "\\" + graphFileName);
    DijkstraPathManager<bool> manager(make_shared<AdjencyList<bool>>(matrix), from, to);
    auto [length, path] = manager.getShortestPath();

    for (auto _ : state) {
        for (int i = 0; i < 4; i++) {
            auto res = manager.getNextShortestPath();
            benchmark::DoNotOptimize(res);

        }
        benchmark::DoNotOptimize(manager.getShortestPath());
    }
}


static void BM_BFS_AdjMatrix(benchmark::State& state, const std::string& graphFileName, int from, int to) {
    AdjencyMatrix<bool> matrix(getProjectDir() + "\\" + graphFileName);
    BFSPathManager<bool> manager(std::make_shared<AdjencyMatrix<bool>>(matrix), from, to);
    auto [length, path] = manager.getShortestPath();

    for (auto _ : state) {
        for (int i = 0; i < 4; i++) {
            auto res = manager.getNextShortestPath();
            benchmark::DoNotOptimize(res);

        }
        benchmark::DoNotOptimize(manager.getShortestPath());
    }
}


static void BM_BFS_AdjList(benchmark::State& state, const std::string& graphFileName, int from, int to) {

    AdjencyList<bool> matrix(getProjectDir() + "\\" + graphFileName);
    BFSPathManager<bool> manager(make_shared<AdjencyList<bool>>(matrix), from, to);
    auto [length, path] = manager.getShortestPath();

    for (auto _ : state) {
        for (int i = 0; i < 4; i++) {
            auto res = manager.getNextShortestPath();
            benchmark::DoNotOptimize(res);
   
        }
        benchmark::DoNotOptimize(manager.getShortestPath());
    }
}


static void BM_BFS_AdjMap(benchmark::State& state, const std::string& graphFileName, int from, int to) {
    AdjencyMap<bool> matrix(getProjectDir() + "\\" + graphFileName);
    BFSPathManager<bool> manager(std::make_shared<AdjencyMap<bool>>(matrix), from, to);
    auto [length, path] = manager.getShortestPath();

    for (auto _ : state) {
        for (int i = 0; i < 4; i++) {
            auto res = manager.getNextShortestPath();
            benchmark::DoNotOptimize(res);

        }
        benchmark::DoNotOptimize(manager.getShortestPath());
    }
}


static void BM_Dijkstra_AdjMap(benchmark::State& state, const std::string& graphFileName, int from, int to) {
    AdjencyMap<bool> matrix(getProjectDir() + "\\" + graphFileName);
    DijkstraPathManager<bool> manager(std::make_shared<AdjencyMap<bool>>(matrix), from, to);
    auto [length, path] = manager.getShortestPath();

    for (auto _ : state) {
        for (int i = 0; i < 4; i++) {
            auto res = manager.getNextShortestPath();
            benchmark::DoNotOptimize(res);

        }
        benchmark::DoNotOptimize(manager.getShortestPath());
    }
}


#define BENCHMARK_RANGE(from, to, step) \
for (int i = from; i <= to; i += step)



int main(int argc, char** argv) {


    BENCHMARK_RANGE(100, 173, 5) {
        auto graphFileName = std::format("..\\Graphs\\grid_graph{}_nopath.txt", i);
        auto graphName = std::format("grid_graph{}_nopath.txt", i);
        benchmark::RegisterBenchmark(("BM_Dijkstra_AdjMatrix/" + graphName), BM_Dijkstra_AdjMatrix, graphFileName, i * i + 1, i * i)->Unit(benchmark::kMillisecond)->Iterations(500);
        benchmark::RegisterBenchmark(("BM_Dijkstra_AdjList/" + graphName), BM_Dijkstra_AdjList, graphFileName, i * i + 1, i * i)->Unit(benchmark::kMillisecond)->Iterations(500);
        benchmark::RegisterBenchmark(("BM_Dijkstra_AdjMap/" + graphName), BM_Dijkstra_AdjMap, graphFileName, i * i + 1, i * i)->Unit(benchmark::kMillisecond)->Iterations(500);
    }
    

    BENCHMARK_RANGE(10'000, 30'000, 1000) {
        auto graphFileName = std::format("..\\Graphs\\graph{}_nopath_random_5persent_prob.txt", i);
        auto graphName = std::format("graph{}_nopath_random_5persent_prob.txt", i);
        benchmark::RegisterBenchmark(("BM_Dijkstra_AdjMatrix/" + graphName), BM_Dijkstra_AdjMatrix, graphFileName, i + 1, i)->Unit(benchmark::kMillisecond) ->Iterations(500);
        benchmark::RegisterBenchmark(("BM_Dijkstra_AdjList/" + graphName), BM_Dijkstra_AdjList, graphFileName, i + 1, i)->Unit(benchmark::kMillisecond) ->Iterations(500);
        benchmark::RegisterBenchmark(("BM_BFS_AdjMatrix/" + graphName), BM_BFS_AdjMatrix, graphFileName, i + 1, i)->Unit(benchmark::kMillisecond) ->Iterations(500);
        benchmark::RegisterBenchmark(("BM_BFS_AdjList/" + graphName), BM_BFS_AdjList, graphFileName, i + 1, i)->Unit(benchmark::kMillisecond) ->Iterations(500);
        benchmark::RegisterBenchmark(("BM_BFS_AdjMap/" + graphName), BM_BFS_AdjMap, graphFileName, i + 1, i)->Unit(benchmark::kMillisecond) ->Iterations(500);
        benchmark::RegisterBenchmark(("BM_Dijkstra_AdjMap/" + graphName), BM_Dijkstra_AdjMap, graphFileName, i + 1, i)->Unit(benchmark::kMillisecond) ->Iterations(500);
    }

    benchmark::Initialize(&argc, argv);
    benchmark::RunSpecifiedBenchmarks();

    return 0;
}