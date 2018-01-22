//
// @Author: John A Graham
// @Date: 22 January 2018
//

#ifndef UNTITLED_BINARYSEARCHTREE_H
#define UNTITLED_BINARYSEARCHTREE_H

#include "Node.h"
#include "../Interfaces/Comparable.h"


template<typename wrapper, typename wrappedType>

class BinarySearchTree {
private:
    Node<wrapper, wrappedType>* rootNode = nullptr;
public:
    BinarySearchTree() {}

    ~BinarySearchTree() { delete (rootNode); }

    inline void insert( wrapper* wrappedData ) {
        if( rootNode == nullptr ) {
            rootNode = new Node<wrapper, wrappedType>( wrappedData );
        } else {
            rootNode->insert( wrappedData );
        }
    }

    inline wrapper* find( wrapper* value ) {
        Node<wrapper, wrappedType>* discoveredNode = nullptr;

        if( rootNode == nullptr )
            return NULL;

        discoveredNode = rootNode->find( value );

        if( discoveredNode == nullptr )
            return NULL;

        return discoveredNode->getWrapper();
    }

    inline void printValues() {
        this->rootNode->print();
    }
};

#endif //UNTITLED_BINARYSEARCHTREE_H