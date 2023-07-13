#include "SortBase.h"

#ifndef MERGE_SORT
#define MERGE_SORT

class MergeSort : public SortBase {
private:
    void mergeSort(int left, int right);
    void mergeTwoArrays(int left, int mid, int right);

    void mergeSortWithComparison(int left, int right);
    void mergeTwoArraysWithComparison(int left, int mid, int right);

public:
    MergeSort(): SortBase(){}

    void sort();
    
    void sortWithComparison();
};

#endif