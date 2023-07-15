#include "SortBase.h"

#ifndef RADIX_SORT
#define RADIX_SORT

class RadixSort : public SortBase {
private:
    int getMax();
    void countSort(int exp);
    int getMaxWithComparison();
    void countSortWithComparison(int exp);
public:
    RadixSort(): SortBase() {}
    RadixSort(int* a, int n): SortBase(a, n) {}
    void sort();
    void sortWithComparison();
};

#endif