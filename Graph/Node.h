//
// @Author: John A Graham
// @Date: 22 January 2018
//

#ifndef UNTITLED_NODE_H
#define UNTITLED_NODE_H

#include <iostream>
#include "../Interfaces/Comparable.h"

using namespace std;

template<typename Wrapper, typename WrappedType>
class Node {
private:
    Wrapper* wrappedValue = nullptr;
    Node* leftNode = nullptr;
    Node* rightNode = nullptr;
public:

    ~Node() {
        delete (wrappedValue);

        if( leftNode != nullptr )
            delete (leftNode);

        if( rightNode != nullptr )
            delete (rightNode);
    }

    inline Node( WrappedType* value ) {
        this->wrappedValue = new Wrapper( value );
    }

    inline Node( Wrapper* comparable ) {
        this->wrappedValue = comparable;
    }

    inline Wrapper* getWrapper() { return wrappedValue; }

    inline void print() {
        if( leftNode != nullptr )
            leftNode->print();

        wrappedValue->print();

        if( rightNode != nullptr )
            rightNode->print();

    }

    inline void insert( WrappedType* value ) {
        insert( new Wrapper( value ));
    }

    inline void insert( Wrapper* comparable ) {
        if( this->wrappedValue->compareTo( comparable ) >= 0 ) {

            if( leftNode == nullptr )
                leftNode = new Node<Wrapper, WrappedType>( comparable );
            else
                leftNode->insert( comparable );
        } else {
            if( rightNode == nullptr )
                rightNode = new Node<Wrapper, WrappedType>( comparable );
            else
                rightNode->insert( comparable );
        }
    }

    inline Node<Wrapper, WrappedType>* find( Wrapper* wrappedValue ) {
        if( this->wrappedValue->compareTo( wrappedValue ) > 0 ) {
            if( leftNode != nullptr )
                return leftNode->find( wrappedValue );
            else
                return NULL;
        } else if( this->wrappedValue->compareTo( wrappedValue ) < 0 ) {
            if( rightNode != nullptr )
                return rightNode->find( wrappedValue );
            else
                return NULL;
        } else return this;
    }
};

#endif //UNTITLED_NODE_H
