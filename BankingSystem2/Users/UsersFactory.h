#pragma once
#include <iostream>
#include "Client.h"
#include "Employee.h"
#include "ThirdPartyEmployee.h"
enum class TypeOfUsers {
	Client,
	Employee,
	ThirdPartyEmployee
};

User* createUser(unsigned int number) {
	switch (number)
	{
	case 0:return new Client();
	case 1:return new Employee();
	case 2:return new ThirdPartyEmployee();
	}
}

User* createUser(const MyString& firstName, const MyString& secondName, const MyString& nameOfPossition, unsigned IDNumber, unsigned age,
	const MyString& password) {
	if (nameOfPossition == "Client") {
		return new Client(firstName, secondName, IDNumber, age, password);
	}
	else if (nameOfPossition ==  "ThirdPartyEmployee") {
		return new ThirdPartyEmployee(firstName, secondName, IDNumber, age, password);
	}
	else {
		throw std::exception("There is no possition with that name!");
	}
}
User* createUser(const char* firstName, const char* secondName, const char* nameOfPossition, unsigned IDNumber, unsigned age,
	          const char* password, const char* nameOfTheBank) {
	if (strcmp(nameOfPossition, "Employee") == 0) {
		return new Employee(firstName, secondName, IDNumber, age, password, nameOfTheBank);
	}
	else {
		throw std::exception("There is no possition with that name!");
	}
}
