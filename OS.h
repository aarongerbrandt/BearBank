#ifndef OS_H
#define OS_H

#include "SystemAdmin.h"
#include "BankOfficial.h"
#include "BankUser.h"

#include "BinaryTree.h"
#include <string>
#include <iostream>

//Create a binary tree for each user type for quick login

void systemAdminLogin(){
    string username, password;
    cout << "Please enter your username: ";
    getline(cin, username);
    
    cout << "Please enter your password: ";
    getline(cin, password);
    
    Admins.login(username, password);
}


void bankOfficialLogin(){
    string username, password;
    cout << "Please enter your username: ";
    getline(cin, username);
    cout << "Please enter your password: ";
    getline(cin, password);

    Officials.login(username, password);
}
void bankUserLogin(){
    string username, password;
    cout << "Please enter your username: ";
    getline(cin, username);
    cout << "Please enter your password: ";
    getline(cin, password);

    Users.login(username, password);
}

#endif