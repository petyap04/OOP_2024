#pragma once
#include "Task.h"
#include "User.h"

class Open_task:public Task
{
public:
	Open_task() = default;
	Open_task(User* c);
};

