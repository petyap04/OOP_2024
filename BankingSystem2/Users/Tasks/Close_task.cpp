#include "../../Tasks/h/Close_task.h"

std::ifstream& operator>>(std::ifstream& ifs, Close_task* task)
{
    operator>>(ifs, (Task*)task);
}

std::ofstream& operator<<(std::ofstream& ofs, const Close_task* task)
{
    operator<<(ofs, (const Task*)task);
}

Close_task::Close_task(Client* client, unsigned account): Task(client), account(account) {}

void Close_task::printTask() const
{
    std::cout << client->getFirstName() << " " << client->getSecondName() << "wants to close account with number: " << account << std::endl;
}

void Close_task::doTask()
{
    try {
        System& banking_system = System::getInstance();
        Bank& bank = banking_system.getBankWhereEmployeeIsWorking(dynamic_cast<Employee*>(banking_system.getCurrentUser()));
        bank.closeAccount(client, account);
        isApproved = true;
        dynamic_cast<Employee*>(banking_system.getCurrentUser())->theTaskHasBeenDone(indOfTask);
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void Close_task::dontDoTask()
{
    try {
        System& banking_system = System::getInstance();
        Message m;
        m.setMessage("The command was disapproved");
        client->addMessage(std::move(m));
        dynamic_cast<Employee*>(banking_system.getCurrentUser())->theTaskHasBeenDone(indOfTask);
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

Task* Close_task::clone() const
{
    return new Close_task(*this);
}
