#include <gtest/gtest.h>
#include "boxxhe-stl/algorithm/make_heap.h"

TEST(make_heap, basic_test)
{
    std::vector<int> case1 = {3, 2, 4, 1, 5, 9};
    // 默认大顶堆
    BOXXHE::make_heap(case1.begin(), case1.end());
    EXPECT_EQ(case1, std::vector<int>({9, 5, 4, 1, 2, 3}));
}