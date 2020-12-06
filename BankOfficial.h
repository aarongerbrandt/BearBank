#ifndef BANKOFFICIAL_H
#define BANKOFFICIAL_H

#include <iostream>
#include <string>
#include <time.h>
#include "User.h" //parent class

using namespace std;

class BankOfficial : public User{
    private:
        bool active;
        struct closingLog{ //Holds information from everytime an account is closed
            //Closing official
            string closingOfficialName = "", closingOfficialID = "";
            //Closed account owner info
            string closedAccountNumber = "", closedOwnerName = "", closedPhoneNumber = "", closedAddress = "";
            //Closed account info
            double closedIntRate = 0, closedBal = 0;

            string reasoning = "";

            //Account time open/close
            time_t closingTime;
            time_t openedTime;
        };
        vector<closingLog>closedAccounts;

    public:
        void openInterface();
        void openAccount();
        void closeAccount();
        void printClosingLog();
        void accessAccount();
        void searchAccounts();
    
};

/*
Only the bank officials can – 
a) open or close an account;                                                                                                - closeAccount, openAccount

b) any closed account information must be saved with abilities for information retrieval (account number, account holder    - ClosingLog, printClosingLog
information, opening and close date, name and id of the bank official involved) by the bank officials;

c) deposit or withdraw money from an account with the customer’s permission, i.e. the customer                              - accessAccount
must also enter the login password to authorize any transaction; 

d) search account(s) by account number, customer name or phone number.                                                      - searchAccount
*/

#endif