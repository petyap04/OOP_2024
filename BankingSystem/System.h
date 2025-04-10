#pragma once
#include "UsersFactory.h"
#include "UsersContainer.h"
#include "Vector.hpp"
#include "Bank.h"

class System
{
private:
	UsersContainer users_container;
	Vector<Bank> banks_container;
	User* currentUser = nullptr;
	int indexOfCurrentUser = -1;
public:
	void login(const char* firstName, const char* secondName, const char* password);
	void signup(const char* firstName, const char* secondName, const char* nameOfPossition, unsigned IDNumber, unsigned age, const char* password);
	void create_bank(const char* nameOfTheBank);
	unsigned check_avl(const char* bank_name, unsigned int account_number)const;
	int returnTheIndexOfTheBankWithThatName(const char* name)const;
	void whoami()const;
	void exit();
	friend class CommandFromClient;
};

