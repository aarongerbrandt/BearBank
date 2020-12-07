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
                    makeWithdrawal();
                    break;
                }

            case 4:
                {
                    //Make deposit
                    makeDeposit();
                    break;
                }

            case 5:
                {
                    //Logout
                    cout << "Have a good day!" << endl;
                    running = false;
                    break;
                }
            
            default:
                {
                    cout << "Invalid Input. Please try again." << endl;
                    break;
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

void BankUser::displayAccounts(){
    //Display Checking
    cout << "\nChecking Accounts: \n";
    for (int i = 0; i < CheckingAccounts.size(); i++){ //Iterates through Checking Accounts
        CheckingAccounts.at(i).displayData();          //Displays data
    }
    //Display Savings
    cout << "\nSavings Accounts: \n";
    for (int i = 0; i < SavingsAccounts.size(); i++){ //Iterates through Savings Accounts
        SavingsAccounts.at(i).displayData();          //Displays data
    }
    //Display CD
    cout << "\nCD Accounts: \n";
    for (int i = 0; i < CDAccounts.size(); i++){ //Iterates through CD Accounts
        CDAccounts.at(i).displayData();          //Displays data
    }
}

/*
checkTransactions will iterate through each of the Transactions of each account vector. It will see if any were within 24 hours and if so, print out
the time, from what account, and how much was added/subtracted
*/ 

/*
makeDeposit will determine which account the user wants to make the deposit from, and then call the deposit function with it
*/

void BankUser::makeDeposit(){
    bool running = true;
    while(running){
        cout << "What kind of account would you like to deposit to?\n
        [1] Checking Account\n
        [2] Savings Account\n
        [3] CD Account\n
        [4] Cancel\n";
        string soption;
        getline(cin, soption);
        int option = stoi(soption);
        switch(option){
            case 1:
            {
                //Checking account
                if(CheckingAccounts.size() = 0){
                    cout << "You do not have any checking accounts. Please try again." << endl;
                    break;
                }
                cout << "Which account would you like to deposit to?" << endl;
                for(int i = 0; i < CheckingAccounts.size(); i++){
                    accountNum = CheckingAccounts.at(i).getAccountNumber();
                    cout << "[" << i+1 << "] " << accountNum << endl;
                }
                string schoice;
                getline(cin, schoice);
                int choice = stoi(schoice);
                if (choice <= CheckingAccounts.size()+1){
                    CheckingAccounts.at(choice-1).deposit();
                    return;
                }
                else{
                    cout << "Invalid input." << endl;
                    return;
                }
            }

            case 2:
            {
                //Savings account
                if(SavingsAccounts.size() = 0){
                    cout << "You do not have any savings accounts. Please try again." << endl;
                    break;
                }
                cout << "Which account would you like to deposit to?" << endl;
                for(int i = 0; i < SavingsAccounts.size(); i++){
                    accountNum = SavingsAccounts.at(i).getAccountNumber();
                    cout << "[" << i+1 << "] " << accountNum << endl; //Print out all accounts with a number
                }
                
                string schoice;
                getline(cin, schoice);
                int choice = stoi(schoice);

                if (choice <= SavingsAccounts.size()+1){ //If input is in reasonable range
                    SavingsAccounts.at(choice-1).deposit();
                    return;
                }
                else{
                    cout << "Invalid input." << endl;
                    return;
                }
            }

            case 3:
            {
                //CD Account
                if(CDAccounts.size() = 0){
                    cout << "You do not have any Certificate of Deposit accounts. Please try again." << endl;
                    break;
                }
                cout << "Which account would you like to deposit to?" << endl;
                for(int i = 0; i < CDAccounts.size(); i++){
                    accountNum = CDAccounts.at(i).getAccountNumber();
                    cout << "[" << i+1 << "] " << accountNum << endl;
                }
                string schoice;
                getline(cin, schoice);
                int choice = stoi(schoice);
                if (choice <= CDAccounts.size()+1){
                    CDAccounts.at(choice-1).deposit();
                    return;
                }
                else{
                    cout << "Invalid input." << endl;
                    return;
                }                
            }

            case 4:
            {
                //Exit
                running = false
            }

            default:
            {
                cout << "Invalid response, please try again." << endl;
            }
        }
    }
    return;
}

void BankUser::makeWithdrawal(){
    bool running = true;
    while(running){
        cout << "What kind of account would you like to withdraw from?\n
        [1] Checking Account\n
        [2] Savings Account\n
        [3] CD Account\n
        [4] Cancel\n";
        string soption;
        getline(cin, soption);
        int option = stoi(soption);
        switch(option){
            case 1:
            {
                //Checking account
                if(CheckingAccounts.size() = 0){
                    cout << "You do not have any checking accounts. Please try again." << endl;
                    break;
                }
                cout << "Which account would you like to withdraw from?" << endl;
                for(int i = 0; i < CheckingAccounts.size(); i++){
                    accountNum = CheckingAccounts.at(i).getAccountNumber();
                    cout << "[" << i+1 << "] " << accountNum << endl;
                }
                string schoice;
                getline(cin, schoice);
                int choice = stoi(schoice);
                if (choice <= CheckingAccounts.size()+1){
                    CheckingAccounts.at(choice-1).withdraw();
                    return;
                }
                else{
                    cout << "Invalid input." << endl;
                    return;
                }
            }

            case 2:
            {
                //Savings account
                if(SavingsAccounts.size() = 0){
                    cout << "You do not have any savings accounts. Please try again." << endl;
                    break;
                }
                cout << "Which account would you like to withdraw from?" << endl;
                for(int i = 0; i < SavingsAccounts.size(); i++){
                    accountNum = SavingsAccounts.at(i).getAccountNumber();
                    cout << "[" << i+1 << "] " << accountNum << endl; //Print out all accounts with a number
                }
                
                string schoice;
                getline(cin, schoice);
                int choice = stoi(schoice);

                if (choice <= SavingsAccounts.size()+1){ //If input is in reasonable range
                    SavingsAccounts.at(choice-1).withdraw();
                    return;
                }
                else{
                    cout << "Invalid input." << endl;
                    return;
                }
            }

            case 3:
            {
                //CD Account
                if(CDAccounts.size() = 0){
                    cout << "You do not have any Certificate of Deposit accounts. Please try again." << endl;
                    break;
                }
                cout << "Which account would you like to withdraw from?" << endl;
                for(int i = 0; i < CDAccounts.size(); i++){
                    accountNum = CDAccounts.at(i).getAccountNumber();
                    cout << "[" << i+1 << "] " << accountNum << endl;
                }
                string schoice;
                getline(cin, schoice);
                int choice = stoi(schoice);
                if (choice <= CDAccounts.size()+1){
                    CDAccounts.at(choice-1).withdraw();
                    return;
                }
                else{
                    cout << "Invalid input." << endl;
                    return;
                }                
            }

            case 4:
            {
                //Exit
                running = false
            }

            default:
            {
                cout << "Invalid response, please try again." << endl;
            }
        }
    }
    return;
}