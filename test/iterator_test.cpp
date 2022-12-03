#include "boxxhe-stl/algorithm.h"
#include "boxxhe-stl/iterator.h"
#include <gtest/gtest.h>

using namespace BOXXHE;

TEST(ostream_iterator_test, output_arrary)
{
    int a[10] = {1, 2, 44444, 5, -1, 3, 23, 12, 0, 1212};
    copy(a, a + 10, ostream_iterator<int>(std::cout, ", "));
}

