#ifndef SORTING_ANALYSIS_COUNTINGSORT_H
#define SORTING_ANALYSIS_COUNTINGSORT_H

#include "SortStrategy.h"
class CountingSort : public SortStrategy {
  static const int MAX_VAL = 300005;
  int _cnt[MAX_VAL];
public:
  void sort() override;
  void sortWithComparison() override;
};

#endif // SORTING_ANALYSIS_COUNTINGSORT_H
