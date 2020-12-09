#include "CD.h"
#include "Encryption.h"
#include <fstream>
#include <iostream>
#include <string>
#include <time.h>

using namespace std;

void CD::withdraw(){
    time_t currentTime = time(0);
    bool maturityFlag = false;
    double timeDifference = difftime(maturityDate, currentTime);
    if (timeDifference > 0.0){ //maturityDate has not passed
        maturityFlag = true;
        cout << "You have not yet reached your maturity date, withdrawing money will result in a penalty. Type 'withdraw' to continue. Type anything else to backout.";
        string input;
        getline(cin, input);
        if(input != "withdraw"){
            cout << "Backing out." << endl;
            return;
        }
    } 
    string samount;
    cout << "How much would you like to withdraw? ";
    double penaltyFee = 0;
    if (maturityFlag == true){
        penaltyFee = ((timeDifference/(60*60*24))*100); //$100 per day late
    }
    getline(cin, samount);
    double amount = stod(samount);
    if ((amount + penaltyFee) > balance){ // If there isn't enough money it will tell the user to add more money and then exit out of the function
        cout << "Insufficient funds. Please add money to your account and try again." << endl;
        return;
    }
    Transaction withdrawal;
    withdrawal.amount  = -amount;
    withdrawal.time = time(NULL);
    transactionHistory.push_back(withdrawal);
    balance -= amount;
    balance -= penaltyFee;
}

void CD::saveData(){
    ofstream output("output.txt");
    output << endl << encrypt("CDAccount") << endl;
    //string outputs
    output << encrypt(firstName) << endl << encrypt(lastName) << endl << encrypt(phoneNumber) << endl << encrypt(address) << endl;
    //Double outputs
    output << encryptDouble(interestRate) << endl << encryptDouble(balance) << endl << encryptDouble(monthlyFee) << endl;
    //Int outputs
    output << encryptInt(accountNumber) << endl;
    //time outputs
    output << encryptInt(openingDate) << endl << encryptInt(closingDate) << endl << encryptInt(maturityDate) << endl;
}