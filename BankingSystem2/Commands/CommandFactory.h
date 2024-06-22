#pragma once
#include "Command.h"
#include "CommandFromClient.h"
#include "LogInCommand.h"

Command CommandFactory(const MyString& command)
{
	if ("logIn" == command){
		MyString password;
		unsigned id;
		std::cin >> password >> id;
		LogInCommand logIn()
		logIn.signIn(id, password);
	}
		
	else if("signUp" == command) {

	}
}

