cmake_minimum_required(VERSION 3.25)
project(sorting_analysis)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(sorting_analysis
        include/BubbleSort.h
        include/FlashSort.h
        include/InsertionSort.h
        include/MergeSort.h
        include/RadixSort.h
        include/SelectionSort.h
        include/SelectionSort.cpp
        include/HeapSort.h
        include/HeapSort.cpp
        include/SortBase.h
        src/DataGenerator.cpp
        src/main.cpp include/SortBase.cpp include/BubbleSort.cpp tests/test.h external/doctest.h tests/test.cpp src/DataGenerator.h)
