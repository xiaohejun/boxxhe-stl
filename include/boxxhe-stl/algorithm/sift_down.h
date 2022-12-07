#ifndef SIFT_DOWM_H_
#define SIFT_DOWM_H_

#include "boxxhe-stl/config.h"
#include <iterator>

BEGIN_NAMESPACE_BOXXHE


template<class Compare, class RandomAccessIterator>
void sift_down(RandomAccessIterator first, // 要调整的区间的迭代器first
               RandomAccessIterator, // last, 要调整的区间的迭代器second
               Compare comp, // 比较函数
               typename std::iterator_traits<RandomAccessIterator>::difference_type len, // [first, last)区间的长度
               RandomAccessIterator start) // [first, last)区间中从start开始做sift_down操作
{
    /*
    boxxhe对当前代码的评价（各项指标满分5星）：
        可读性：2星
        运行效率：4星 TODO 附上测试结果
    */
    typedef typename std::iterator_traits<RandomAccessIterator>::difference_type difference_type;
    typedef typename std::iterator_traits<RandomAccessIterator>::value_type value_type;
    
    // child 当前表示了start在[first, last) 区间中的偏移量，也就是在一个数组表示的二叉树中的下标
    // 下标i 的左孩子 2 * i + 1
    // 下标i 的右孩子 2 * i + 2
    difference_type child = start - first;
    if (len < 2 || (len - 2) / 1 < child) {
        // 1. 区间长度小于2, 没有必要调整，已经满足了 
        // 2. start的位置是一个叶子节点，不需要调整
        return;
    }

    // child 指向start的左孩子在[first, last)区间内的偏移量
    child = 2 * child + 1;
    // child_i 当前表示左孩子所在位置对应的迭代器
    RandomAccessIterator child_i = first + child;
    // 如果有右孩子比较右孩子是不是比左孩子大，如果比左孩子大的话child和child_i指向右孩子
    // 由此可知，如果传入的比较函数comp
    // 是less(x, y)，则小的往下沉，小的sift_down
    // 是greater(x, y)，则大的往下沉，大的sift_down
    if ((child + 1) < len && comp(*child_i, *(child_i + 1))) {
        ++child;
        ++child_i;
    }

    if (comp(*child_i, *start)) {
        // 如果start大于他左右孩子的最大值，start已经谁最大的，不用往下沉
        return;
    }

    // top 指向start的值
    // 关键点：使用std::move，避免深拷贝的额外开销
    value_type top(std::move(*start));
    do {
        // 当前情况：
        // *start < (*child_i = max(*start_left_child, *start_right_child))
        // 也就是说child_i指向了start中最大的一个孩子
        // star指向的值小于它的两个孩子
        // 需要将child_i的值移动到start的位置
        // 然后start指向child_i继续处理
        *start = std::move(*child_i);
        start = child_i;

        // 当前child是start迭代器指向的位置对应的在[first, last)中的偏移位置
        // 判断当前是不是已经处理到了叶子节点了，处理到了就不用继续处理了
        if ((len - 2) / 2 < child) {
            break;
        }

        // 继续之前的操作，当前start和它的左右孩子选个最大的
        child = 2 * child + 1;
        child_i = first + child;

        // 如果有右孩子比较右孩子是不是比左孩子大，如果比左孩子大的话child和child_i指向右孩子
        // 由此可知，如果传入的比较函数comp
        // 是less(x, y)，则小的往下沉，小的sift_down
        // 是greater(x, y)，则大的往下沉，大的sift_down
        if ((child + 1) < len && comp(*child_i, *(child_i + 1))) {
            ++child;
            ++child_i;
        }
    } while(comp(*child_i, *start));
    // 当前start指向的位置就是top这个值应该放的位置
    *start = std::move(top);
}

























END_NAMESPACE_BOXXHE

#endif
