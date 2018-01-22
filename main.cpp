//
// @Author: John A Graham
// @Date: 22 January 2018
//

#include "Graph/BinarySearchTree.h"
#include "Integer.h"

using namespace std;

// Forward declaration
void addValue( BinarySearchTree<Integer, int>* binarySearchTree );

// Main
int main() {

    srand(( unsigned ) time( 0 ));

    BinarySearchTree<Integer, int>* binarySearchTree = new BinarySearchTree<Integer, int>();

    for( int i = 0; i < 100; i++ )
        addValue( binarySearchTree );

    binarySearchTree->printValues();
    cout << endl;

    Integer* integer = new Integer( 40 );

    Integer* discoveredInteger = binarySearchTree->find( integer );

    if( discoveredInteger == NULL )
        cout << *integer->getValue() << " is not in the tree.";
    else
        cout << *discoveredInteger->getValue() << " is in the tree." << endl;

    delete (discoveredInteger);
    delete (binarySearchTree);

    return 0;
}

void addValue( BinarySearchTree<Integer, int>* binarySearchTree ) {
    // random integer between 0 and 100
    int random_integer = rand() % 100;
    binarySearchTree->insert( new Integer( random_integer ));
}