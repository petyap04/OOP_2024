#pragma once
#include "System.h"
class Command
{
protected:
	static System banking_system;
public:
	virtual Command* clone()const = 0;
	virtual ~Command() = default;
};

