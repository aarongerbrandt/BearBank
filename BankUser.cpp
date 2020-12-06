#include <iostream>
#include <string>
#include "BankUser.h"

using namespace std;

/*
openInterface opens a GUI for the user to make their decisions in
*/

void BankUser::openInterface(){
    cout << "Welcome, " << firstName << " to BearBank! Please make a decision of the options printed below. Have a good day!" << endl;
    bool running = True;
    while(running){
        cout << "[1] View Accounts\n
        [2] Change Password\n
        [3] Make Withdrawal\n
        [4] Make Deposit\n
        [5] Logout\n"
        int choice;
        getline(cin, choice);
        switch(choice){
            case 1:
                {
                    //View accounts
                    break;
                }

            case 2:
                {
                    //Change password
                    break;
                }
            
            case 3:
                {
                    //Make withdrawal
                    break;
                }

            case 4:
                {
                    //Make deposit
                    break;
                }

            case 5:
                {
                    //Logout
                    cout << "Have a good day!" << endl;
                    running = false;
                }
        }
    }
}

/*
Change Password function prompts the user for their current login/password, encrypts it, 
checks if it matches any in the binary tree, if it does, return a pointer to the object and change password.
*/

/*
Display Accounts will iterate through each vector and print any account they hold
*/

/*
checkTransactions will iterate through each of the Transactions of each account vector. It will see if any were within 24 hours and if so, print out
the time, from what account, and how much was added/subtracted
*/ 