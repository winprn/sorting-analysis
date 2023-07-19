//
// Created by Ly Dinh Minh Man on 12/07/2023.
//

#ifndef SORTING_ANALYSIS_SORTSTRATEGY_H
#define SORTING_ANALYSIS_SORTSTRATEGY_H
#include <algorithm>
#include <chrono>
#include <iostream>
#include <fstream>

class SortStrategy {
 protected:
  int* m_array;
  std::chrono::high_resolution_clock::time_point m_timeStart;
  std::chrono::high_resolution_clock::time_point m_timeEnd;
  int m_count_comparison = 0, m_size;

 public:
  SortStrategy();
  SortStrategy(int* a, int size);
  ~SortStrategy();

    virtual void sort() = 0;
    virtual void sortWithComparison() = 0;
    int *getArray() const;
    int getComparison() const;
    int getSize() const;
  
    // return runtime in seconds
    double getDuration() const;
    void startTimer();
    void stopTimer();

    void writeToFile(std::string FileName);

  void display();
};

#endif  // SORTING_ANALYSIS_SORTSTRATEGY_H
