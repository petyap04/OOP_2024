#pragma once
#include <iostream>
#include "Client.h"
#include "Employee.h"
#include "ThirdPartyEmployee.h"


User* factory(const char* firstName, const char* secondName, const char* nameOfPossition, unsigned IDNumber, unsigned age, 
	          const char* password) {
	if (strcmp(nameOfPossition, "Client") == 0) {
		return new Client(firstName, secondName, IDNumber, age, password);
	}
	else if (strcmp(nameOfPossition, "ThirdPartyEmployee") == 0) {
		return new ThirdPartyEmployee(firstName, secondName, IDNumber, age, password);
	}
	else {
		throw std::exception("There is no possition with that name!");
	}
}
User* factory(const char* firstName, const char* secondName, const char* nameOfPossition, unsigned IDNumber, unsigned age, 
	          const char* password, const char* nameOfTheBank) {
	if (strcmp(nameOfPossition, "Employee") == 0) {
		return new Employee(firstName, secondName, IDNumber, age, password, nameOfTheBank);
	}
	else {
		throw std::exception("There is no possition with that name!");
	}
}
