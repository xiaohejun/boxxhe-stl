
#include "boxxhe-stl/algorithm.h"
#include <gtest/gtest.h>

using namespace BOXXHE;

TEST(replace_test, replace_int_array_then_find)
{
    int a[10] = {1, 2, 44444, 5, -1, 3, 23, 12, 0, 1212};
    replace(a, a + 10, 5, 6);

    EXPECT_EQ(a[3], 6);
    EXPECT_EQ(find(a, a + 10, 5), a + 10);
}

