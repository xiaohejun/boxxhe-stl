#include "boxxhe-stl/algorithm.h"
#include <gtest/gtest.h>

using namespace boxxhe;

TEST(adjacent_find_test, adjacent_find_in_arrary)
{
    int a[10] = {1, 2, 44444, 5, -1, 3, 23, 12, 0, 1212};
    EXPECT_EQ(adjacent_find(a, a + 10), a + 10);
}

TEST(copy_test, copy_arrary)
{
    int a[] = {1, 2, 3, 4, 5};
    int b[10];
    copy(a, a + 5, b);
    for (size_t i = 0; i < 5; ++i) {
        EXPECT_EQ(b[i], i + 1);
    }
}


TEST(reverse_copy_test, recerse_copy_test)
{
    int a[10] = {0};
    int b[10] = {0};
    for (size_t i = 0; i < 10; ++i) {
        a[i] = int(i);
    }
    reverse_copy(a, a + 10, b);
    for (size_t i = 0; i < 10; ++i) {
        EXPECT_EQ(b[i], 10 - i - 1);
    }
}

TEST(find_test, find_in_arrary)
{
    int a[10] = {1, 2, 44444, 5, -1, 3, 23, 12, 0, 1212};
    EXPECT_EQ(*find(a, a + 10, 0), 0);
    EXPECT_EQ(find(a, a + 10, 444444), a + 10);
}

TEST(replace_test, replace_int_array_then_find)
{
    int a[10] = {1, 2, 44444, 5, -1, 3, 23, 12, 0, 1212};
    replace(a, a + 10, 5, 6);

    EXPECT_EQ(a[3], 6);
    EXPECT_EQ(find(a, a + 10, 5), a + 10);
}

TEST(sum_nonemptytest, sum_int_arrary)
{
    int a[6] = {1, 2, 3, 3, 2, 1};
    EXPECT_EQ(sum_nonempty(a, a + 6), 12);
    EXPECT_EQ(sum_nonempty(a, a + 1), 1);
}





