#include "BankOfficial.h"
#include "BinaryTree.h"

#include "CD.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"

#include <iostream>
#include <string>
#include <time.h>
#include <ctime>

/*
Open interface opens the GUI from which the user will make selections
*/

void BankOfficial::openInterface(){
    if(active == false){
        cout << "Your account is not active. Please speak to a System Administrator in order to activate it again." << endl;
        return;
    }
    bool running = true;
    while(running){
        cout << "[1] Open Account\n" <<
        "[2] Close Account\n" << 
        "[3] Check Closed Accounts\n" <<
        "[4] Access User Account\n" <<
        "[5] Search for Account\n" <<
        "[6] Logout\n";
        string soption;
        getline(cin, soption);
        int option = stoi(soption);
        switch (option){
            case 1:
            {
                //Open Account
                openAccount();
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

void BankOfficial::openAccount(){
    string soption;
    cout << "[1] Checking Account\n" <<
    "[2] Savings Account\n" <<
    "[3] CD Account\n" <<
    "[4] Cancel\n";
    cout << "What kind of account would you like to open? ";
    getline(cin, soption);
    int option;
    switch(option){
        case 1: //Checking
        {
            string fName, lName, homeAddress, phone, sBal;
            int accountNum;
            double balance;

            cout << "Please enter in your First Name, Last Name, Address and Phone Number, each on their own line. " << endl;
            getline(cin, fName);
            getline(cin, lName);
            getline(cin, homeAddress);
            getline(cin, phone);

            cout << "Now enter in the starting balance." << endl; 
            getline(cin, sBal);
            balance = stod(sBal);

            CheckingAccount cAccount(fName, lName, homeAddress, phone, accountNum, balance);
            //Add to binary tree
        }

        case 2: //Savings
        {
            string fName, lName, homeAddress, phone, sIntRate, sBal;
            int accountNum;
            double balance, interestRate;

            cout << "Please enter in your First Name, Last Name, Address and Phone Number, each on their own line. " << endl;
            getline(cin, fName);
            getline(cin, lName);
            getline(cin, homeAddress);
            getline(cin, phone);

            cout << "Now enter in the interest rate and the starting balance, also on separate lines." << endl;
            getline(cin, sIntRate);
            interestRate = stod(sIntRate);     
            getline(cin, sBal);
            balance = stod(sBal);

            SavingsAccount sAccount(fName, lName, homeAddress, phone, accountNum, interestRate, balance);
            //Add to binary tree
        }

        case 3: //CDAccount
        {
            string fName, lName, homeAddress, phone, sIntRate, sBal;
            time_t opening = time(0), maturity;
            int accountNum; //Figure out how to get account number
            double interestRate, balance;
            cout << "Please enter in your First Name, Last Name, Address and Phone Number, each on their own line. " << endl;
            getline(cin, fName);
            getline(cin, lName);
            getline(cin, homeAddress);
            getline(cin, phone);

            cout << "Now enter in the interest rate and the starting balance, also on separate lines." << endl;
            getline(cin, sIntRate);
            interestRate = stod(sIntRate);     
            getline(cin, sBal);
            balance = stod(sBal);

            cout << "How many days before this account matures? ";
            string sMaturity;
            getline(cin, sMaturity);
            int matureDays = stoi(sMaturity);
            maturity = (matureDays * 60 * 60 * 24); //Converts days to seconds


            CD cdAccount(fName, lName, homeAddress, phone, accountNum, interestRate, balance, opening, maturity);
            //add account to binary tree HERE
        }

        case 4:
        {
            cout << "Exiting." << endl;
            return;
        }
    }
}

/*
closeAccount prompts the user for an account number to close. It then must save the official's info
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