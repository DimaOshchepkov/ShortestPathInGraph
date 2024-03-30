# Проект "Нахождение кратчайших путей в графе"
## Описание проекта
Этот проект представляет собой реализацию алгоритма нахождения кратчайших путей в графе.
Он разработан в рамках производственной практики с целью изучения различных способов
представления графа в памяти компьютера и их влияния на эффективность алгоритма.

## Некоторые результаты
```
Run on (8 X 3600 MHz CPU s)
CPU Caches:
  L1 Data 32 KiB (x4)
  L1 Instruction 32 KiB (x4)
  L2 Unified 256 KiB (x4)
  L3 Unified 6144 KiB (x1)
---------------------------------------------------------------------------
Benchmark                                 Time             CPU   Iterations
---------------------------------------------------------------------------
BM_Dijkstra_AdjMatrix/graph_2048       23.9 ms         7.94 ms          124
BM_Dijkstra_AdjMatrix/graph_4096       99.7 ms         36.5 ms           21
BM_Dijkstra_AdjMatrix/graph_8192        385 ms          153 ms            5
BM_Dijkstra_AdjMatrix/graph_100       0.055 ms        0.018 ms        29867
BM_Dijkstra_AdjMatrix/graph_50        0.017 ms        0.008 ms        89600
BM_Dijkstra_AdjList/graph_2048         2.32 ms        0.994 ms          896
BM_Dijkstra_AdjList/graph_4096         20.8 ms         7.26 ms           99
BM_Dijkstra_AdjList/graph_8192          124 ms         51.6 ms           10
BM_Dijkstra_AdjList/graph_100         0.034 ms        0.015 ms        56000
BM_Dijkstra_AdjList/graph_50          0.013 ms        0.006 ms       112000
BM_BFS_AdjMatrix/graph_2048             101 ms         39.1 ms           20
BM_BFS_AdjMatrix/graph_4096            1044 ms          445 ms            2
BM_BFS_AdjMatrix/graph_8192            6568 ms         3109 ms            1
BM_BFS_AdjMatrix/graph_100            0.032 ms        0.013 ms        89600
BM_BFS_AdjMatrix/graph_50             0.010 ms        0.006 ms       148670
BM_BFS_AdjList/graph_2048              2.34 ms        0.921 ms          560
BM_BFS_AdjList/graph_4096              20.7 ms         7.19 ms          100
BM_BFS_AdjList/graph_8192               124 ms         53.1 ms           10
BM_BFS_AdjList/graph_100              0.034 ms        0.013 ms        49778
BM_BFS_AdjList/graph_50               0.012 ms        0.005 ms       172308
```
Как видно из бенчмарка храня матрицу в виде списка смежности, мы получаем прирост в производительности 1,5 раза на больших графах. На малых графаx почти не получаем прироста. Также можно заметить, что на малых графах лучше себя показывает BFS.

Для более оптимального хранения графа (в виду того, что граф, невзвешанный) была разработана специализация хранения графа, которая хранит в bool переменных длину (true - если есть ребро, иначе false в матрице смежности, а в списке смежности хранятся только вершины, между которыми есть связь). Были получены результаты, представленные ниже:
```
Running C:\MyStuff\Programming\ShortestPathInGraph\x64\Release\BenchmarkBoolStorage.exe
Run on (8 X 3600 MHz CPU s)
CPU Caches:
  L1 Data 32 KiB (x4)
  L1 Instruction 32 KiB (x4)
  L2 Unified 256 KiB (x4)
  L3 Unified 6144 KiB (x1)
---------------------------------------------------------------------------
Benchmark                                 Time             CPU   Iterations
---------------------------------------------------------------------------
BM_Dijkstra_AdjMatrix/graph_2048       25.2 ms         6.50 ms          137
BM_Dijkstra_AdjMatrix/graph_4096        103 ms         25.1 ms           28
BM_Dijkstra_AdjMatrix/graph_8192        312 ms          133 ms            4
BM_Dijkstra_AdjMatrix/graph_100       0.062 ms        0.023 ms        49778
BM_Dijkstra_AdjMatrix/graph_50        0.018 ms        0.007 ms        89600
BM_Dijkstra_AdjList/graph_2048         2.15 ms        0.572 ms         1338
BM_Dijkstra_AdjList/graph_4096         18.0 ms         6.13 ms          102
BM_Dijkstra_AdjList/graph_8192         85.3 ms         23.8 ms           21
BM_Dijkstra_AdjList/graph_100         0.044 ms        0.014 ms       112000
BM_Dijkstra_AdjList/graph_50          0.014 ms        0.006 ms       100000
BM_BFS_AdjMatrix/graph_2048             113 ms         36.5 ms           21
BM_BFS_AdjMatrix/graph_4096            1114 ms          461 ms            2
BM_BFS_AdjMatrix/graph_8192            7144 ms         2391 ms            1
BM_BFS_AdjMatrix/graph_100            0.034 ms        0.009 ms        89600
BM_BFS_AdjMatrix/graph_50             0.011 ms        0.003 ms       165926
BM_BFS_AdjList/graph_2048              2.14 ms        0.767 ms          896
BM_BFS_AdjList/graph_4096              17.8 ms         6.00 ms          112
BM_BFS_AdjList/graph_8192              84.8 ms         34.8 ms           22
BM_BFS_AdjList/graph_100              0.045 ms        0.013 ms        37333
BM_BFS_AdjList/graph_50               0.014 ms        0.004 ms       154483
```

## Немного о структуре проекта
Алгоритм поиска находится в [файле](./Graph/ShortestPathManager.cpp).
Бенчмарк находится в [файле](./Benchmark/DijkstraBM.cpp).

## Чтобы установить проект понадобится
- Visual Studio 2022
- [vcpkg](https://github.com/microsoft/vcpkg) с интеграцией для visual studio. Крутой [гайд](https://www.youtube.com/watch?v=0h1lC3QHLHU) по установке.
  - benchmark 
```.\vcpkg install benchmark```  
  - gtest 
```.\vcpkg install gtest```
