#pragma once
#include "DataOfClients.h"
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
	bool hasSameName(const char* name)const;
	void addClient(const Client& c);
	void addEmployee(Employee& c);
	void giveTaskToTheEmployeeWithTheLeastTasks(Task* task);
	int getIndexOfClientWithThatName(const char* firstName, const char* secondName)const;

	friend class System;
	friend class CommandFromClient;
};

