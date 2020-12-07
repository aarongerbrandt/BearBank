#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>
#include <vector>
#include <time.h> //time_t

using namespace std;

class Account{
    protected:
        bool open; //Can be changed by bank official
        string firstName, lastName, phoneNumber, address;
        double interestRate, balance;
        int accountNumber;
        //friend void SystemAdmin::modifyAccount(); //Gives modifyaccount access to elements

        struct Transaction{ //Data Structure for each time a transaction is made
            time_t time;
            double amount;
        };
        vector<Transaction> transactionHistory; //Keeps a record of transactions

    public:
        void deposit();
        void withdraw();
        
        void displayData();

        int getAccountNumber(){
            return accountNumber;
        }
        
};

#endif