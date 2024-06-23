#pragma once
#include <iostream>
#include <fstream>
#include "../../h/Client.h"
#include "../../h/Message.h"

class Task
{
protected:
	unsigned indOfTask;
	bool isApproved = false;
	Client* client;
public:
	Task(Client* client);
	Task(Client* client, unsigned indOfTask);
	friend std::ifstream& operator>>(std::ifstream& ifs, Task* task);
	friend std::ofstream& operator<<(std::ofstream& ofs, const Task* task);
	virtual void printTask()const = 0;
	virtual void doTask() = 0;
	virtual void dontDoTask() = 0;
	void sendMessageToClient(Message&& m);
	void setApproval(bool ap);
	void setInd(unsigned ind);

	virtual Task* clone()const = 0;
	virtual ~Task() = default;
};

