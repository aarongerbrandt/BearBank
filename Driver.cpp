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

using namespace std;

int main(){
    //Create a binary tree for each user type for quick login
    BinaryTree<SystemAdmin> Admins;
    BinaryTree<BankOfficial> Officials;
    BinaryTree<BankUser> Users;

    bool running = true;
    while(running){
        cout << "[1] Login to System Admin Account\n" <<
        "[2] Login to Bank Official Account\n" <<
        "[3] Login to Bank User Account\n"
        "[4] Exit\n";
        string schoice;
        getline(cin, schoice);
        int choice = stoi(schoice);
        switch(choice){
            case 1:
            {
                //Login to system admin
                cout << "Logging into system admin" << endl;
                break;
            }

            case 2:
            {
                //Login to Bank Official
                cout << "Logging into bank official" << endl;
                break;
            }

            case 3:
            {
                //Login to Bank User
                cout << "Logging into bank user" << endl;
                break;
            }

            case 4:
            {
                //Exit
                cout << "Thank you for using Bear Bank!" << endl;
                running = false;
            }
        }
    }

    

    return 0;
}