#pragma once
#include "Task.h"
#include "../../h/User.h"
#include <iostream>
#include <fstream>

class Close_task:public Task
{
public:
	Close_task() = default;
	Close_task(User* client, unsigned account);
	friend std::ifstream& operator>>(std::ifstream& ifs, Close_task* task);
	friend std::ofstream& operator<<(std::ofstream& ofs, const Close_task* task);
};

