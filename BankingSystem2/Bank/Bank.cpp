#include "../h/Bank.h"

Bank::Bank(const char* name): name(name) {}

void Bank::setName(const char* name)
{
    if (name) {
        this->name = name;
    }
}

bool Bank::hasSameName(const char* name) const
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

int Bank::getIndexOfClientWithThatName(const char* firstName, const char* secondName) const
{
    unsigned size = clientsOfBank.clients.getSize();
    for (int i = 0; i < size; i++) {
        if (clientsOfBank.clients[i].getClient()->amITheUserYouAreSearchingFor(firstName, secondName)) {
            return i;
        }
    }
    return -1;
}
