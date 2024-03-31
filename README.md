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
Хранение в int.
-------------------------------------------------------------------------------------------------
Benchmark                                                       Time             CPU   Iterations
-------------------------------------------------------------------------------------------------
BM_Dijkstra_AdjMatrix/graph_2048_random_25persent_prob       66.6 ms         40.3 ms           19
BM_Dijkstra_AdjMatrix/graph_4096_random_25persent_prob        334 ms          191 ms            4
BM_Dijkstra_AdjMatrix/graph_8192_random_25persent_prob        809 ms          531 ms            1
BM_Dijkstra_AdjMatrix/graph_2048_random_50persent_prob        137 ms         97.2 ms            9
BM_Dijkstra_AdjMatrix/graph_4096_random_50persent_prob        428 ms          323 ms            3
BM_Dijkstra_AdjMatrix/graph_8192_random_50persent_prob       1953 ms         1344 ms            1
BM_Dijkstra_AdjMatrix/grid_graph_16                         0.465 ms        0.368 ms         2036
BM_Dijkstra_AdjMatrix/grid_graph_32                          6.20 ms         4.80 ms          179
BM_Dijkstra_AdjMatrix/grid_graph_64                           102 ms         64.2 ms            9
BM_Dijkstra_AdjMatrix/graph_100                             0.195 ms        0.126 ms         4978
BM_Dijkstra_AdjMatrix/graph_50                              0.069 ms        0.046 ms        12949
BM_Dijkstra_AdjList/graph_2048_random_25persent_prob          359 ms          219 ms            3
BM_Dijkstra_AdjList/graph_4096_random_25persent_prob         3152 ms         2281 ms            1
BM_Dijkstra_AdjList/graph_8192_random_25persent_prob        14307 ms        10312 ms            1
BM_Dijkstra_AdjList/graph_2048_random_50persent_prob         1558 ms         1188 ms            1
BM_Dijkstra_AdjList/graph_4096_random_50persent_prob         9049 ms         6359 ms            1
BM_Dijkstra_AdjList/graph_8192_random_50persent_prob        79993 ms        57281 ms            1
BM_Dijkstra_AdjList/grid_graph_16                           0.280 ms        0.213 ms         5146
BM_Dijkstra_AdjList/grid_graph_32                            1.72 ms         1.30 ms         1120
BM_Dijkstra_AdjList/grid_graph_64                            9.84 ms         6.25 ms           90
BM_Dijkstra_AdjList/graph_100                               0.967 ms        0.719 ms         1000
BM_Dijkstra_AdjList/graph_50                                0.143 ms        0.114 ms        11200
BM_BFS_AdjMatrix/graph_2048_random_25persent_prob           0.339 ms        0.218 ms         3446
BM_BFS_AdjMatrix/graph_4096_random_25persent_prob           0.970 ms        0.698 ms         1120
BM_BFS_AdjMatrix/graph_8192_random_25persent_prob            1.14 ms        0.408 ms         2641
BM_BFS_AdjMatrix/graph_2048_random_50persent_prob           0.550 ms        0.288 ms         2987
BM_BFS_AdjMatrix/graph_4096_random_50persent_prob           0.792 ms        0.317 ms         1723
BM_BFS_AdjMatrix/graph_8192_random_50persent_prob            2.31 ms         1.27 ms         1120
BM_BFS_AdjMatrix/grid_graph_16                              36032 ms        17844 ms            1
BM_BFS_AdjMatrix/graph_100                                  0.022 ms        0.010 ms        56000
BM_BFS_AdjMatrix/graph_50                                   0.013 ms        0.007 ms       112000
BM_BFS_AdjList/graph_2048_random_25persent_prob             0.215 ms        0.094 ms         7467
BM_BFS_AdjList/graph_4096_random_25persent_prob             0.618 ms        0.363 ms         2240
BM_BFS_AdjList/graph_8192_random_25persent_prob             0.606 ms        0.259 ms         6400
BM_BFS_AdjList/graph_2048_random_50persent_prob             0.378 ms        0.138 ms         3733
BM_BFS_AdjList/graph_4096_random_50persent_prob             0.492 ms        0.201 ms         5600
BM_BFS_AdjList/graph_8192_random_50persent_prob              1.40 ms        0.753 ms          747
BM_BFS_AdjList/grid_graph_16                                 7439 ms         4453 ms            1
BM_BFS_AdjMap/graph_100                                     0.022 ms        0.008 ms        74667
BM_BFS_AdjMap/graph_50                                      0.010 ms        0.006 ms       144516
BM_Dijkstra_AdjMap/graph_100                                0.547 ms        0.246 ms         2987
BM_Dijkstra_AdjMap/graph_50                                 0.155 ms        0.067 ms        10000
BM_Dijkstra_AdjMap/graph_2048_random_25persent_prob         212 ms          105 ms            7
BM_Dijkstra_AdjMap/graph_4096_random_25persent_prob         1146 ms          500 ms            1
BM_Dijkstra_AdjMap/graph_8192_random_25persent_prob          2935 ms         1250 ms            1
BM_Dijkstra_AdjMap/graph_2048_random_50persent_prob          575 ms          276 ms            3
BM_Dijkstra_AdjMap/graph_4096_random_50persent_prob          1847 ms         1203 ms            1
BM_Dijkstra_AdjMap/graph_8192_random_50persent_prob          8913 ms         4000 ms            1
BM_Dijkstra_AdjMap/grid_graph_16                            0.333 ms        0.140 ms         4480
BM_Dijkstra_AdjMap/grid_graph_32                            2.38 ms         1.19 ms          896
BM_Dijkstra_AdjMap/grid_graph_64                            18.6 ms         9.77 ms      56

```


Для более оптимального хранения графа (в виду того, что граф, невзвешанный) была разработана специализация хранения графа, которая хранит в bool переменных длину (true - если есть ребро, иначе false в матрице смежности, а в списке смежности хранятся только вершины, между которыми есть связь). Были получены результаты, представленные ниже:
```
Running C:\MyStuff\Programming\ShortestPathInGraph\x64\Release\BenchmarkBoolStorage.exe
Run on (8 X 3600 MHz CPU s)
CPU Caches:
  L1 Data 32 KiB (x4)
  L1 Instruction 32 KiB (x4)
  L2 Unified 256 KiB (x4)
  L3 Unified 6144 KiB (x1)
//bool_storage
-------------------------------------------------------------------------------------------------
Benchmark                                                       Time             CPU   Iterations
-------------------------------------------------------------------------------------------------
BM_Dijkstra_AdjMatrix/graph_2048_random_25persent_prob       65.6 ms         35.0 ms           21
BM_Dijkstra_AdjMatrix/graph_4096_random_25persent_prob        330 ms          154 ms            6
BM_Dijkstra_AdjMatrix/graph_8192_random_25persent_prob        808 ms          516 ms            1
BM_Dijkstra_AdjMatrix/graph_2048_random_50persent_prob        136 ms         84.8 ms            7
BM_Dijkstra_AdjMatrix/graph_4096_random_50persent_prob        480 ms          266 ms            2
BM_Dijkstra_AdjMatrix/graph_8192_random_50persent_prob       1970 ms          641 ms            1
BM_Dijkstra_AdjMatrix/grid_graph_16                         0.498 ms        0.207 ms         4978
BM_Dijkstra_AdjMatrix/grid_graph_32                          5.97 ms         3.26 ms          201
BM_Dijkstra_AdjMatrix/grid_graph_64                          85.1 ms         62.5 ms           10
BM_Dijkstra_AdjMatrix/graph_100                             0.188 ms        0.127 ms         6400
BM_Dijkstra_AdjMatrix/graph_50                              0.070 ms        0.043 ms        18667
BM_Dijkstra_AdjList/graph_2048_random_25persent_prob          366 ms          214 ms            3
BM_Dijkstra_AdjList/graph_4096_random_25persent_prob         3151 ms         1906 ms            1
BM_Dijkstra_AdjList/graph_8192_random_25persent_prob        14445 ms         6031 ms            1
BM_Dijkstra_AdjList/graph_2048_random_50persent_prob         1561 ms          578 ms            2
BM_Dijkstra_AdjList/graph_4096_random_50persent_prob         9074 ms         3828 ms            1
BM_Dijkstra_AdjList/graph_8192_random_50persent_prob        81664 ms        47141 ms            1
BM_Dijkstra_AdjList/grid_graph_16                           0.282 ms        0.146 ms         4073
BM_Dijkstra_AdjList/grid_graph_32                            1.75 ms         1.10 ms          498
BM_Dijkstra_AdjList/grid_graph_64                            10.3 ms         5.00 ms          100
BM_Dijkstra_AdjList/graph_100                               0.970 ms        0.594 ms         1000
BM_Dijkstra_AdjList/graph_50                                0.148 ms        0.093 ms         6400
BM_BFS_AdjMatrix/graph_2048_random_25persent_prob           0.345 ms        0.204 ms         2987
BM_BFS_AdjMatrix/graph_4096_random_25persent_prob           0.993 ms        0.562 ms         1445
BM_BFS_AdjMatrix/graph_8192_random_25persent_prob            1.01 ms        0.711 ms          747
BM_BFS_AdjMatrix/graph_2048_random_50persent_prob           0.565 ms        0.351 ms         2358
BM_BFS_AdjMatrix/graph_4096_random_50persent_prob           0.748 ms        0.462 ms         1487
BM_BFS_AdjMatrix/graph_8192_random_50persent_prob            2.35 ms        0.947 ms         1056
BM_BFS_AdjMatrix/grid_graph_16                              38481 ms        19281 ms            1
BM_BFS_AdjMatrix/graph_100                                  0.018 ms        0.008 ms       112000
BM_BFS_AdjMatrix/graph_50                                   0.011 ms        0.005 ms       213333
BM_BFS_AdjList/graph_2048_random_25persent_prob             0.213 ms        0.117 ms         6400
BM_BFS_AdjList/graph_4096_random_25persent_prob             0.623 ms        0.249 ms         3446
BM_BFS_AdjList/graph_8192_random_25persent_prob             0.573 ms        0.307 ms         2800
BM_BFS_AdjList/graph_2048_random_50persent_prob             0.369 ms        0.222 ms         6400
BM_BFS_AdjList/graph_4096_random_50persent_prob             0.476 ms        0.269 ms         3200
BM_BFS_AdjList/graph_8192_random_50persent_prob              1.40 ms        0.648 ms          989
BM_BFS_AdjList/grid_graph_16                                 7300 ms         3156 ms            1
BM_BFS_AdjList/graph_100                                    0.021 ms        0.009 ms        56000
BM_BFS_AdjList/graph_50                                     0.013 ms        0.007 ms        89600
BM_BFS_AdjMap/graph_2048_random_25persent_prob              0.264 ms        0.096 ms         7467
BM_BFS_AdjMap/graph_4096_random_25persent_prob              0.758 ms        0.321 ms         2240
BM_BFS_AdjMap/graph_8192_random_25persent_prob              0.908 ms        0.391 ms         1600
BM_BFS_AdjMap/graph_2048_random_50persent_prob              0.472 ms        0.204 ms         3446
BM_BFS_AdjMap/graph_4096_random_50persent_prob              0.632 ms        0.276 ms         2489
BM_BFS_AdjMap/graph_8192_random_50persent_prob               2.27 ms         1.10 ms          896
BM_BFS_AdjMap/grid_graph_16                                 10852 ms         5203 ms            1
BM_BFS_AdjMap/graph_100                                     0.023 ms        0.010 ms       112000
BM_BFS_AdjMap/graph_50                                      0.012 ms        0.005 ms       100000
BM_Dijkstra_AdjMap/graph_100                                0.574 ms        0.210 ms         4978
BM_Dijkstra_AdjMap/graph_50                                 0.148 ms        0.075 ms         8960
BM_Dijkstra_AdjMap/graph_2048_random_25persent_prob           217 ms          104 ms            6
BM_Dijkstra_AdjMap/graph_4096_random_25persent_prob          1176 ms          547 ms            1
BM_Dijkstra_AdjMap/graph_8192_random_25persent_prob          3115 ms         1453 ms            1
BM_Dijkstra_AdjMap/graph_2048_random_50persent_prob           583 ms          266 ms            3
BM_Dijkstra_AdjMap/graph_4096_random_50persent_prob          1850 ms          734 ms            1
BM_Dijkstra_AdjMap/graph_8192_random_50persent_prob          9205 ms         4156 ms            1
BM_Dijkstra_AdjMap/grid_graph_16                            0.332 ms        0.160 ms         4978
BM_Dijkstra_AdjMap/grid_graph_32                             2.34 ms         1.23 ms          560
BM_Dijkstra_AdjMap/grid_graph_64                             18.3 ms         8.06 ms           64

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
