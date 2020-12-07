#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <vector>
#include "Account.h"

using namespace std;

class User{
    protected:
        string username, password; //Will be stored encrypted
        string firstName, lastName;

    public:
        void printData();
        

};

#endif