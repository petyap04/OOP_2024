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
	Bank() = default;
	Bank(const char* name);
	void setName(const char* name);
	bool isTheNameOfTheBankTheSame(const char* name)const;
	void addClient(const Client& c);
	void addEmployee(Employee& c);
	void giveTaskToTheEmployeeWithTheLeastTasks(Task* task);
	friend class System;
};

