#include "System.h"
#include <iostream>

void System::login(const char* firstName, const char* secondName, const char* password)
{
	int index = users_container.indexOfUser(firstName, secondName, password);
	try {
		if (index < 0) {
			throw std::exception("Wrong user names or password! Try again!");

		}
		else {
			indexOfCurrentUser = index;
			currentUser = users_container[index];
		}
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
	try {
		banks_container.pushBack(Bank(nameOfTheBank));
	}
	catch (...) {
		std::cout << "There has been a mistake! Try again!" << std::endl;
	}
}

unsigned System::check_avl(const char* bank_name, unsigned int account_number) const
{
	try {
		if (indexOfCurrentUser < 0) {
			throw std::exception("You need to be loged in the system to check your account in the bank");
		}
		int indOfBank = returnTheIndexOfTheBankWithThatName(bank_name);
		if (indOfBank < 0) {
			throw std::exception("There is no bank with that name");
		}
		int indOfClient = banks_container[indOfBank].clientsOfBank.indexClientWithThatName(currentUser->getFirstName().getData(), currentUser->getSecondName().getData());
		if (indOfClient < 0) {
			throw std::exception("There is no user with that name in the bank");
		}
		int indOfAccount = banks_container[indOfBank].clientsOfBank[indOfClient].hasAccountWithThatNumber(account_number);
		if (indOfAccount < 0) {
			throw std::exception("The user does not have account with that number");
		}
		else {
			return banks_container[indOfBank].clientsOfBank[indOfClient].accounts[indOfAccount].availableMoney;
		}
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
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

void System::whoami() const
{
	try {
		if (indexOfCurrentUser < 0) {
			throw std::exception("You need to be loged in the system to check your info");
		}
		else {
			std::cout << "First name: " << currentUser->getFirstName() << std::endl;
			std::cout << "Second name: " << currentUser->getSecondName() << std::endl;
			std::cout << "ID number: " << currentUser->IDNumber << std::endl;
			std::cout << "Age: " << currentUser->age << std::endl;
		}
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void System::exit()
{
	try {
		if (indexOfCurrentUser < 0) {
			throw std::exception("You need to be loged in the system to exit");
		}
		else {
			currentUser = nullptr;
			indexOfCurrentUser = -1;
		}
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}



