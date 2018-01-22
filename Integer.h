//
// Created by datas on 22/01/2018.
//

#ifndef UNTITLED_INTEGER_H
#define UNTITLED_INTEGER_H

#include "Interfaces/Comparable.h"

/**
 * A concrete wrapper implementation of Comparable<T> for storing, sorting, finding integers.
 */
class Integer : public Comparable<int>, private Printable {
public:
    Integer( int* value ) : Comparable<int>( value ) {}

    Integer( int _value ) : Comparable<int>( new int( _value )) {}

    inline int* getValue() { return value; }

    inline int compareTo( Comparable<int>* other ) { return *value - *other->getValue(); }

    inline void print() { cout << *value << ", "; }
};


#endif //UNTITLED_INTEGER_H
