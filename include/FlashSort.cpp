#include "FlashSort.h"

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

int FlashSort::findMaxWithComparison()
{
    int max = m_array[0];
    for (int i = 1; ++m_count_comparison && i < m_size; i++)
    {
        if (++m_count_comparison && m_array[i] > max)
            max = m_array[i];
    }
    return max;
}

// Flash Sort algorithm
void FlashSort::sort()
{
    int minVal = m_array[0];
    int max = 0;
    int m = int(0.45 * m_size);
    int *l = new int[m];
    for (int i = 0; i < m; i++)
        l[i] = 0;
    for (int i = 1; i < m_size; i++)
    {
        if (m_array[i] < minVal)
            minVal = m_array[i];
        if (m_array[i] > m_array[max])
            max = i;
    }
    if (m_array[max] == minVal)
        return;
    double c1 = (double)(m - 1) / (m_array[max] - minVal);
    for (int i = 0; i < m_size; i++)
    {
        int k = int(c1 * (m_array[i] - minVal));
        ++l[k];
    }
    for (int i = 1; i < m; i++)
        l[i] += l[i - 1];

    // swap
    swap(m_array[max], m_array[0]);

    int nmove = 0;
    int j = 0;
    int k = m - 1;
    int t = 0;
    int flash;
    while (nmove < m_size - 1)
    {
        while (j > l[k] - 1)
        {
            j++;
            k = int(c1 * (m_array[j] - minVal));
        }
        flash = m_array[j];
        if (k < 0)
            break;
        while (j != l[k])
        {
            k = int(c1 * (flash - minVal));
            int hold = m_array[t = --l[k]];
            m_array[t] = flash;
            flash = hold;
            ++nmove;
        }
    }
    delete[] l;

    // insertion sort
    for (int i = 1; i < m_size; i++)
    {
        int key = m_array[i];
        int j = i - 1;

        // Move elements greater than key to one position ahead
        while (j >= 0 && m_array[j] > key)
        {
            m_array[j + 1] = m_array[j];
            j--;
        }

        // Place the key in its correct position
        m_array[j + 1] = key;
    }
}

void FlashSort::sortWithComparison()
{
    int max = findMaxWithComparison();

    int m = int(0.45 * m_size);
    int *distribution = new int[m](); 

    for (int i = 0;++m_count_comparison && i < m_size; i++)
    {
        int index = int(m * (double(m_array[i]) / max));
        distribution[index]++;
    }

    for (int i = 1; ++m_count_comparison && i < m; i++)
    {
        distribution[i] += distribution[i - 1];
    }

    int val = m_array[0];
    int index = 0;
    int start = 0;
    int next;

    while (++m_count_comparison && index < m_size)
    {
        next = distribution[index] - 1;
        if (++m_count_comparison && next == index)
        {
            m_array[index] = val;
            index++;
            if (start != 0)
                start = next + 1;
            if (index < m_size)
                val = m_array[index];
        }
        else
        {
            std::swap(val, m_array[next]);
            distribution[index]--;
        }
    }

    delete[] distribution;
}
