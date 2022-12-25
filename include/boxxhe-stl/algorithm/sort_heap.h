#ifndef ALGORITHM_SORT_HEAP_H
#define ALGORITHM_SORT_HEAP_H

#include <functional>
#include <iterator>
#include "boxxhe-stl/config.h"
#include "boxxhe-stl/algorithm/pop_heap.h"

BEGIN_NAMESPACE_BOXXHE

template <class Compare, class RandomAccessIterator>
void
_sort_heap(RandomAccessIterator first, RandomAccessIterator last, Compare comp)
{
    typedef typename std::iterator_traits<RandomAccessIterator>::difference_type difference_type;
    for (difference_type n = last - first; n > 1; --last, --n) {
        boxxhe::_pop_heap<Compare>(first, last, comp, n);
    }
}

template <class RandomAccessIterator, class Compare>
inline
void
sort_heap(RandomAccessIterator first, RandomAccessIterator last, Compare comp)
{
    boxxhe::_sort_heap(first, last, comp);
}

template <class RandomAccessIterator>
inline
void
sort_heap(RandomAccessIterator first, RandomAccessIterator last)
{
    boxxhe::sort_heap(first, last, std::less<typename std::iterator_traits<RandomAccessIterator>::value_type>());
}

END_NAMESPACE_BOXXHE

#endif