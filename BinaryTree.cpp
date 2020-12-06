#include "BinaryTree.h"
#include <iostream>
#include <string>

/*
Display prints all elements of the tree inorder
*/

void BinaryTree::displayTree(Node *nodePtr){
    if(nodePtr){
        displayTree(nodePtr -> left);
        cout << object.printData() << endl;
        displayTree(nodePtr -> right);
    }
}

