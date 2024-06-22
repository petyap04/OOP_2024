#pragma once
#include "Task.h"
#include "../../h/User.h"
class Change_task: public Task
{
	User* user;
	unsigned account;
	MyString newBank;
public:
	Change_task(User* user, unsigned account, const MyString& newBank);
	friend std::ifstream& operator>>(std::ifstream& ifs, Change_task* task);
	friend std::ofstream& operator<<(std::ofstream& ofs, const Change_task* task);

	Task* clone()const;
};

