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
-------------------------------------------------------------------------------
Benchmark                                     Time             CPU   Iterations
-------------------------------------------------------------------------------
BM_ShortestPath_AdjMatrix/graph_2048       13.8 ms         8.46 ms          109
BM_ShortestPath_AdjMatrix/graph_4096       37.6 ms         20.5 ms           32
BM_ShortestPath_AdjMatrix/graph_8192        107 ms         62.5 ms           12
BM_ShortestPath_AdjMatrix/graph_100       0.520 ms        0.377 ms         2240
BM_ShortestPath_AdjMatrix/graph_50        0.296 ms        0.195 ms         3446
BM_ShortestPath_AdjList/graph_2048         9.95 ms         6.56 ms          112
BM_ShortestPath_AdjList/graph_4096         22.5 ms         14.9 ms           45
BM_ShortestPath_AdjList/graph_8192         59.1 ms         37.2 ms           21
BM_ShortestPath_AdjList/graph_100         0.494 ms        0.330 ms         2133
BM_ShortestPath_AdjList/graph_50          0.297 ms        0.172 ms         3733
```
Как видно из бенчмарка храня матрицу в виде списка смежности, мы получаем прирост в производительности 1,5 раза на больших графах. На малых графаx почти не получаем прироста.

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
