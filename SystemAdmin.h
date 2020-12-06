#ifndef SYSTEMADMIN_H
#define SYSTEMADMIN_H

#include <iostream>
#include <string>
#include "User.h" //parent class

using namespace std;

class SystemAdmin : public User{
    private:
        //

    public:
        void enableBankOfficial();
        void disableBankOfficial();
        void createAccount();
        void deleteAccount();
        void modifyAccount();
        void retreivePassword();
        void changePassword();
};

/*
Only the system administrators can do the following – 
a) create and enable/disable bank official login profiles; 
b) create, delete, and modify CD, Checking, Savings Accounts
c) retrieve any user’s login id and change the password.
*/

#endif