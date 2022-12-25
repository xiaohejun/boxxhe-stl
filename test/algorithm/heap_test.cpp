#include <gtest/gtest.h>
#include <vector>
#include "boxxhe-stl/algorithm.h"

TEST(heap_test, make_heap_basic_test)
{
    std::vector<int> case1 = {3, 2, 4, 1, 5, 9};
    // 默认大顶堆
    boxxhe::make_heap(case1.begin(), case1.end());
    EXPECT_EQ(case1, std::vector<int>({9, 5, 4, 1, 2, 3}));
}

TEST(heap_test, push_heap_basic_test)
{
    std::vector<int> v{3, 1, 4, 1, 5, 9};
    boxxhe::make_heap(v.begin(), v.end());
    EXPECT_EQ(v, std::vector<int>({9, 5, 4, 1, 1, 3}));

    v.push_back(6);
    EXPECT_EQ(v, std::vector<int>({9, 5, 4, 1, 1, 3, 6}));

    boxxhe::push_heap(v.begin(), v.end());
    EXPECT_EQ(v, std::vector<int>({9, 5, 6, 1, 1, 3, 4}));
}

TEST(heap_test, shift_a_int_vector)
{
    std::vector<int> case1 = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
    // case1.begin() + 1也就是数字4开始做sift_down操作
    boxxhe::sift_down(case1.begin(), case1.end(),
        std::less<int>(),
        case1.end() - case1.begin(),
        case1.begin() + 1);
    EXPECT_EQ(case1, std::vector<int>({16, 14, 10, 8, 7, 9, 3, 2, 4, 1}));
}

TEST(heap_test, sort_heap_test)
{
    std::vector<int> v = {3, 1, 4, 1, 5, 9}; 
    std::make_heap(v.begin(), v.end());
    EXPECT_EQ(v, std::vector<int>({9, 5, 4, 1, 1, 3}));
 
    boxxhe::sort_heap(v.begin(), v.end());
    EXPECT_EQ(v, std::vector<int>({1, 1, 3, 4, 5, 9}));
}