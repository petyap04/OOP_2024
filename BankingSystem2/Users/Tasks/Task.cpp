#include "../../Tasks/h/Task.h"


std::ifstream& operator>>(std::ifstream& ifs, Task* task)
{

}

std::ofstream& operator<<(std::ofstream& ofs, const Task* task)
{
	
}

Task::Task(Client* client):client(client) {}

Task::Task(Client* client, unsigned indOfTask):client(client), indOfTask(indOfTask){}

void Task::sendMessageToClient(Message&& m)
{
	client->addMessage(std::move(m));
}

void Task::setApproval(bool ap)
{
	isApproved = ap;
}

void Task::setInd(unsigned ind)
{
	indOfTask = ind;
}
