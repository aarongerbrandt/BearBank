#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include "Account.h"
#include "Encryption.h"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class CheckingAccount : public Account{
    public:
        void saveData();

        CheckingAccount(string fName, string lName, string add, string phoneNum, double bal){
            firstName = fName;
            lastName = lName;
            address = add;
            phoneNumber = phoneNum;
            accountNumber = assignAccountNumber();
            interestRate = 0;
            balance = bal;
            monthlyFee = 0.0;
        }
};

void CheckingAccount::saveData(){
    ofstream output("output.txt");
    output << endl << encrypt("CheckingAccount") << endl;
    //string outputs
    output << encrypt(firstName) << endl << encrypt(lastName) << endl << encrypt(phoneNumber) << endl << encrypt(address) << endl;
    //Double outputs
    output << encryptDouble(interestRate) << endl << encryptDouble(balance) << endl << encryptDouble(monthlyFee) << endl;
    //Int outputs
    output << encryptInt(accountNumber) << endl;
}

/*
daily checking account with no monthly fees and no interest
*/

#endif