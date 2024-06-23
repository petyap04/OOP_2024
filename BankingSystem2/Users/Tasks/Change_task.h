#pragma once
#include "Task.h"
#include "../../h/User.h"
#include "../../../Commands/CommandsFromEmployee/ValidateCommand.h"
class Change_task: public Task
{
	unsigned account;
	MyString oldBank;
	MyString newBank;
	bool hasBeenValidated = false;
public:
	Change_task(Client* client, unsigned account, const MyString& oldBank, const MyString& newBank);
	friend std::ifstream& operator>>(std::ifstream& ifs, Change_task* task);
	friend std::ofstream& operator<<(std::ofstream& ofs, const Change_task* task);
	bool isTaskValid()const;
	void beenValidated();
	void printTask()const override;
	void doTask() override;
	void dontDoTask() override;

	Task* clone()const;
	friend class ValidateCommand;
};

