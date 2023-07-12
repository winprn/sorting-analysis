//
// Created by Ly Dinh Minh Man on 12/07/2023.
//

#ifndef SORTING_ANALYSIS_SORTBASE_H
#define SORTING_ANALYSIS_SORTBASE_H

class SortBase {
protected:
    int *m_array;
    int m_count_comparison = 0, m_size;
public:
    SortBase();
    SortBase(int *a, int size);

    void sort();
    void sortWithComparison();
    int getComparison() const;
};

#endif //SORTING_ANALYSIS_SORTBASE_H
