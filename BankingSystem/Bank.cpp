#include "Bank.h"

Bank::Bank(const char* name): name(name) {}

void Bank::setName(const char* name)
{
    if (name) {
        this->name = name;
    }
}

bool Bank::isTheNameOfTheBankTheSame(const char* name) const
{
    return strcmp(this->name.getData(), name) == 0;
}

void Bank::addClient(const Client& c)
{
    clientsOfBank.addClient(c);
}

void Bank::addEmployee(Employee& e)
{
    employeesOfBank.addEmployee(e);
}

void Bank::giveTaskToTheEmployeeWithTheLeastTasks(Task* task)
{
    employeesOfBank.giveTaskToTheEmployeeWithTheLeastTasks(task);
}
