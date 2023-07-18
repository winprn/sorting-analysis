#include "SortStrategy.h"

#ifndef RADIX_SORT
#define RADIX_SORT

class RadixSort : public SortStrategy {
 private:
  int getMax();
  void countSort(int exp);
  int getMaxWithComparison();
  void countSortWithComparison(int exp);

 public:
  RadixSort() : SortStrategy() {}
  RadixSort(int* a, int n) : SortStrategy(a, n) {}
  void sort();
  void sortWithComparison();
};

#endif