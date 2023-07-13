#include "SortBase.h"

#ifndef INSERTION_SORT
#define INSERTION_SORT

class InsertionSort : public SortBase {
public:
    InsertionSort(): SortBase(){}
    void sort();
    void sortWithComparison();
};

#endif