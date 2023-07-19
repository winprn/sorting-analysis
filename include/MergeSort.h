#ifndef MERGE_SORT
#define MERGE_SORT

#include "SortStrategy.h"

class MergeSort : public SortStrategy {
 private:
  void mergeSort(int left, int right);
  void mergeTwoArrays(int left, int mid, int right);

  void mergeSortWithComparison(int left, int right);
  void mergeTwoArraysWithComparison(int left, int mid, int right);

 public:
  MergeSort() : SortStrategy() {}
  MergeSort(int* a, int n) : SortStrategy(a, n) {}

  void sort();

  void sortWithComparison();
};

#endif