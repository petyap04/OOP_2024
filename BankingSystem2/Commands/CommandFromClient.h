#pragma once
#include "Command.h"
#include "../System.h"
#include "../Helpers/MyString.h"

class CommandFromClient : public Command
{
public:
	unsigned check_avl(const MyString& bank_name, unsigned account_number)const;
	void open(const MyString& bank_name)const;
	void close(const MyString& bank_name, unsigned account_number)const;

	virtual Command* clone() const = 0;
	virtual ~CommandFromClient() = default;
};

