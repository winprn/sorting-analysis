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
    MergeSort(int* a, int n) : SortBase(a, n) {}

    void sort();
    
    void sortWithComparison();
};

#endif