#pragma once
#include "../Helpers/MyString.h"
#include "../LogIn/h/Login.h"
#include "Command.h"
class LogInCommand:public Command
{
public:
	LogInCommand(const MyString& command);
};

