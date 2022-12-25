#ifndef UTILITY_SWAP_H
#define UTILITY_SWAP_H

#include <utility>
#include "boxxhe-stl/config.h"

BEGIN_NAMESPACE_BOXXHE

template <class Tp>
inline void swap(Tp& x, Tp& y)
{
    Tp t(std::move(x));
    x = std::move(y);
    y = std::move(t);
}

END_NAMESPACE_BOXXHE

#endif