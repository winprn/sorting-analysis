#include "SortBase.h"

SortBase::SortBase() {
    m_array = nullptr;
    m_count_comparison = m_size = 0;
}

SortBase::SortBase(int *a, int size) {
    m_size = size;
    m_array = new int[m_size];
    for (int i = 0; i < m_size; i++) m_array[i] = a[i];
}

int SortBase::getComparison() const {
    return m_count_comparison;
}

SortBase::~SortBase()
{
    if (m_array != nullptr)
    {
        delete[] m_array;
    }
    m_count_comparison = m_size = 0;
}

double SortBase::getDuration() const{
    std::chrono::duration<double> duration = m_timeEnd - m_timeStart;
    double seconds = duration.count();
    return seconds;
}