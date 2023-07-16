#include "SortStrategy.h"

#ifndef FLASH_SORT
#define FLASH_SORT

class FlashSort : public SortStrategy {
public:
    FlashSort(): SortStrategy(){}
    FlashSort(int* a, int n): SortStrategy(a, n){}

    void sort();
    void sortWithComparison();
};

#endif