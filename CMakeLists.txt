cmake_minimum_required(VERSION 3.25)
project(sorting_analysis)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(sorting_analysis
               src/DataGenerator.h
               src/DataGenerator.cpp
               src/main.cpp
               include/BubbleSort.h
               include/BubbleSort.cpp
               include/FlashSort.h
               include/FlashSort.cpp
               include/InsertionSort.h
               include/InsertionSort.cpp
               include/MergeSort.h
               include/MergeSort.cpp
               include/RadixSort.h
               include/RadixSort.cpp
               include/SelectionSort.h
               include/SelectionSort.cpp
               include/HeapSort.h
               include/HeapSort.cpp
               include/ShakerSort.h
               include/ShakerSort.cpp
               include/SortStrategy.h
               include/SortStrategy.cpp
               tests/test.h external/doctest.h tests/test.cpp
               include/SortContext.h include/SortContext.cpp include/common.h)
