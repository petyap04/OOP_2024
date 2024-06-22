#include "../h/Bank.h"

Bank::Bank(const MyString& name): name(name) {}

void Bank::setName(const MyString& name)
{
    try {
        if (name) {
            this->name = name;
        }
        throw std::exception("The name shouldn't be nullptr!");
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

bool Bank::hasSameName(const MyString& name) const
{
    return this->name == name;
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

int Bank::getIndexOfClientWithThatName(const MyString& firstName, const MyString& secondName) const
{
    unsigned size = clientsOfBank.clients.getSize();
    for (int i = 0; i < size; i++) {
        if (clientsOfBank.clients[i].getClient()->amITheUserYouAreSearchingFor(firstName, secondName)) {
            return i;
        }
    }
    return -1;
}

void Bank::listAllAccountAClientHasInTheBank(const Client& client) const
{
    int ind = getIndexOfClientWithThatName(client.getFirstName(), client.getSecondName();
    if (ind < 0) {
        return;
    }
    clientsOfBank[ind].listAllAccountAClientHasInTheBank(client);
}


