#include "boxxhe-stl/algorithm/sift_down.h"
#include <gtest/gtest.h>

TEST(sift_down, shift_a_int_vector)
{
    std::vector<int> case1 = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
    // case1.begin() + 1也就是数字4开始做sift_down操作
    BOXXHE::sift_down(case1.begin(), case1.end(),
        std::less<int>(),
        case1.end() - case1.begin(),
        case1.begin() + 1);
    EXPECT_EQ(case1, std::vector<int>({16, 14, 10, 8, 7, 9, 3, 2, 4, 1}));
}