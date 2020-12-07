#include "SystemAdmin.h"
#include <iostream>
#include <string>

using namespace std;

    void enableBankOfficial();
    void disableBankOfficial();
    void createAccount();
    void deleteAccount();
    void modifyAccount();
    void retreivePassword();
    void changePassword();
/*
enableBankOfficial will prompt the user for the UserID of an official that is disabled to enable them
*/

/*
disableBankOfficial will prompt the user for the UserID of an official that is enabled to disable them
*/

/*
createAccount will prompt the user what kind of account they want to create, then it will proceed to ask the user for data to input into account
*/

/*
deleteAccount will prompt the user for the accountNumber of the account they want to delete, then delete it
*/

/*
modifyAccount will prompt the user for what information they would like to modify and then allow it to be changed
*/

/*
openInterface
*/

void SystemAdmin::openInterface(){
    bool running = true;
    while (running){
        cout << "[1] Create Bank Official\n
        [2] Enable Bank Official\n
        [3] Disable Bank Official\n
        [4] Create Bank Account\n
        [5] Delete Bank Account\n
        [6] Modify Bank Account\n
        [7] Retrieve Login ID\n
        [8] Logout\n";
        string soption;
        getline(cin, soption);
        int option = stoi(soption);
        switch(option){
            case 1:
            {
                //Create Bank Official
            }

            case 2:
            {
                //Enable Bank Official
            }

            case 3:
            {
                //Disable Bank Official
            }

            case 4:
            {
                //Create Bank Account
            }

            case 5:
            {
                //Delete Bank Account
            }

            case 6:
            {
                //Modify Bank Account
            }

            case 7:
            {
                //Retrieve Login ID
            }

            case 8:
            {
                //Logout
                running = false;
            }
    }
}