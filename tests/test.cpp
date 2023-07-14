#include "test.h"
#include "BubbleSort.h"
#include "../src/DataGenerator.h"

TEST_CASE("random data") {
    int *a = new int[10];
    GenerateRandomData(a, 10);
    BubbleSort bs(a, 10);
    bs.sort();
    CHECK(std::is_sorted(bs.getArray(), bs.getArray() + 10) == 1);
}