#pragma once
#include "Command.h"
#include "CommandFromClient.h"
#include "CommandFromClient/ChangeAccountCommand.h"
#include "CommandFromClient/CheakAvlCommand.h"
#include "CommandFromClient/CloseAccountCommand.h"
#include "CommandFromClient/ListCommand.h"
#include "CommandFromClient/MessageCommand.h"
#include "CommandFromClient/OpenAccountCommand.h"


#include "CommandFromEmployee.h"
#include "CommandsFromEmployee/TaskCommand.h"
#include "CommandsFromEmployee/ViewCommand.h"
#include "CommandsFromEmployee/ApproveCommand.h"
#include "CommandsFromEmployee/DisapproveCommand.h"
#include "CommandsFromEmployee/ValidateCommand.h"

#include "CommandFromThirdPartyEmployee.h"
#include "LogInCommand.h"

Command* commandFactory(const MyString& command)
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

Command* commandFactory(Client* client) {

}

Command* commandFactory(Employee* employee) {
	while (true) {
		MyString command;
		std::cin >> command;
		if ("task" == command) {
			return new TaskCommand();
		}
		else if ("view" == command) {
			std::cout << "Which task do you want to see:";
			unsigned ind;
			std::cin >> ind;
			return new ViewCommand(ind);
		}
		else if ("approve" == command) {
			std::cout << "Which task do you want to approve:";
			unsigned ind;
			std::cin >> ind;
			return new ApproveCommand(ind);
		}
		else if ("disapprove" == command) {
			std::cout << "Which task do you want to disapprove:";
			unsigned ind;
			std::cin >> ind;
			return new DisapproveCommand(ind);
		}
		else if ("validate" == command) {
			std::cout << "Which task do you want to validate:";
			unsigned ind;
			std::cin >> ind;
			return new ValidateCommand(ind);
		}
		else {
			std::cout << "Invalid command! Try again!";
		}
	}
}

Command* commandFactory(ThirdPartyEmployee* thirdPartyEmployee) {

}