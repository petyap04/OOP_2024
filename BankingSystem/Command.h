#pragma once
class Command
{
public:
	virtual Command* clone()const = 0;
	virtual ~Command() = default;
};

