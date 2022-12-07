#ifndef MAKE_HEAP_H_
#define MAKE_HEAP_H_

#include "boxxhe-stl/config.h"
#include "boxxhe-stl/algorithm/sift_down.h"
#include "boxxhe-stl/iterator.h"
#include <functional>
#include <iterator>

BEGIN_NAMESPACE_BOXXHE

template<class Compare, class RandomAccessIterator>
void _make_heap(RandomAccessIterator first, RandomAccessIterator last, Compare comp)
{
    typedef typename std::iterator_traits<RandomAccessIterator>::difference_type difference_type;

    // 传入的区间是[first, last), n计算了区间包含的元素个数
    difference_type n = last - first;
    
    if (n <= 1) {
        // 区间中元素少于1个，不用调整已经满足heap数据结构的要求了
        return;
    }

    // 如果代码走到这里说明区间中元素个数大于等于2，需要调整使其满足heap性质
    // 从最后一个非叶子节点开始调整，最后一个非叶子节点就是最后一个叶子节点的父亲 
    // start
    for (difference_type start = (n - 2) / 2; start >= 0; --start) {
        BOXXHE::sift_down(first, last, comp, n, first + start);
    }
}

template<class RandomAccessIterator, class Compare>
inline
void
make_heap(RandomAccessIterator first, RandomAccessIterator last, Compare comp)
{
    BOXXHE::_make_heap(first, last, comp);
}

template<class RandomAccessIterator>
inline
void
make_heap(RandomAccessIterator first, RandomAccessIterator last)
{
    // 没有传比较函数对象的话，默认使用<，也就是生成大顶堆
    BOXXHE::_make_heap(first, last, std::less<typename std::iterator_traits<RandomAccessIterator>>::value_type());
}

END_NAMESPACE_BOXXHE

#endif
