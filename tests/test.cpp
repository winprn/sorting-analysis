#include "test.h"
#include "../include/RadixSort.h"
#include "../include/FlashSort.h"
#include "../src/DataGenerator.h"

TEST_CASE("random data") {
    int *a = new int[10];
    GenerateRandomData(a, 10);
    FlashSort bs(a, 10);
    bs.sort();
    // std::cerr << "Total comparison: " << bs.getComparison() << std::endl;
    CHECK(std::is_sorted(bs.getArray(), bs.getArray() + 10) == 1);
}