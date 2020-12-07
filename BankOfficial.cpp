#include "BankOfficial.h"
#include <iostream>
#include <string>
#include <ctime>

/*
Open interface opens the GUI from which the user will make selections
*/

void BankOfficial::openInterface(){
    bool running = true;
    while(running){
        cout "[1] Open Account\n
        [2] Close Account\n
        [3] Check Closed Accounts\n
        [4] Access User Account\n
        [5] Search for Account\n
        [6] Logout"
        string soption;
        getline(cin, soption)
        int option = stoi(soption)
        switch option{
            case 1:
            {
                //Open Account
                break;
            }

            case 2:
            {
                //Close account
                break;
            }

            case 3:
            {
                //Check closed accounts
                break;
            }

            case 4:
            {
                //Access User Account
                break;
            }

            case 5:
            {
                //Search for user account
                break;
            }

            case 6:
            {
                //Exit
                running = false;
                break;
            }

            default:
            {
                cout << "Invalid input. Please try again." << endl;
            }
        }
    }
}

/*
openAccount prompts the user for information to create an account and then adds it to the applicable binary tree
*/

/*
closeAccount prompts the user for an account number to close. It then must save the official's 
*/

/*
printClosingLog prints information from closingLog in a clear way
*/

/*
printClosedAccounts takes a vector of closingLog and calls printClosingLog to print them all out
*/

/*
accessAccounts asks for the Account num of the account to be accessed. Once provided with a valid ID, it will then ask for the Username and password to be provided by the
Account owner. Once that is correctly input, then the official can deposit or withdraw from that account
*/

/*
searchAccounts asks the official what criteria they would like to search by(Account Num, Name, PhoneNumber) and searches through the binary tree for that
*/