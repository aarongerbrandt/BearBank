#include <iostream>
#include <string>
#include <vector>
#include "BinaryTree.h"

#include "SystemAdmin.h"
#include "BankOfficial.h"
#include "BankUser.h"

#include "CD.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"

//#include "OS.h"

using namespace std;

BinaryTree<SystemAdmin> Admins;
BinaryTree<BankOfficial> Officials;
BinaryTree<BankUser> Users;

void systemAdminLogin();
void bankOfficialLogin();
void bankUserLogin();

int main(){
    
    bool running = true;
    while(running){
        cout << "[1] Login to System Admin Account\n" <<
        "[2] Login to Bank Official Account\n" <<
        "[3] Login to Bank User Account\n" <<
        "[4] Exit\n";
        string schoice;
        getline(cin, schoice);
        int choice = stoi(schoice);
        switch(choice){
            case 1:
            {
                //Login to system admin
                cout << "Logging into system admin" << endl;
                //systemAdminLogin();
                break;
            }

            case 2:
            {
                //Login to Bank Official
                cout << "Logging into bank official" << endl;
                //bankOfficialLogin();
                break;
            }

            case 3:
            {
                //Login to Bank User
                cout << "Logging into bank user" << endl;
                //bankUserLogin();
                break;
            }

            case 4:
            {
                //Exit
                cout << "Thank you for using Bear Bank!" << endl;
                running = false;
            }

            default:
            {
                cout << "Invalid input. Please try again!" << endl;
            }
        }
    }

    

    return 0;
}


/*
Login functions for each user type
takes a user and password and then searches for them in the applicable binary tree.
*/

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

