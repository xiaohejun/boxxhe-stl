#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include "config.h"
#include <array>
#include <cstddef>

BEGIN_NAMESPACE_BOXXHE



template<typename T, std::size_t Size>
class BinaryHeap {
private:
    std::array<T, Size> data_;

    std::size_t Parent(std::size_t i) { return i >> 1; }
    
    std::size_t Left(std::size_t i) { return (i << 1) + 1; }

    std::size_t Right(std::size_t i) { return (i << 1) + 2; }
public:


};



END_NAMESPACE_BOXXHE


#endif
