#pragma once
class Command
{
	static System banking_system;
public:
	virtual Command* clone()const = 0;
	virtual ~Command() = default;
};

