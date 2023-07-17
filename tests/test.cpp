#include "test.h"
#include "../include/ShakerSort.h"
#include "../src/DataGenerator.h"

TEST_CASE("random data") {
    int sz = 500;
    int *a = new int[sz];
    GenerateRandomData(a, sz);
    ShakerSort bs(a, sz);
    bs.sortWithComparison();
    CHECK(std::is_sorted(bs.getArray(), bs.getArray() + sz) == 1);
}