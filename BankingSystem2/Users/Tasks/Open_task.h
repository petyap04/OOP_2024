#pragma once
#include "Task.h"
#include "../../h/User.h"
#include <iostream>
#include <fstream>

class Open_task:public Task
{
public:
	Open_task() = default;
	Open_task(User* client);
	friend std::ifstream& operator>>(std::ifstream& ifs, Open_task* task);
	friend std::ofstream& operator<<(std::ofstream& ofs, const Open_task* task);
};

