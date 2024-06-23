#pragma once
#include "Task.h"
#include "../../h/User.h"
#include <iostream>
#include <fstream>

class Close_task:public Task
{
private:
	unsigned account;
public:
	Close_task() = default;
	Close_task(Client* client, unsigned account);
	friend std::ifstream& operator>>(std::ifstream& ifs, Close_task* task);
	friend std::ofstream& operator<<(std::ofstream& ofs, const Close_task* task);
	void printTask()const override;
	void doTask() override;
	void dontDoTask() override;

	Task* clone()const;
};

