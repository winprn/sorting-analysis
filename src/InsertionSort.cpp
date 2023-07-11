#include "../include/InsertionSort.h"

void insertionSort(int* arr, int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
} 

void insertionSortWithCount(int* arr, int n, int& count_comparison)
{
    count_comparison = 0;
    int i, key, j;
    for (i = 1; ++count_comparison && i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (++count_comparison && j >= 0 && ++count_comparison && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}