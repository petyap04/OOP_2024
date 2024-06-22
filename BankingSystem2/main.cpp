#include <iostream>
#include "System.h"
#include "Login/h/Login.h"
#include "Helpers/MyString.h"

int main()
{
    LoginCommand logIn;
    
    MyString command;
    std::cin >> command;
    System bankingSystem = System::getInstance();
    if ("logIn" == command) {
        MyString password;
        unsigned id;
        std::cin >> password >> id;
        logIn.signIn(id, password);
    }
    else if ("signUp" == command) {
        MyString fisrtName, secondName, password, possition;
        unsigned id, age;
        std::cin >> fisrtName >> secondName >> password >> possition >> id >> age;
        logIn.signupUser(fisrtName, secondName, password, possition, id, age);
    }

    else if ("createABank" == command) {
        MyString nameOfBank;
        std::cin >> nameOfBank;
        bankingSystem.create_bank(nameOfBank);
    }
    

}
