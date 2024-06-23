#include "System.h"
#include <iostream>

void System::create_bank(const MyString& nameOfTheBank)
{
	try {
		banks_container.pushBack(Bank(nameOfTheBank));
	}
	catch (...) {
		std::cout << "There has been a mistake! Try again!" << std::endl;
	}
}

unsigned System::check_avl(const MyString& bank_name, unsigned int account_number) const
{
	try {
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

int System::returnTheIndexOfTheBankWithThatName(const MyString& name) const
{
	for (int i = 0; i < banks_container.getSize(); i++) {
		if (banks_container[i].hasSameName(name)) {
			return i;
		}
	}
	return -1;
}

int System::returnTheIndexOfCurrentUserInABank(int indOfBank) const
{
	for (int i = 0; i < usersContainer.getSize(); i++) {
		if (usersContainer[i]->amITheUserYouAreSearchingFor(currentUser)) {
			return i;
		}
	}
	return -1;
}

Bank& System::getBankOnIndex(unsigned ind)
{
	return banks_container[ind];
}

User* System::getCurrentUser()
{
	return currentUser;
}

Bank& System::getBankWhereEmployeeIsWorking(const Employee* e) 
{
	for (int i = 0; i < banks_container.getSize(); i++) {
		int ind = banks_container[i].employeesOfBank.indexEmployeesWithThatName(e->getFirstName(), e->getSecondName());
		if (ind > 0) {
			return banks_container[i];
		}
	}
	throw std::exception("There is no employee with that name");
}

void System::listAllAccountAClientHas(const Client& client) const
{
	for (int i = 0; i < banks_container.getSize(); i++) {
		banks_container[i].listAllAccountAClientHasInTheBank(client);
	}
}

void System::addUser(User*&& user)
{
	usersContainer.pushBack(user);
}

void System::whoami() const
{
	///opravi
	try {
		if (currentUser) {
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
		if (currentUser) {
			throw std::exception("You need to be loged in the system to exit");
		}
		else {
			currentUser = nullptr;
			std::ofstream ofs("userDataBase.txt");
			if (!ofs.is_open()) {
				throw std::exception("Problem with openning of the file!");
			}
			operator<<(ofs, usersContainer);
			operator<<(ofs, banks_container);
			ofs.close();
		}
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}



