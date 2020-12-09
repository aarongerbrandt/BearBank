#ifndef CD_H
#define CD_H

/*
You didn't say whether or not CD accounts would have monthly fees, so I looked it up online 
and the internet said they normally don't so thats why I don't make them have any.
*/

#include <iostream>
#include <string>
#include <time.h>
#include "Account.h"
#include "Encryption.h"

using namespace std;

class CD : public Account{
    private:
        time_t openingDate, closingDate, maturityDate;

    public:
        CD(){
        }

        CD(string fName, string lName, string add, string phoneNum, double intRate, double bal, time_t opening, time_t maturity){
            firstName = fName;
            lastName = lName;
            address = add;
            phoneNumber = phoneNum;
            accountNumber = assignAccountNumber();
            interestRate = intRate;
            balance = bal;
            openingDate = opening;
            maturityDate = maturity;
            monthlyFee = 0;
        }

        void saveData();

        virtual void withdraw();
};

#endif