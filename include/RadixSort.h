#include "SortBase.h"

#ifndef RADIX_SORT
#define RADIX_SORT

class RadixSort : public SortBase {
public:
    RadixSort(): SortBase(){}
    void sort();
    void sortWithComparison();
};

#endif