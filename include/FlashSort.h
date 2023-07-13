#include "SortBase.h"

#ifndef FLASH_SORT
#define FLASH_SORT

class FlashSort : public SortBase {
public:
    FlashSort(): SortBase(){}
    void sort();
    void sortWithComparison();
};

#endif