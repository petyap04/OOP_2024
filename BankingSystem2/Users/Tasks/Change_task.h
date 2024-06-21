#pragma once
#include "Task.h"
#include "../../h/User.h"
class Change_task: public Task
{
public:
	ChangeTask(User* user, unsigned account, Bank& newBank);
	friend std::ifstream& operator>>(std::ifstream& ifs, Change_task* task);
	friend std::ofstream& operator<<(std::ofstream& ofs, const Change_task* task);
};

