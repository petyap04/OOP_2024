#pragma once
#include "MyString.h"
#include "DataOfClients.h"
#include "Vector.hpp"
#include "Employee.h"
#include "DataOfEmployees.h"

class Bank {
private:
	MyString name;
	DataOfClients clientsOfBank;
	DataOfEmployees employeesOfBank;
public:
	Bank(const char* name);
	bool isTheNameOfTheBankTheSame(const char* name)const;
	void addClient(const Client& c);
	void addEmployee(const Employee& c);
};

