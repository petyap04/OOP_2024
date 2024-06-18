#pragma once
#include "User.h"
#include "MyString.h"

class Employee: public User
{
	MyString nameOfTheBank;
public:
	Employee() = default;
	Employee(const char* firstName, const char* secondName, unsigned IDNumber, unsigned age, const char* password, const char* nameOfTheBank);
	User* clone()const;
};


