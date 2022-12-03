#ifndef ALGORITHM_H_
#define ALGORITHM_H_

#include "config.h"

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






END_NAMESPACE_BOXXHE

#endif
