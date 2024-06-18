#pragma once
#include "User.h"

class ThirdPartyEmployee: public User
{
public: 
	ThirdPartyEmployee() = default;
	ThirdPartyEmployee(const char* firstName, const char* secondName, unsigned IDNumber, unsigned age, const char* password);
	User* clone()const;
};

