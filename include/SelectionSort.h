#ifndef SELECTION_SORT
#define SELECTION_SORT

#include "SortBase.h"

class SelectionSort : public SortBase
{
    public:
    void sort(int *a, int n);
    void sortWithComparison(int *a, int n);
};
#endif