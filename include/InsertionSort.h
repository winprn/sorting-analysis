#include "SortStrategy.h"

#ifndef INSERTION_SORT
#define INSERTION_SORT

class InsertionSort : public SortStrategy {
 public:
  InsertionSort() : SortStrategy() {}
  InsertionSort(int* a, int n) : SortStrategy(a, n) {}
  void sort();
  void sortWithComparison();
};

#endif