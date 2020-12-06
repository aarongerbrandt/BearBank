#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
#include "Encryption.h"

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
        bool checkExists(Node *&, T); //Returns true if the value exists in the tree
        void displayTree(Node *&); //Displays tree inorder

    public:
        BinaryTree(){ //Constructor
            root = nullptr;
        }

        ~BinaryTree(){//Destructor
        }

        void display(){
            displayTree(root);
        }

        void insertNode(T); //Will take an element of Type T, create a node for it, then call Insert and add it to the tree

        bool search(T element){
            if (checkExists(root, element)){
                return true;
            }
            else{
                return false;
            }
        }

        T* login(string username, string password){//Takes username and password - returns pointer to object if it finds a match
            string User = encrypt(username);
            string pass = encrypt(password);

        }
};

#endif