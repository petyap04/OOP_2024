#pragma once
#include "../CommandFromThirdPartyEmployee.h"
class SendCheckCommand: public CommandFromThirdPartyEmployee
{
	double sum = 0;
	MyString code;
	unsigned Id;
public:
	SendCheckCommand(double sum, const MyString code, unsigned Id);
	void execute()override;
	virtual Command* clone() const;
};

