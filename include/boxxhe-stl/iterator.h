#ifndef ITERATOR_H_
#define ITERATOR_H_

#include "config.h"
#include <ostream>

BEGIN_NAMESPACE_BOXXHE




template<class T>
class ostream_iterator {
private:
    std::ostream *os;
    const char* str;

public:
    explicit ostream_iterator(std::ostream& os, const char *s = nullptr) : os(&os), str(s) {}

    ostream_iterator(const ostream_iterator &oi) : os(oi.os), str(oi.str) {}

    ostream_iterator& operator=(const ostream_iterator &oi) { 
        os = oi.os;
        str = oi.str;
        return *this; 
    }

    ostream_iterator<T>& operator=(const T& value) {
        *os << value;
        if (str != nullptr) {
            *os << str;    
        }
        
        return *this;
    }

    ostream_iterator<T>& operator*() { return *this; }

    ostream_iterator<T>& operator++() { return *this; }

    ostream_iterator<T>& operator++(int) { return *this; }
};














END_NAMESPACE_BOXXHE

#endif
