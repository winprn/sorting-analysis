#include "SortStrategy.h"

SortStrategy::SortStrategy() {
    m_array = nullptr;
    m_count_comparison = m_size = 0;
}

SortStrategy::SortStrategy(int *a, int size) {
    m_size = size;
    m_array = new int[m_size];
    for (int i = 0; i < m_size; i++) m_array[i] = a[i];
}

int *SortStrategy::getArray() const {
    return m_array;
}

int SortStrategy::getComparison() const {
    return m_count_comparison;
}

SortStrategy::~SortStrategy()
{
    if (m_array != nullptr)
    {
        delete[] m_array;
    }
    m_count_comparison = m_size = 0;
}

double SortStrategy::getDuration() const{
    std::chrono::duration<double> duration = m_timeEnd - m_timeStart;
    double seconds = duration.count();
    return seconds;
}

void SortStrategy::display()
{
    for (int i = 0; i < m_size; i++)
    {
        std::cout << m_array[i] << " ";
    } 
    std::cout << "\n";
}