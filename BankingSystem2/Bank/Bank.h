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
	Bank(const MyString& name);
	void setName(const MyString& name);
	bool hasSameName(const MyString& name)const;
	void addClient(const Client& c);
	void addEmployee(Employee& c);
	void giveTaskToTheEmployeeWithTheLeastTasks(Task* task);
	int getIndexOfClientWithThatName(const MyString& firstName, const MyString& secondName)const;
	void listAllAccountAClientHasInTheBank(const Client& client)const;


	friend class System;
	friend class CommandFromClient;
};

