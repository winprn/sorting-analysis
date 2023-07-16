#include "SortBase.h"

#ifndef INSERTION_SORT
#define INSERTION_SORT

class InsertionSort : public SortBase {
public:
    InsertionSort(): SortBase(){}
    InsertionSort(int* a, int n) : SortBase(a, n) {}
    void sort() override;
    void sortWithComparison();
};

#endif