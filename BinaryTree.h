#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <string>
#include "Encryption.h"

using namespace std;

/*
The Binary Tree is used to hold User Accounts so they may be traversed quickly
*/

template <class T>
class BinaryTree{
    private:
        struct Node{
            T object;
            Node* right;  //Right subtree
            Node* left;   //Left subtree
        };
        Node* previous = nullptr; //used for deletion

        Node* root; //Root node of tree

        void insert(Node *&, Node *&); //Inserts a node of type T
        bool checkExists(Node *&, string); //Returns true if the value exists in the tree
        void displayTree(Node *&); //Displays tree inorder
        T& search(Node *&, string); //Returns address to object with that username
        int countNodes(Node *&);
        int countAccounts(Node *&);
        T& findAccount(Node*&, string, string)

    public:
        /*BinaryTree(){root = nullptr;}
        ~BinaryTree(){};*/
        void display();

        int getNodeCount();

        void insertNode(T); //Will take an element of Type T, create a node for it, then call Insert and add it to the tree

        T& searchTree(string element, Node*&);
        
        void login(string username, string password);//Takes username and password - returns pointer to object if it finds a match

};

/*
searchTree
*/

template <class T>
T& BinaryTree<T>::searchTree(string element, Node*& root){
    if(BinaryTree<T>::checkExists(root, element)==true){
        T* account = BinaryTree<T>::search(root, element);
        return account;
    }
else{
    cout << "Username does not exist." << endl;
    return nullptr;
}
}

#endif