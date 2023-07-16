#ifndef SELECTION_SORT
#define SELECTION_SORT

#include "SortBase.h"

class SelectionSort : public SortBase
{
    public:
    SelectionSort(int *a, int n) : SortBase(a, n){}
    void sort();
    void sortWithComparison();
};
#endif