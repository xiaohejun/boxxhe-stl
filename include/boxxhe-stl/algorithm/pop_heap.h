#ifndef ALGORITHM_POP_HEAP_H
#define ALGORITHM_POP_HEAP_H

#include <algorithm>
#include <iterator>
#include "boxxhe-stl/config.h"
#include "boxxhe-stl/utility/swap.h"
#include "boxxhe-stl/algorithm/sift_down.h"

BEGIN_NAMESPACE_BOXXHE

/*!
 * @brief 将堆顶的第一个元素放到最后的位置，并且保持堆的性质
 * @tparam Compare 比较函数对象类型
 * @tparam RandomAccessIterator 接受可随机访问的迭代器类型
 * @param first 左闭区间
 * @param last 右开区间
 * @param comp 比较函数对象
 * @param len 操作的长度
 */
template <class Compare, class RandomAccessIterator>
inline
void
_pop_heap(RandomAccessIterator first, RandomAccessIterator last, Compare comp,
          typename std::iterator_traits<RandomAccessIterator>::difference_type len)
{
    // len <= 1不用执行操作已经满足
    if (len > 1) {
        // 将堆顶元素和堆尾元素交换
        boxxhe::swap(*first, *--last);
        // 将小的放到堆顶之后堆可能不满足性质了，需要在len - 1的区间里面进行调整     
        boxxhe::sift_down(first, last, comp, len - 1, first);
    }
}

/*!
 * @brief 将堆顶的第一个元素放到最后的位置，并且保持堆的性质
 * @tparam RandomAccessIterator 接受可随机访问的迭代器类型
 * @tparam Compare 比较函数对象类型
 * @param first 左闭区间
 * @param last 右开区间
 * @param comp 比较函数对象
 */
template <class RandomAccessIterator, class Compare>
inline
void
pop_heap(RandomAccessIterator first, RandomAccessIterator last, Compare comp)
{
    // TODO: 没明白这是干啥的
    // typedef typename __comp_ref_type<_Compare>::type _Comp_ref;
    boxxhe::_pop_heap(first, last, comp, last - first);
}

/*!
 * @brief 将堆顶的第一个元素放到最后的位置，并且保持堆的性质，默认大顶堆
 * @tparam RandomAccessIterator 接受可随机访问的迭代器类型
 * @param first 左闭区间
 * @param last 右开区间
 */
template <class RandomAccessIterator>
inline
void
pop_heap(RandomAccessIterator first, RandomAccessIterator last)
{
    boxxhe::pop_heap(first, last, std::less<typename std::iterator_traits<RandomAccessIterator>::value_type>());
}

END_NAMESPACE_BOXXHE

#endif