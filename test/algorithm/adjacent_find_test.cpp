#include "boxxhe-stl/algorithm.h"
#include <gtest/gtest.h>

using namespace BOXXHE;

TEST(adjacent_find_test, adjacent_find_in_arrary)
{
    int a[10] = {1, 2, 44444, 5, -1, 3, 23, 12, 0, 1212};
    EXPECT_EQ(adjacent_find(a, a + 10), a + 10);
}

