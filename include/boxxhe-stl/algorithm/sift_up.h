#ifndef ALGORITHM_SIFT_UP_H_
#define ALGORITHM_SIFT_UP_H_

#include <iterator>
#include "boxxhe-stl/config.h"

BEGIN_NAMESPACE_BOXXHE

/*!
 * @brief 堆中做sift_up操作
 * @tparam Compare 比较函数对象类型
 * @tparam RandomAccessIterator 容器的迭代器必须是可随机访问的
 * @param first 左闭区间
 * @param last 右开区间
 * @param comp 比较函数
 * @param len 区间长度
 */
template <class Compare, class RandomAccessIterator>
void
sift_up(RandomAccessIterator first, RandomAccessIterator last, Compare comp,
        typename std::iterator_traits<RandomAccessIterator>::difference_type len)
{
    typedef typename std::iterator_traits<RandomAccessIterator>::value_type value_type;
    // 区间长度>1才处理，区间长度<=1不需要调整
    if (len > 1) {
        // len: 作为入参表示区间长度，即len = last - first
        // len - 1：表示[first, last)区间中last - 1对应的下标
        // len = ((len - 1) - 1) = (len - 2) / 2 计算之后
        // len 表示堆中最后一个叶子节点的父亲，即非叶子节点的下标
        len = (len - 2) / 2;
        // ptr：迭代器指向下标len对应的元素
        RandomAccessIterator ptr = first + len;
        // 如果最后一个元素也就是最后一个叶子节点的值（*--last）
        // 大于ptr即其父亲指向的值，需要做调整操作
        if (comp(*ptr, *--last)) {
            // 取得last指向的值
            value_type t(std::move(*last));
            do {
                *last = std::move(*ptr);
                last = ptr;
                if (len == 0) {
                    // len表示父亲节点所在偏移量，已经处理到根节点了
                    // 就应该退出了
                    break;
                }
                // len和ptr继续向上指向父亲节点
                len = (len - 1) / 2;
                ptr = first + len;
            } while (comp(*ptr, *last));
            // 最后需要把剩下的last的位置放上t
            *last = std::move(t);
        }
    }
}

END_NAMESPACE_BOXXHE

#endif