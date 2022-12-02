#include "boxxhe-stl/algorithm.h"
#include <gtest/gtest.h>
#include <cstddef>

using namespace BOXXHE;

TEST(copy_test, copy_arrary)
{
    int a[] = {1, 2, 3, 4, 5};
    int b[10];
    copy(a, a + 5, b);
    for (size_t i = 0; i < 5; ++i) {
        EXPECT_EQ(b[i], i + 1);
    }
}
