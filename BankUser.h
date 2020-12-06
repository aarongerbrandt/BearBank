#ifndef BANKUSER_H
#define BANKUSER_H

#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include "CD.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include "User.h" //parent class

using namespace std;

class BankUser : public User{
    private:
        time_t previousLogin;
        vector<CD> CDAccounts;
        vector<CheckingAccount> CheckingAccounts;
        vector<SavingsAccount> SavingsAccounts;
    
    public:
        void openInterface();
        void changePassword();
        void displayAccounts();
        void checkTransactions();
};

/*
A valid Bear bank customer – 
a) can have more than one account;                                                    - vectors for each account type and also displayAccounts
b) change their login password;                                                       - changePassword
c) must log in with their user id and password to see the account(s) information,     - postLogin allows them to see info
d) will see the last login date and time after every successful login,                - also postLogin
e) can check all transactions made with their account within a day/date range.        - checkTransactions
*/

#endif