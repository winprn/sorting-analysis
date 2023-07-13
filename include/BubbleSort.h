#include "SortBase.h"

#ifndef SORTING_ANALYSIS_BUBBLESORT_H
#define SORTING_ANALYSIS_BUBBLESORT_H

class BubbleSort: public SortBase {
public:
    BubbleSort(): SortBase(){}
    void sort();
    void sortWithComparison();
};

#endif //SORTING_ANALYSIS_BUBBLESORT_H
