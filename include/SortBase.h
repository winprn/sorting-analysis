//
// Created by Ly Dinh Minh Man on 12/07/2023.
//

#ifndef SORTING_ANALYSIS_SORTBASE_H
#define SORTING_ANALYSIS_SORTBASE_H
#include <algorithm>
#include <chrono>
#include <iostream>

class SortBase {
protected:
    int *m_array;
    std::chrono::high_resolution_clock::time_point m_timeStart;
    std::chrono::high_resolution_clock::time_point m_timeEnd;
    int m_count_comparison = 0, m_size;
public:
    SortBase();
    SortBase(int *a, int size);
    ~SortBase();

    void sort();
    void sortWithComparison();
    int *getArray() const;
    int getComparison() const;
  
    // return runtime in seconds
    double getDuration() const;

    void display();
};

#endif //SORTING_ANALYSIS_SORTBASE_H
