#ifndef HEAP_SORT
#define HEAD_SORT  
#include "SortBase.h"

class HeapSort : public SortBase
{
    public:
    HeapSort(int *a, int n) : SortBase(a, n){}

    void heapify(int i, int m_size);
    void sort();
    void sortWithComparision();
    void heapifyWithComparision(int i, int m_size);
};

#endif