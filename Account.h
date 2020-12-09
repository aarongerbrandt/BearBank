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
        double interestRate, balance, monthlyFee;
        int accountNumber;
        static int count; //holds # of accounts created

        struct Transaction{ //Data Structure for each time a transaction is made
            time_t time;
            double amount;
        };
        vector<Transaction> transactionHistory; //Keeps a record of transactions

    public:
        void deposit();
        void withdraw();
        void printTransaction(Transaction);
        
        void displayData();

        int getAccountNumber(){
            return accountNumber;
        }

        int assignAccountNumber(){
            int i = 111111111;
            return i + count;
            count++;
        }
        
};

#endif