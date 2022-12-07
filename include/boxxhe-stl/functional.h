#ifndef FUNCTIONAL_H_
#define FUNCTIONAL_H_

#include "config.h"

BEGIN_NAMESPACE_BOXXHE


template<class T>
struct less {
    bool operator()(const T& x, const T& y) { return x < y; }
    typedef T first_argument_type;
    typedef T second_argument_type;
    typedef bool result_type;
};

template<class T>
struct greater {
    bool operator()(const T& x, const T& y) { return x > y; }
    typedef T first_argument_type;
    typedef T second_argument_type;
    typedef bool result_type;
};





















END_NAMESPACE_BOXXHE

#endif
