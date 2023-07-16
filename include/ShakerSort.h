#ifndef SHAKER_SORT
#define SHAKER_SORT
#include "SortBase.h"

class ShakerSort : public SortBase
{
public:
    ShakerSort(int *a, int n) : SortBase(a, n) {}
    void sort();
    void sortWithComparison();
};
#endif