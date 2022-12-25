#include <gtest/gtest.h>
#include "boxxhe-stl/algorithm/push_heap.h"
#include "boxxhe-stl/algorithm/make_heap.h"

#include <vector>

TEST(push_heap, basic_test)
{
    std::vector<int> v{3, 1, 4, 1, 5, 9};
    boxxhe::make_heap(v.begin(), v.end());
    EXPECT_EQ(v, std::vector<int>({9, 5, 4, 1, 1, 3}));

    v.push_back(6);
    EXPECT_EQ(v, std::vector<int>({9, 5, 4, 1, 1, 3, 6}));

    boxxhe::push_heap(v.begin(), v.end());
    EXPECT_EQ(v, std::vector<int>({9, 5, 6, 1, 1, 3, 4}));
}