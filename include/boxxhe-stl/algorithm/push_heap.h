#ifndef ALGORITHM_PUSH_HEAP_H_
#define ALGORITHM_PUSH_HEAP_H_


#include <functional>
#include "boxxhe-stl/config.h"
#include "boxxhe-stl/algorithm/sift_up.h"

BEGIN_NAMESPACE_BOXXHE

/*!
 * @brief [first, last)区间中将最后一个元素加入堆
 * @tparam RandomAccessIterator 可随机访问的迭代器类型
 * @tparam Compare 比较函数对象类型
 * @param first 左闭区间
 * @param last 右开区间
 * @param comp 比较函数对象
 */
template <class RandomAccessIterator, class Compare>
inline
void 
push_heap(RandomAccessIterator first, RandomAccessIterator last, Compare comp)
{
    // TODO: 源码里面的这个没看懂是为了啥
    // typedef typename __comp_ref_type<_Compare>::type _Comp_ref;
    boxxhe::sift_up(first, last, comp, last - first);
}

/*!
 * @brief [first, last)区间中将最后一个元素加入堆，默认的大顶堆
 * @tparam RandomAccessIterator 可随机访问的迭代器
 * @param first 左闭区间
 * @param last 右开区间
 */
template <class RandomAccessIterator>
inline
void 
push_heap(RandomAccessIterator first, RandomAccessIterator last)
{
    boxxhe::push_heap(first, last, std::less<typename std::iterator_traits<RandomAccessIterator>::value_type>());
}

END_NAMESPACE_BOXXHE

#endif