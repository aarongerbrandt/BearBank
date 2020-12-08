#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "Account.h"
#include <iostream>
#include <string>

using namespace std;

class SavingsAccount : public Account{
    private:
        void accumulateInterest();
    
    public:
        //Constructor
        SavingsAccount(string fName, string lName, string add, string phoneNum, int accountNum, double intRate, double bal){
            firstName = fName;
            lastName = lName;
            address = add;
            phoneNumber = phoneNum;
            accountNumber = accountNum;
            interestRate = intRate;
            balance = bal;
            monthlyFee = 0.0;
            count++;
        }
};

void SavingsAccount::accumulateInterest(){
    balance = (balance + (balance * (interestRate/100))); //Initial balance + balance * intRate %
}

/*
daily savings account with no monthly fees and a variable daily interest rate set by the bank officials;
*/

#endif