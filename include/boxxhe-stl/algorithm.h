#ifndef ALGORITHM_H_
#define ALGORITHM_H_

#include "config.h"
#include "iterator.h"

BEGIN_NAMESPACE_BOXXHE




template<typename InputIterator, typename T>
InputIterator find(InputIterator first, InputIterator last, const T& value)
{
    while (first != last && *first != value) {
        ++first;
    }    

    return first;
}

template<typename InputIterator, typename OuputIterator>
OuputIterator copy(InputIterator first, InputIterator last, OuputIterator result)
{
    for (; first != last; ++first, ++result) {
        *result = *first;
    }

    return result;
}


template<typename ForwardIterator, typename T>
void replace(ForwardIterator first, ForwardIterator last, const T& old_value, const T& new_value)
{
    for (; first != last; ++first) {
        if (*first == old_value) {
            *first = new_value;
        }
    }
}


template<typename ForwardIterator>
ForwardIterator adjacent_find(ForwardIterator first, ForwardIterator last)
{
    if (first == last) { // 空区间
        return last;
    }

    ForwardIterator next = first;
    while (++next != last) {
        if (*first == *next) {
            return first;
        }
        first = next;
    }

    return last;
}

template<typename BidirectionalIterator, class OuputIterator>
OuputIterator reverse_copy(BidirectionalIterator first,
                           BidirectionalIterator last,
                           OuputIterator result)
{
    while (first != last) {
        --last;
        *result = *last;
        ++result;
    }

    return result;
}


template<typename InputIterator>
typename iterator_traits<InputIterator>::value_type
sum_nonempty(InputIterator first, InputIterator last)
{
    typename iterator_traits<InputIterator>::value_type result = *first++;
    for (; first != last; ++first) {
        result += *first;
    }

    return result;
}


END_NAMESPACE_BOXXHE

#endif
