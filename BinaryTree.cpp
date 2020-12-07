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

/*
insertNode will take an element of Type T, create a node for it, then call Insert and add it to the tree
*/

void BinaryTree::insertNode(T element){
    Node* newNode = new Node;
    newNode -> object = element;
    newNode -> left = nullptr;
    newNode -> right = nullptr

    insert(root, newNode);
}

void BinaryTree::insert(Node *&nodePtr, Node *&newNode){
    if(nodePtr == nullptr){
        nodePtr = newNode;
    }

    else if(newNode -> object -> username.compare(nodePtr -> object -> username) < 0){ //If less than 0, add to left
        insert(nodePtr -> left, newNode);
    }

    else if(newNode -> object -> username.compare(nodePtr -> object -> username) > 0){ //If greater than 0, add to right
        insert(nodePtr -> right, newNode);
    }
}

bool BinaryTree::checkExists(Node *&nodePtr, string s){
    if(nodePtr == nullptr){
        return false;
    }

    if(nodePtr -> object -> username == s){
        return true;
    }

    else if(newNode -> object.username.compare(nodePtr -> object.username) < 0){ //If less than 0, look to left
        return checkExists(nodePtr -> left, newNode);
    }

    else if(newNode -> object.username.compare(nodePtr -> object.username) > 0){ //If greater than 0, add to right
        return checkExists(nodePtr -> right, newNode);
    }
}

T& BinaryTree::search(Node *&nodePtr, string s){
    if(nodePtr == nullptr){
        return nullptr;
    }
    int i = nodePtr -> object.username.compare(s);
    if(i == 0){ //If string equals the username of the object, returns the address of the pointer
        T &reference = nodePtr -> object
        return reference;
    }

    if (i > 0){//nodePtr username is greater than s
        return search(nodePtr -> left, s);
    }

    if (i < 0){
        return search(nodePtr -> right, s);
    }
    else{
        cout << "Error!" << endl;
        return nullptr;
    }
}

/*
Login
*/

void login(string username, string password){//Takes username and password - returns pointer to object if it finds a match
            string User = encrypt(username);
            string pass = encrypt(password);
            T account =  search(root, username);
            /*if (account == nullptr){
                cout << "Error" << endl;
                return nullptr;
            }*/
            account.openInterface();
        }