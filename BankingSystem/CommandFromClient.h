#pragma once
#include "Command.h"
#include "System.h"
#

class CommandFromClient: public Command
{
public:
	unsigned check_avl(const char* bank_name, unsigned account_number)const;
	void open(const char* bank_name)const;
	void close(const char* bank_name, unsigned account_number)const;
	void redeem(const char* bank_name, unsigned account_number, unsigned verification_code)const;
	void change(const char* new_bank_name, const char* current_bank_name, unsigned account_number)const;
	void list(const char* bank_name)const;
	void messages()const;
	Command* clone()const;
};

