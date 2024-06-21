#pragma once
#include <iostream>
#include <fstream>
#include "Bank/h/Bank.h"

class System
{
private:
	Vector<Polymorphic_Ptr<User>> usersContainer;
	Vector<Bank> banks_container;
	User* currentUser = nullptr;
public:
	//как трябва да се достигне от logIn до system
	System(const char* fileName);
	void create_bank(const char* nameOfTheBank);

	unsigned check_avl(const char* bank_name, unsigned int account_number)const;
	int returnTheIndexOfTheBankWithThatName(const char* name)const;
	int returnTheIndexOfCurrentUserInABank(int indOfBank)const;
	void whoami()const;
	void exit();
	friend class CommandFromClient;
};

