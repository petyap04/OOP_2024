#pragma once
#include "User.h"

class Client: public User
{
public:
	Client() = default;
	Client(const char* firstName, const char* secondName, unsigned IDNumber, unsigned age, const char* password);
	User* clone()const;
};

