#pragma once
#include "MyString.h"
class User
{
private:
	MyString firstName;
	MyString secondName;
	MyString password;
	unsigned IDNumber = 0;
	unsigned age = 0;
public:
	User() = default;
	User(const char* firstName, const char* secondName, unsigned IDNumber, unsigned age, const char* password);
	bool isThePasswordRight(const char* password)const;
	const MyString& getFirstName()const;
	const MyString& getSecondName()const;
	bool amITheUserYouAreSearchingFor(const char* firstName, const char* secondName)const;
	bool amITheUserYouAreSearchingFor(const char* firstName, const char* secondName, const char* password)const;
	virtual User* clone()const = 0;
	virtual ~User() = default;
};