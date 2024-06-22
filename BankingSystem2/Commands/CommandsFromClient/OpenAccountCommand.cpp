#include "OpenAccountCommand.h"

OpenAccountCommand::OpenAccountCommand(const MyString& nameOfTheBank): nameOfTheBank(nameOfTheBank){}

void OpenAccountCommand::execute()
{
	try {
		System& banking_system = System::getInstance();
		int ind = banking_system.returnTheIndexOfTheBankWithThatName(nameOfTheBank);
		if (ind < 0) {
			throw std::exception("The bank you want to open account in does not exist");
		}
		Task* task = new Open_task(banking_system.getCurrentUser());
		banking_system.getBankOnIndex(ind).giveTaskToTheEmployeeWithTheLeastTasks(task);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

Command* OpenAccountCommand::clone() const
{
	return new OpenAccountCommand(*this);
}
