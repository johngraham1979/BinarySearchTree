//
// @Author: John A Graham
// @Date: 22 January 2018
//

#ifndef UNTITLED_COMPARABLE_H
#define UNTITLED_COMPARABLE_H

#include "Printable.h"

template<typename Type>
class Comparable {
protected:
    Type* value;
public:
    inline Comparable( Type* value ) { this->value = value; }

    virtual inline Type* getValue() { return value; }

    virtual inline int compareTo( Comparable<Type>* other ) { return *this->value - *other->getValue(); }
};

#endif //UNTITLED_COMPARABLE_H
