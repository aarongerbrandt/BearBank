#include "BankOfficial.h"
#include "BinaryTree.h"
#include "Encryption.h"
#include <fstream>

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
                closeAccount();
                break;
            }

            case 3:
            {
                //Check closed accounts
                printClosedAccounts();
                break;
            }

            case 4:
            {
                //Access User Account
                accessAccount();
                break;
            }

            case 5:
            {
                //Search for user account
                searchAccounts();
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

            CheckingAccount cAccount(fName, lName, homeAddress, phone, balance);
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

            SavingsAccount sAccount(fName, lName, homeAddress, phone, interestRate, balance);
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


            CD cdAccount(fName, lName, homeAddress, phone, interestRate, balance, opening, maturity);
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

void BankOfficial::closeAccount(){
    string fName, lName;
    cout << "Please enter the name of the account owner. First name on one line, then Last name." << endl;
    getline(cin, fName);
    getline(cin, lName);
    BankUser* ptr = BankUsers.findAccount(root, fName, lName)
    ptr.open = false;
}

/*
printClosingLog prints information from closingLog in a clear way
*/

void BankOfficial::printClosingLog(ClosingLog log){
    cout << log.closingOfficialName << ", ID#" << log.closingOfficialID << endl;
    cout << "Closed Account #" << log.closedAccountNumber << endl << endl;
    cout << "Their reasoning was : " << reasoning << endl;
    cout << "If you want to contact the owner of the account, " << log.closedOwnerName <<" they can be contacted at " << log.closedPhoneNumber << " or " << log.closedAddress << endl;

}

/*
printClosedAccounts takes a vector of closingLog and calls printClosingLog to print them all out
*/

void BankOfficial::printClosedAccounts(){
    for(int i = 0; i < closedAccounts.size(); i++){
        printClosingLog(closedAccounts.at(i));
    }
}

/*
accessAccounts asks for the username and password of the account owner. The official can then choose which account to access
*/

void BankOfficial::accessAccounts(){
    string user, pass;
    cout << "Account Owner: please enter your username: ";
    getline(cin, user)
    cout << "Account Owner: please enter your password: ";
    getline(cin, pass);
    BankUser *ptr = BankUsers.findAccount(root, user, pass);
    ptr.openInterface();
}

/*
searchAccounts asks the official what criteria they would like to search by(Account Num, Name, PhoneNumber) and searches through the binary tree for that
*/

void BankOfficial::searchAccounts(){
    string schoice;
    cout << "[1] Search by Account Number\n" <<
    "[2] Name\n" <<
    "[3] Phone Number\n"<<
    "[4] Exit\n";
    getline(cin, schoice);
    int choice = stoi(schoice);
    switch(choice){
        case 1:
        {
            //Account NUm
        }

        case 2:
        {
            //Name
        }

        case 3:
        {
            //Phone Number
        }

        case 4:
        {
            //Exit
            return;
        }
    }
}

/*
saveData saves all of the official's information to output.txt
*/

void BankOfficial::saveData(){
    ofstream output("output.txt");
    output << encrypt("BankOfficial") << endl;
    output << encrypt(firstName) << endl << encrypt(lastName) << endl;
    output << encrypt(username) << endl << encrypt(password) << endl;
    if(active == true){
        output << "active" << endl;
    }
    else{
        output << "inactive" << endl;
    }
    //Save transaction log
    output << endl;
}