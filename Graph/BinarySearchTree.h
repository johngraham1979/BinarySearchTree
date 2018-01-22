//
// @Author: John A Graham
// @Date: 22 January 2018
//

#ifndef UNTITLED_BINARYSEARCHTREE_H
#define UNTITLED_BINARYSEARCHTREE_H

#include "Node.h"
#include "../Interfaces/Comparable.h"


template<typename wrapper, typename wrappedType>
/**
 * What users of this data structure sees and uses.
 *
 * @tparam wrapper
 * @tparam wrappedType
 */
class BinarySearchTree {
private:
    Node<wrapper, wrappedType>* rootNode = nullptr;
public:
    BinarySearchTree() {}

    ~BinarySearchTree() { delete (rootNode); }

    /**
     * Insert a wrapped value.
     *
     * @param wrappedData
     */
    inline void insert( wrapper* wrappedData ) {
        if( rootNode == nullptr ) {
            rootNode = new Node<wrapper, wrappedType>( wrappedData );
        } else {
            rootNode->insert( wrappedData );
        }
    }

    /**
     * find a wrapped value in the tree that matches the value wrapped in the actual parameter.
     *
     * @param wrappedValue
     * @return
     */
    inline wrapper* find( wrapper* wrappedValue ) {
        Node<wrapper, wrappedType>* discoveredNode = nullptr;

        if( rootNode == nullptr )
            return NULL;

        discoveredNode = rootNode->find( wrappedValue );

        if( discoveredNode == nullptr )
            return NULL;

        return discoveredNode->getWrapper();
    }

    /**
     * Print all the values in the tree.
     */
    inline void printValues() {
        this->rootNode->print();
    }
};

#endif //UNTITLED_BINARYSEARCHTREE_H