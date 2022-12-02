#include "boxxhe-stl/algorithm.h"
#include <gtest/gtest.h>

using namespace BOXXHE;

TEST(FIND_TEST, find_in_arrary)
{
  EXPECT_TRUE(true);
    int a[10] = {1, 2, 44444, 5, -1, 3, 23, 12, 0, 1212};
    EXPECT_EQ(*find(a, a + 10, 0), 0);
    EXPECT_EQ(find(a, a + 10, 444444), a + 10);
}

