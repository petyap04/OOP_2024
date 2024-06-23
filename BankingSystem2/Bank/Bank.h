#pragma once
#include "DataOfClients.h"
#include "DataOfEmployees.h"
#include "Check.h"

class Bank {
private:
	MyString name;
	DataOfClients clientsOfBank;
	DataOfEmployees employeesOfBank;
	Vector<Check> checks;
public:
	Bank() = default;
	Bank(const MyString& name);
	void setName(const MyString& name);
	bool hasSameName(const MyString& name)const;
	bool hasAccountInTheBank(const Client* c)const;
	bool doesClientHasThisAccount(const Client* client, unsigned accountNumber)const;
	void addClient(const Client* c);
	void addEmployee(Employee* c);
	unsigned giveTaskToTheEmployeeWithTheLeastTasks(Task* task);
	int getIndexOfClientWithThatName(const MyString& firstName, const MyString& secondName)const;
	void listAllAccountAClientHasInTheBank(const Client* client)const;

	void addCheck(Check&& check);
	int returnIndexOfCheck(const Check& check)const;
	void theCheckHasBeenUsed(const Check& check);

	void openAccount(const Client* client);
	void openAccount(const Client* client, unsigned accountNumber, unsigned money);
	void closeAccount(const Client* client, unsigned accountNumber);

	friend class System;
	friend class CommandFromClient;
};

