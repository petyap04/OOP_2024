#include "Bank.h"

Bank::Bank(const char* name): name(name) {}

bool Bank::isTheNameOfTheBankTheSame(const char* name) const
{
    return strcmp(this->name.getData(), name) == 0;
}

void Bank::addClient(const Client& c)
{
    clientsOfBank.addClient(c);
}

void Bank::addEmployee(const Employee& e)
{
    employeesOfBank.addEmployee(e);
}
