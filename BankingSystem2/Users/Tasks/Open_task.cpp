#include "../../Tasks/h/Open_task.h"

Open_task::Open_task(Client* client):Task(client){}

std::ifstream& operator>>(std::ifstream& ifs, Open_task* task)
{
    operator>>(ifs, (Task*)task);
}

std::ofstream& operator<<(std::ofstream& ofs, const Open_task* task)
{
    operator<<(ofs, (const Task*)task);
}

void Open_task::printTask() const
{
    std::cout << client->getFirstName() << " " << client->getSecondName() << "wants to open account" << std::endl;
}

void Open_task::doTask()
{
    try {
        System& banking_system = System::getInstance();
        Bank& bank = banking_system.getBankWhereEmployeeIsWorking(dynamic_cast<Employee*>(banking_system.getCurrentUser()));
        bank.openAccount(dynamic_cast<Client*>(client));
        isApproved = true;
        dynamic_cast<Employee*>(banking_system.getCurrentUser())->theTaskHasBeenDone(indOfTask);
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void Open_task::dontDoTask() 
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

Task* Open_task::clone() const
{
    return new Open_task(*this);
}
