#pragma once
#include <iostream>
#include "../../Helpers/MyString.h"
class Check
{
private:
	MyString code;
	double money = 0;
	bool isValid(const MyString& code);
public:
	Check(const MyString& code, double money);
	const MyString& getCode()const;
	double getMoney()const;
};

bool operator==(const Check& lhs, const Check& rhs);
bool operator!=(const Check& lhs, const Check& rhs);