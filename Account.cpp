#include "Account.h"
#include <iostream>
#include <string>
#include <time.h>

using namespace std;

/*
deposit asks the user how much they want to deposit. It will then make 
*/

void Account::deposit(){
    double amount;
    cout << "How much would you like to deposit? ";
    getline(cin, amount);
    Transaction deposit = new Transaction;
    deposit.amount = amount;
    deposit.time = time(NULL);
    transactionHistory.push_back(deposit); //Add it to the history of transactions
    balance += amount;
}

/*
Withdraw asks the user how much they want to withdraw. It then checks if the account has enough money to withdraw. If it does then it makes a note and adds
it to the transactionHistory
*/

void Account::withdraw(){
    double amount;
    cout << "How much would you like to withdraw? ";
    getline(cin, amount);
    if (amount > balance){ // If there isn't enough money it will tell the user to add more money and then exit out of the function
        cout << "Insufficient funds. Please add money to your account and try again." << endl;
        return;
    }
    Transaction withdrawal = new Transaction;
    withdrawal.amount  = -amount;
    withdrawal.time = time(NULL);
    transactionHistory.push_back(withdrawal);
    balance -= amount;
}