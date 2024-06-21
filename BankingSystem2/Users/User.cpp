#include "../h/User.h"
#include <iostream>

User::User(const MyString& firstName, const MyString& secondName, unsigned IDNumber, unsigned age, const MyString& password):
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

bool User::amITheUserYouAreSearchingFor(const User* user) const
{
    return strcmp(user->getFirstName().getData(), this->firstName.getData()) == 0 &&
           strcmp(user->getSecondName().getData(), this->secondName.getData()) == 0;
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

std::ifstream& operator>>(std::ifstream& ifs, User* user)
{
    ifs >> user->firstName >> user->secondName >> user->IDNumber >> user->age >> user->password;
}

std::ofstream& operator<<(std::ofstream& ofs, const User* user)
{
    ofs << user->firstName << " " << user->secondName << " " << user->IDNumber << " " << user->age << " " << user->password;
}

