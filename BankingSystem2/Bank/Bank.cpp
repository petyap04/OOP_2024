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

bool Bank::hasAccountInTheBank(const Client* c) const
{
    return clientsOfBank.indexClientWithThatName(c->getFirstName(), c->getSecondName()) >= 0;
}

bool Bank::doesClientHasThisAccount(const Client* client, unsigned accountNumber) const
{
    int ind = getIndexOfClientWithThatName(client->getFirstName(), client->getSecondName());
    if (ind < 0) {
        return false;
    }
    return clientsOfBank[ind].hasAccountWithThatNumber(accountNumber);
}

void Bank::addClient(const Client* c)
{
    clientsOfBank.addClient(c);
}

void Bank::addEmployee(Employee* e)
{
    employeesOfBank.addEmployee(e);
}

unsigned Bank::giveTaskToTheEmployeeWithTheLeastTasks(Task* task)
{
    return employeesOfBank.giveTaskToTheEmployeeWithTheLeastTasks(task);
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

void Bank::listAllAccountAClientHasInTheBank(const Client* client) const
{
    int ind = getIndexOfClientWithThatName(client->getFirstName(), client->getSecondName());
    if (ind < 0) {
        return;
    }
    clientsOfBank[ind].listAllAccountAClientHasInTheBank();
}

void Bank::addCheck(Check&& check)
{
    checks.pushBack(check);
}

int Bank::returnIndexOfCheck(const Check& check) const
{
    for (int i = 0; i < checks.getSize(); i++) {
        if (checks[i] == check) {
            return i;
        }
    }
    return -1;
}

void Bank::theCheckHasBeenUsed(const Check& check)
{
    int ind = returnIndexOfCheck(check);
    for (int i = ind; i < checks.getSize(); i++) {
        checks[i] = checks[i+1];
    }
    checks.popBack();
}

void Bank::openAccount(const Client* client)
{
    clientsOfBank.openAccount(client);
}

void Bank::openAccount(const Client* client, unsigned accountNumber, unsigned money)
{
    clientsOfBank.openAccount(client, accountNumber, money);
}

void Bank::closeAccount(const Client* client, unsigned accountNumber)
{
    clientsOfBank.closeAccount(client, accountNumber);
}


