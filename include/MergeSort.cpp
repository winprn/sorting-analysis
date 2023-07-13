#include "MergeSort.h"

void MergeSort::mergeSort(int left, int right) 
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        mergeTwoArrays(left, mid, right);
    }
}
void MergeSort::mergeTwoArrays(int left, int mid, int right) 
{
        if (left <= right)
    {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        int *arr1 = new int[n1];
        int *arr2 = new int[n2];
        // copy
        for (int i = 0; i < n1; i++)
        {
            arr1[i] = m_array[left + i];
        }
        for (int i = 0; i < n2; i++)
        {
            arr2[i] = m_array[mid + 1 + i];
        }

        // merge
        int index1 = 0, index2 = 0, index = left;
        while (index1 < n1 && index2 < n2)
        {
            if (arr1[index1] <= arr2[index2])
            {
                m_array[index] = arr1[index1++];
            }
            else
            {
                m_array[index] = arr2[index2++];
            }
            index++;
        }
        while (index1 < n1)
        {
            m_array[index] = arr1[index1];
            index++;
            index1++;
        }

        while (index2 < n2)
        {
            m_array[index] = arr2[index2];
            index++;
            index2++;
        }

        // deallocated
        delete[] arr1;
        delete[] arr2;
    }
}

void MergeSort::sort() {
    mergeSort(0, m_size - 1);
}

void MergeSort::mergeSortWithComparison(int left, int right) 
{

}

void MergeSort::mergeTwoArraysWithComparison(int left, int mid, int right) 
{

}

void MergeSort::sortWithComparison() 
{
    mergeSortWithComparison(0, m_size - 1);
}