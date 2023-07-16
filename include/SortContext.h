#ifndef SORTING_ANALYSIS_SORTCONTEXT_H
#define SORTING_ANALYSIS_SORTCONTEXT_H
#include "./SortStrategy.h"
#include "BubbleSort.h"
#include "FlashSort.h"
#include "HeapSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "RadixSort.h"
#include "SelectionSort.h"
#include "ShakerSort.h"
#include "common.h"

class SortContext {
private:
  SortStrategy *strategy;
public:
  SortContext(): strategy(nullptr){}
  SortContext(SortStrategy *strat_): strategy(strat_){}
  void setStrategy(SortingAlgorithm algo, int *a, int n);
  void sort() {
    strategy->sort();
  }
  void sortWithComparison() {
    strategy->sortWithComparison();
  }
};

#endif // SORTING_ANALYSIS_SORTCONTEXT_H