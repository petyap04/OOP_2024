#include "CommandFromClient.h"
#include "Task.h"
#include "Change_task.h"
#include "Close_task.h"
#include "Open_task.h"

unsigned CommandFromClient::check_avl(const char* bank_name, unsigned account_number) const
{
	banking_system.check_avl(bank_name, account_number);
}

void CommandFromClient::open(const char* bank_name) const
{
	/*open[bank_name] - Изпраща заявка към банката за отваряне на нова сметка.
	В заявката, която се изпраща към банката, автоматично се изпращат и неговите имена, ЕГН и възраст*/
	try {
		int indOfBank = banking_system.returnTheIndexOfTheBankWithThatName(bank_name);
		if (indOfBank < 0) {
			throw std::exception("The bank does not exists");
		}
		else {
			Open_task* task = new Open_task(banking_system.currentUser);
			banking_system.banks_container[indOfBank].giveTaskToTheEmployeeWithTheLeastTasks(task);
			delete task;
		}
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void CommandFromClient::close(const char* bank_name, unsigned account_number) const
{
	//close [bank_name] [account_number] - Изпраща заявка към банката за затваряне на сметка. При невалидни данни да се изведе подходяща грешка.
	try {
		int indOfBank = banking_system.returnTheIndexOfTheBankWithThatName(bank_name);
		if (indOfBank < 0) {
			throw std::exception("The bank does not exist");
		}
		int indOfClient = banking_system.returnTheIndexOfCurrentUserInABank(indOfBank);
		if (indOfClient < 0) {
			throw std::exception("There is no such client of the bank");
		}
		banking_system.banks_container
		else {
			Close_task* task = new Close_task(banking_system.currentUser, account_number);
			banking_system.banks_container[indOfBank].giveTaskToTheEmployeeWithTheLeastTasks(task);
			delete task;
		}
	}
	catch (std::exception& e) {

	}
}

Command* CommandFromClient::clone() const
{
	return new CommandFromClient (*this);
}
