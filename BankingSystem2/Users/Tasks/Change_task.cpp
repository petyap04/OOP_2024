#include "../../Tasks/h/Change_task.h"

std::ifstream& operator>>(std::ifstream& ifs, Change_task* task)
{
    operator>>(ifs, (Task*)task);
}

std::ofstream& operator<<(std::ofstream& ofs, const Change_task* task)
{
    operator<<(ofs, (const Task*)task);
}

Change_task::Change_task(Client* client, unsigned account, const MyString& oldBank, const MyString& newBank): 
             Task(client), account(account), oldBank(oldBank), newBank(newBank){}

bool Change_task::isTaskValid() const
{
    System& banking_system = System::getInstance();
    int indOfOldBank = banking_system.returnTheIndexOfTheBankWithThatName(oldBank);
    if (indOfOldBank < 0) {
        return false;
    }
    return (banking_system.getBankOnIndex(indOfOldBank).doesClientHasThisAccount(client, account));
}

void Change_task::beenValidated()
{
    this->hasBeenValidated = true;
}

void Change_task::printTask() const
{
    std::cout << client->getFirstName() << " " << client->getSecondName() << "wants to change account with number: " << account;
    std::cout << " to " << newBank;
}

void Change_task::doTask()
{
    if (hasBeenValidated) {
        System& banking_system = System::getInstance();
        unsigned money = banking_system.check_avl(oldBank, account);
        Bank& bankEmplIsWorkingIn = banking_system.getBankWhereEmployeeIsWorking(dynamic_cast<Employee*>(banking_system.getCurrentUser()));
        bankEmplIsWorkingIn.openAccount(client, account, money);
        banking_system.getBankOnIndex(banking_system.returnTheIndexOfTheBankWithThatName(oldBank)).closeAccount(client, account);
        dynamic_cast<Employee*>(banking_system.getCurrentUser())->theTaskHasBeenDone(indOfTask);
    }
}

void Change_task::dontDoTask()
{
    System& banking_system = System::getInstance();
    dynamic_cast<Employee*>(banking_system.getCurrentUser())->theTaskHasBeenDone(indOfTask);
}


Task* Change_task::clone() const
{
    return new Change_task(*this);
}
