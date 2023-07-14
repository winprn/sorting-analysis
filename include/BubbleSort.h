#include "SortBase.h"

#ifndef SORTING_ANALYSIS_BUBBLESORT_H
#define SORTING_ANALYSIS_BUBBLESORT_H

class BubbleSort: public SortBase {
public:
    BubbleSort(): SortBase(){}
    BubbleSort(int *a, int n): SortBase(a, n){}
    void sort();
    void sortWithComparison();
};

#endif //SORTING_ANALYSIS_BUBBLESORT_H