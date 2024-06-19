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
			banking_system.banks_container[indOfBank].giveTaskToTheEmployeeWithTheLeastTasks(new Open_task(banking_system.currentUser));
			//tryabva da vidya kak da ne e problem tova new
		}
	}
}

Command* CommandFromClient::clone() const
{
	return new CommandFromClient (*this);
}
