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

int *SortBase::getArray() const {
    return m_array;
}

int SortBase::getComparison() const {
    return m_count_comparison;
}

int SortBase::getSize() const {
    return m_size;
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

void SortBase::startTimer() {
    m_timeStart = std::chrono::high_resolution_clock::now();
}

void SortBase::stopTimer() {
    m_timeEnd = std::chrono::high_resolution_clock::now();
}

void SortBase::display()
{
    for (int i = 0; i < m_size; i++)
    {
        std::cout << m_array[i] << " ";
    } std::cout << "\n";
}

void SortBase::readFromFile(char* FileName)
{
    std::ifstream ifs(FileName);
    ifs >> m_size;
    if (m_array != nullptr) 
        delete[] m_array;
    m_array = new int[m_size];
    for (int i = 0; i < m_size; i++)
    {
        ifs >> m_array[i];
    }
    ifs.close();
}
