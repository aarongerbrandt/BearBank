#include "BinaryTree.h"
#include <iostream>
#include <string>

using namespace std;

/*
display calls displayTree
*/
template <class T>
void BinaryTree<T>::display(){
    displayTree(root);
}

/*
Display prints all elements of the tree inorder
*/

template <class T>
void BinaryTree<T>::displayTree(Node *&nodePtr){
    if(nodePtr){
        displayTree(nodePtr -> left);
        cout << nodePtr -> object.printData() << endl;
        displayTree(nodePtr -> right);
    }
}

/*
insertNode will take an element of Type T, create a node for it, then call Insert and add it to the tree
*/

template <class T>
void BinaryTree<T>::insertNode(T element){
    Node* newNode = new Node;
    newNode -> object = element;
    newNode -> left = nullptr;
    newNode -> right = nullptr;

    insert(root, newNode);
}

template <class T>
void BinaryTree<T>::insert(Node *&nodePtr, Node *&newNode){
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

template <class T>
bool BinaryTree<T>::checkExists(Node *&nodePtr, string s){
    if(nodePtr == nullptr){
        return false;
    }

    if(nodePtr -> object -> username == s){
        return true;
    }

    else if(s.compare(nodePtr -> object.username) < 0){ //If less than 0, look to left
        return checkExists(nodePtr -> left, s);
    }

    else if(s.compare(nodePtr -> object.username) > 0){ //If greater than 0, add to right
        return checkExists(nodePtr -> right, s);
    }
}

template <class T>
T& BinaryTree<T>::search(Node *&nodePtr, string s){
    if(nodePtr == nullptr){
        return nullptr;
    }
    int i = nodePtr -> object.username.compare(s);
    if(i == 0){ //If string equals the username of the object, returns the address of the pointer
        T &reference = nodePtr -> object;
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

template <class T>
void BinaryTree<T>::login(string username, string password){//Takes username and password - returns pointer to object if it finds a match
            string User = encrypt(username);
            string pass = encrypt(password);
            T* account = search(root, username);
            /*if (account == nullptr){
                cout << "Error" << endl;
                return nullptr;
            }*/
            account.openInterface();
        }

/*
getNodeCount calls countNodes and gives it the root pointer
*/

template <class T>
int BinaryTree<T>::getNodeCount(){
    int i = countNodes(root);
    return i;
}

/*
countNodes counts nodes through the use of recursion
*/

template <class T>
int BinaryTree<T>::countNodes(Node *&nodePtr){
    if(nodePtr == nullptr){
        return 0;
    }
    else{
        return(1 + countNodes(nodePtr -> left) + countNodes(nodePtr -> right));
    }
}

template <class T>
int BinaryTree<T>::countAccounts(Node *&nodePtr){
    if(nodePtr == nullptr){
        return 0;
    }
    else{
        return((nodePtr -> object -> CheckingAccounts.size()+1) + (nodePtr -> object -> savingsAccounts.size()+1) + (nodePtr -> object -> CDAccounts.size()+1) + countAccounts(nodePtr -> left) + countAccounts(nodePtr -> right));
    }
}

template <class T>
T& BinaryTree::findAccount(Node *&nodePtr, string user, string pass){
    if(nodePtr == nullptr){
        return nullptr;
    }
    if(nodePtr -> object.username == user){
        if(nodePtr -> object.password == pass){
            return &nodePtr -> object;
        }
    }
    else{
        return findAccount(nodePtr -> left, user, pass);
        return findAccount(nodePtr -> right, user, pass);
    }
}

