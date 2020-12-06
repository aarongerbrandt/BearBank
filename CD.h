#ifndef CD_H
#define CD_H

#include <iostream>
#include <string>
#include <time.h>
#include "Account.h"

using namespace std;

class CD : public Account{
    private:
        time_t openingDate, closingDate, maturityDate;

    public:
        CD(){
            openingDate = time(NULL);
        }
};

#endif