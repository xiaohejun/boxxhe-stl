#ifndef ALGORITHM_H_
#define ALGORITHM_H_

#include "config.h"

BEGIN_NAMESPACE_BOXXHE

template<typename Iterator, typename T>
Iterator find(Iterator first, Iterator last, const T& value)
{
    while (first != last && *first != value) {
        ++first;
    }    

    return first;
}


END_NAMESPACE_BOXXHE

#endif
