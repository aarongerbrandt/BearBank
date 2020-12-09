#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "Account.h"
#include "Encryption.h"

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class SavingsAccount : public Account{
    private:
        void accumulateInterest();
    
    public:
        //Constructor
        SavingsAccount(string fName, string lName, string add, string phoneNum, double intRate, double bal){
            firstName = fName;
            lastName = lName;
            address = add;
            phoneNumber = phoneNum;
            accountNumber = assignAccountNumber();
            interestRate = intRate;
            balance = bal;
            monthlyFee = 0.0;
        }

        void saveData();
};

void SavingsAccount::accumulateInterest(){
    balance = (balance + (balance * (interestRate/100))); //Initial balance + balance * intRate %
}

void SavingsAccount::saveData(){
    ofstream output("output.txt");
    output << endl << encrypt("SavingsAccount") << endl;
    //string outputs
    output << encrypt(firstName) << endl << encrypt(lastName) << endl << encrypt(phoneNumber) << endl << encrypt(address) << endl;
    //Double outputs
    output << encryptDouble(interestRate) << endl << encryptDouble(balance) << endl << encryptDouble(monthlyFee) << endl;
    //Int outputs
    output << encryptInt(accountNumber) << endl;
}

/*
daily savings account with no monthly fees and a variable daily interest rate set by the bank officials;
*/

#endif