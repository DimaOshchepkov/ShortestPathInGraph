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
BM_ShortestPath_AdjMatrix/0/0/89       4.75 ms         2.85 ms          280
BM_ShortestPath_AdjMatrix/1/0/89       17.2 ms         14.2 ms           66
BM_ShortestPath_AdjMatrix/2/0/89       68.9 ms         50.0 ms           10
BM_ShortestPath_AdjList/0/0/89        0.713 ms        0.531 ms         1000
BM_ShortestPath_AdjList/1/0/89         3.33 ms         2.71 ms          213
BM_ShortestPath_AdjList/2/0/89         19.8 ms         14.6 ms           45
```
Как видно из бенчмарка храня матрицу в виде списка смежности, мы получаем прирост в производительности 4-5 раз.

## Немного о структуре проекта
Алгоритм поиска находится в [файле](./Graph/ShortestPathManager.cpp).
Бенчмарк находится в [файле](./Benchmark/DijkstraBM.cpp).

## Чтобы установить проект понадобиться
- Visual Studio 2022
- [vcpkg](https://github.com/microsoft/vcpkg) с интеграцией для visual studio. Крутой [гайд](https://www.youtube.com/watch?v=0h1lC3QHLHU) по установке.
  - benchmark (.\vcpkg install benchmark)
  - gtest (.\vcpkg install gtest)
