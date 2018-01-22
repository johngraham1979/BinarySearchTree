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
/**
 * Binary Search Tree Nodes.
 * Could be used for other types of graphs.
 *
 * @tparam Wrapper
 * @tparam WrappedType
 */
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

    /**
     * Wrap the value, then call insert.
     *
     * @param value
     */
    inline void insert( WrappedType* value ) {
        insert( new Wrapper( value ));
    }

    /**
     * Insert the wrappedValue at the appropriate place in the tree.
     *
     * @param wrappedValue
     */
    inline void insert( Wrapper* wrappedValue ) {
        if( this->wrappedValue->compareTo( wrappedValue ) >= 0 ) {

            if( leftNode == nullptr )
                leftNode = new Node<Wrapper, WrappedType>( wrappedValue );
            else
                leftNode->insert( wrappedValue );
        } else {
            if( rightNode == nullptr )
                rightNode = new Node<Wrapper, WrappedType>( wrappedValue );
            else
                rightNode->insert( wrappedValue );
        }
    }

    /**
     * Recursively find a tree node that the same wrapped value as
     * that wrapped by actual parameter.
     *
     * @param wrappedValue
     * @return
     */
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
