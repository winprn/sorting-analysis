#include "SortBase.h"

#ifndef FLASH_SORT
#define FLASH_SORT

class FlashSort : public SortBase {
public:
    FlashSort(): SortBase(){}
    FlashSort(int* a, int n): SortBase(a, n){}

    void sort();
    void sortWithComparison();
};

#endif