#pragma once
#include "MyString.h"
#include "DataOfClientInTheBank.h"
#include "Vector.hpp"
class DataOfClients
{
private:
	Vector<DataOfClientInTheBank> clients;
	unsigned lastAccountNumberGiven = 0;
public:

	int indexClientWithThatName(const char* firstName, const char* secondName) const;
	void addClient(const Client& c);

};

