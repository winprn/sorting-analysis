#ifndef SORTING_ANALYSIS_COMMON_H
#define SORTING_ANALYSIS_COMMON_H

#include "string.h"

enum class SortingAlgorithm {
  SelectionSort,
  InsertionSort,
  BubbleSort,
  HeapSort,
  MergeSort,
  QuickSort,
  RadixSort,
  ShakerSort,
  ShellSort,
  CountingSort,
  FlashSort
};

SortingAlgorithm convertStringToEnum(char* algorithmName)
{
    if (strcmp(algorithmName, "bubble-sort") == 0) {
        return SortingAlgorithm::BubbleSort;
    }
    else if (strcmp(algorithmName, "radix-sort") == 0) {
        return SortingAlgorithm::RadixSort;
    }
    else if (strcmp(algorithmName, "merge-sort") == 0) {
        return SortingAlgorithm::MergeSort;
    }
    else if (strcmp(algorithmName, "flash-sort") == 0) {
        return SortingAlgorithm::FlashSort;
    }
    else if (strcmp(algorithmName, "bubble-sort") == 0) {
        return SortingAlgorithm::BubbleSort;
    }
    else if (strcmp(algorithmName, "insertion-sort") == 0) {
        return SortingAlgorithm::InsertionSort;
    }
    else if (strcmp(algorithmName, "selection-sort") == 0) {
        return SortingAlgorithm::SelectionSort;
    }
    else if (strcmp(algorithmName, "shell-sort") == 0) {
        return SortingAlgorithm::ShellSort;
    }
    else if (strcmp(algorithmName, "shaker-sort") == 0) {
        return SortingAlgorithm::ShakerSort;
    }
    else if (strcmp(algorithmName, "heap-sort") == 0) {
        return SortingAlgorithm::HeapSort;
    }
    else if (strcmp(algorithmName, "counting-sort") == 0) {
        return SortingAlgorithm::CountingSort;
    }
}

#endif // SORTING_ANALYSIS_COMMON_H
