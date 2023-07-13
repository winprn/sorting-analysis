#include "InsertionSort.h"

void InsertionSort::sort()
{
    int i, key, j;
    for (i = 1; i < m_size; i++)
    {
        key = m_array[i];
        j = i - 1;

        while (j >= 0 && m_array[j] > key)
        {
            m_array[j + 1] = m_array[j];
            j = j - 1;
        }
        m_array[j + 1] = key;
    }
} 

void InsertionSort::sortWithComparison()
{
    int i, key, j;
    for (i = 1; ++m_count_comparison && i < m_size; i++)
    {
        key = m_array[i];
        j = i - 1;

        while (++m_count_comparison && j >= 0 && ++m_count_comparison && m_array[j] > key)
        {
            m_array[j + 1] = m_array[j];
            j = j - 1;
        }
        m_array[j + 1] = key;
    }
}