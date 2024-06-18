#include "System.h"
#include <iostream>

void System::login(const char* firstName, const char* secondName, const char* password)
{
	int index = users_container.indexOfUser(firstName, secondName, password);
	try {
		if (index < 0) {
			throw std::exception("Wrong user names or password! Try again!");

		}
		else
			indexOfCurrentUser = index;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void System::signup(const char* firstName, const char* secondName, const char* nameOfPossition, unsigned IDNumber, unsigned age, const char* password)
{
	try {
		users_container.addUser(factory(firstName, secondName, nameOfPossition, IDNumber, age, password));
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void System::create_bank(const char* nameOfTheBank)
{
	banks_container.pushBack(Bank(nameOfTheBank));
}

unsigned System::check_avl(const char* bank_name, const char* account_number) const
{
	if (indexOfCurrentUser < 0) {
		throw std::exception("You need to be loged in the system to check your account in the bank");
	}
	int indOfBank = returnTheIndexOfTheBankWithThatName(bank_name);
	if (indOfBank < 0) {
		throw std::exception("There is no bank with that name");
	}

}

int System::returnTheIndexOfTheBankWithThatName(const char* name) const
{
	for (int i = 0; i < banks_container.getSize(); i++) {
		if (banks_container[i].isTheNameOfTheBankTheSame(name)) {
			return i;
		}
	}
	return -1;
}



