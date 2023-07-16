#ifndef SORTING_ANALYSIS_FLASHSORT_H
#define SORTING_ANALYSIS_FLASHSORT_H
#include "SortBase.h"


class FlashSort : public SortBase {
private:
    int findMaxWithComparison();
    
public:
    FlashSort(): SortBase(){}
    FlashSort(int* a, int n): SortBase(a, n){}

    void sort() override;
    void sortWithComparison();
};

#endif