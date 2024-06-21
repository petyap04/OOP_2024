#pragma once
#include "DataOfClientInTheBank.h"

class DataOfClients
{
private:
	Vector<DataOfClientInTheBank> clients;
	unsigned lastAccountNumberGiven = 0;
public:
	const DataOfClientInTheBank operator[](int ind)const;
	DataOfClientInTheBank operator[](int ind);
	int indexClientWithThatName(const char* firstName, const char* secondName) const;
	void addClient(const Client& c);
	friend class Bank;
	friend class System;
};

