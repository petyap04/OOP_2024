#include "User.h"
#include <iostream>

User::User(const char* firstName, const char* secondName, unsigned IDNumber, unsigned age, const char* password):
    firstName(firstName),secondName(secondName), IDNumber(IDNumber), age(age),password(password){}

bool User::isThePasswordRight(const char* password) const
{
    return strcmp(password,this->password.getData()) == 0;
}

const MyString& User::getFirstName() const
{
    return firstName;
}

const MyString& User::getSecondName() const
{
    return secondName;
}

bool User::amITheUserYouAreSearchingFor(const char* firstName, const char* secondName) const
{
    return strcmp(firstName, this->firstName.getData()) == 0 && 
           strcmp(secondName, this->secondName.getData()) == 0;
}

bool User::amITheUserYouAreSearchingFor(const char* firstName, const char* secondName, const char* password) const
{
    return strcmp(firstName, this->firstName.getData()) == 0 &&
           strcmp(secondName, this->secondName.getData()) == 0 &&
           strcmp(password, this->password.getData()) == 0;
}
