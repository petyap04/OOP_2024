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
	void redeem(const MyString& bank_name, unsigned account_number, unsigned verification_code)const;
	void change(const MyString& new_bank_name, const MyString& current_bank_name, unsigned account_number)const;
	void list(const MyString& bank_name)const;
	void messages()const;
	virtual Command* clone() const = 0;
	virtual ~CommandFromClient() = default;
};

