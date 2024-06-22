#include "CommandFromClient.h"
#include "../Users/Tasks/h/Task.h"
#include "../Users/Tasks/h/Change_task.h"
#include "../Users/Tasks/h/Close_task.h"
#include "../Users/Tasks/h/Open_task.h"
#include "../System.h"

unsigned CommandFromClient::check_avl(const MyString& bank_name, unsigned account_number) const
{
	System& banking_system = System::getInstance();
	banking_system.check_avl(bank_name, account_number);
}

void CommandFromClient::open(const MyString& bank_name) const
{
	/*open[bank_name] - Изпраща заявка към банката за отваряне на нова сметка.
	В заявката, която се изпраща към банката, автоматично се изпращат и неговите имена, ЕГН и възраст*/
	System& banking_system = System::getInstance();
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

void CommandFromClient::close(const MyString& bank_name, unsigned account_number) const
{
	//close [bank_name] [account_number] - Изпраща заявка към банката за затваряне на сметка. При невалидни данни да се изведе подходяща грешка.
	System& banking_system = System::getInstance();
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

