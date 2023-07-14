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
        include/SortBase.h
        include/BubbleSort.cpp
        include/InsertionSort.cpp
        include/MergeSort.cpp
        src/DataGenerator.cpp
        src/main.cpp
        include/SortBase.cpp 
        )
