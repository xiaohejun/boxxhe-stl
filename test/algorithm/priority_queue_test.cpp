#include <gtest/gtest.h>
#include "boxxhe-stl/queue.h"
    
TEST(priority_queue, basic_test)
{
    boxxhe::priority_queue<int> q1;
    q1.push(1);
    q1.push(2);
    EXPECT_FALSE(q1.empty());
    EXPECT_EQ(q1.top(), 2);
    EXPECT_EQ(q1.size(), 2);

    boxxhe::priority_queue<int> q2(q1);
    EXPECT_EQ(q2.top(), 2);
    EXPECT_EQ(q2.size(), 2);

    boxxhe::priority_queue<int> q3;
    q3 = q2;
    EXPECT_EQ(q3.top(), 2);
    EXPECT_EQ(q3.size(), 2);

    boxxhe::priority_queue<int> q4(std::move(q3));
    EXPECT_TRUE(q3.empty());
    EXPECT_EQ(q3.size(), 0);
    EXPECT_FALSE(q4.empty());
    EXPECT_EQ(q4.top(), 2);
    EXPECT_EQ(q4.size(), 2);

    boxxhe::priority_queue<int> q5;
    q5 = std::move(q4);
    EXPECT_TRUE(q4.empty());
    EXPECT_EQ(q4.size(), 0);
    EXPECT_FALSE(q5.empty());
    EXPECT_EQ(q5.top(), 2);
    EXPECT_EQ(q5.size(), 2);

    struct MyComp {
        bool operator()(const int& x, const int& y) { return x > y; }
    };
    boxxhe::priority_queue<int, std::vector<int>, MyComp> q6{MyComp()};
    q6.push(1002);
    q6.push(1000);
    q6.push(1001);
    EXPECT_FALSE(q6.empty());
    EXPECT_EQ(q6.size(), 3);
    EXPECT_EQ(q6.top(), 1000);
    q6.pop();
    EXPECT_EQ(q6.top(), 1001);

    std::vector<int> v1{1, 6, -1, 2, 5};
    boxxhe::priority_queue<int, std::vector<int>, MyComp> q7{MyComp(), v1};
    EXPECT_EQ(q7.size(), v1.size());
    EXPECT_EQ(q7.top(), -1);

    boxxhe::priority_queue<int, std::vector<int>, MyComp> q8(MyComp(), std::move(v1));
    EXPECT_FALSE(q8.empty());
    EXPECT_EQ(q8.size(), 5);
    EXPECT_EQ(q8.top(), -1);
    EXPECT_EQ(v1.size(), 0);
    EXPECT_TRUE(v1.empty());

    std::vector<int> v2{1, 2, -100, 1};
    boxxhe::priority_queue<int, std::vector<int>, MyComp> q9(v2.begin(), v2.end(), MyComp());
    EXPECT_FALSE(q9.empty());
    EXPECT_EQ(q9.top(), -100);
    EXPECT_EQ(q9.size(), v2.size());

    boxxhe::priority_queue<int, std::vector<int>, MyComp> q10(v2.begin(), v2.end(), MyComp(), v2);
    EXPECT_FALSE(q10.empty());
    EXPECT_EQ(q10.top(), -100);
    EXPECT_EQ(q10.size(), 2 * v2.size());

    boxxhe::priority_queue<int, std::vector<int>, MyComp> q11(v2.begin(), v2.end(), MyComp(), std::move(v2));
    EXPECT_FALSE(q11.empty());
    EXPECT_EQ(q11.top(), -100);
    EXPECT_EQ(q11.size(), 8);
    EXPECT_TRUE(v2.empty());
    EXPECT_EQ(v2.size(), 0);

    q7.swap(q9);
    EXPECT_EQ(q7.size(), 4);
    EXPECT_EQ(q7.top(), -100);
    EXPECT_FALSE(q9.empty());
    EXPECT_EQ(q9.top(), -1);
    EXPECT_EQ(q9.size(), 5);

    boxxhe::swap(q7, q9);
    EXPECT_EQ(q9.size(), 4);
    EXPECT_EQ(q9.top(), -100);
    EXPECT_FALSE(q7.empty());
    EXPECT_EQ(q7.top(), -1);
    EXPECT_EQ(q7.size(), 5);
}
