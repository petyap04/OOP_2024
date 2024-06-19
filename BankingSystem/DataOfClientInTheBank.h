#pragma once
#include "MyString.h"
#include "Client.h"
#include "Polymorphic_Ptr.hpp"
#include "Vector.hpp" 

class DataOfClientInTheBank
{
private:
	struct Account {
		unsigned accountNumber = 0;
		double availableMoney = 0;
		Account() = default;
		Account(unsigned accountNumber, double availableMoney);
	};
	const Client* client;
	Vector<Account> accounts;

public:
	DataOfClientInTheBank() = default;
	DataOfClientInTheBank(const Client& client);
	int hasAccountWithThatNumber(unsigned accountNumber)const;
	unsigned openNewAccount();
	void closeAccount(unsigned accountNumber);
	const Client* getClient()const;
	friend class DataOfClients;
	friend class System;
};

