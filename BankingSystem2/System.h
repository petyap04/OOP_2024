#pragma once
#include <iostream>
#include <fstream>
#include "Bank/h/Bank.h"
#include "Helpers/Vector.hpp"

class System
{
private:
	Vector<Polymorphic_Ptr<User>> usersContainer;
	Vector<Bank> banks_container;
	User* currentUser = nullptr;
	System() = default;
public:
	static System& getInstance(std::ifstream& ifs, Vector<Polymorphic_Ptr<User>>&& users, User*&& curr) {
		static System system;
		system.usersContainer = users;
		system.currentUser = curr;
		ifs >> system.banks_container;
		return system;
	}
	static System& getInstance() {
		static System system;
		return system;
	}
	void create_bank(const MyString& nameOfTheBank);

	unsigned check_avl(const MyString& bank_name, unsigned int account_number)const;

	int returnTheIndexOfTheBankWithThatName(const MyString& name)const;
	int returnTheIndexOfCurrentUserInABank(int indOfBank)const;
	Bank& getBankOnIndex(unsigned ind);
	User* getCurrentUser();
	Bank& getBankWhereEmployeeIsWorking(const Employee* e);

	void listAllAccountAClientHas(const Client& client)const;
	void addUser(User*&& user);


	void whoami()const;
	void exit();
};

