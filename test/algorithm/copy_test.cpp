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
