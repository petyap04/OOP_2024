#pragma once
#include "../../Helpers/MyString.h"
#include <iostream>
#include <fstream>

class User
{
protected:
	MyString firstName;
	MyString secondName;
	MyString password;
	unsigned IDNumber = 0;
	unsigned age = 0;
public:
	User() = default;
	User(const MyString& firstName, const MyString& secondName, unsigned IDNumber, unsigned age, const MyString& password);
	bool isThePasswordRight(const char* password)const;
	const MyString& getFirstName()const;
	const MyString& getSecondName()const;
	bool amITheUserYouAreSearchingFor(const User* user)const;
	bool amITheUserYouAreSearchingFor(const char* firstName, const char* secondName)const;
	bool amITheUserYouAreSearchingFor(const char* firstName, const char* secondName, const char* password)const;

	friend std::ifstream& operator>>(std::ifstream& ifs, User* user);
	friend std::ofstream& operator<<(std::ofstream& ofs, const User* user);

	virtual User* clone()const = 0;
	virtual ~User() = default;
	friend class System;
};