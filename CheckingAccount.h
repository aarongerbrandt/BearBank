#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include "Account.h"
#include <iostream>
#include <string>

using namespace std;

class CheckingAccount : public Account{
    private:
        //

    public:
        CheckingAccount(string fName, string lName, string add, string phoneNum, int accountNum, double bal){
            firstName = fName;
            lastName = lName;
            address = add;
            phoneNumber = phoneNum;
            accountNumber = accountNum;
            interestRate = 0;
            balance = bal;
            monthlyFee = 0.0;
            count++;
        }
};

/*
daily checking account with no monthly fees and no interest
*/

#endif