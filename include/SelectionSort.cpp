#include "SelectionSort.h"

void SelectionSort::sort(int *a, int n)
{
    m_timeStart = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < n; ++i)
    {
        int minPos = i;
        for (int j = i + 1; j < n; ++j)
            if (a[j] < a[minPos])
                minPos = j;
        std::swap(a[i], a[minPos]);
    }
    m_timeEnd = std::chrono::high_resolution_clock::now();
}

void SelectionSort::sortWithComparison(int *a, int n)
{
    for (int i = 0; m_count_comparison++ && i < n; ++i)
    {
        int minPos = i;
        for (int j = i + 1; m_count_comparison++ && j < n; ++j)
            if (m_count_comparison++ && a[j] < a[minPos])
                minPos = j;
        std::swap(a[i], a[minPos]);
    }
}