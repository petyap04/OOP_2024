#include "ListCommand.h"

void ListCommand::execute()
{
	try {
		System& banking_system = System::getInstance();
		dynamic_cast<Client*>(banking_system.getCurrentUser())->list();
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

Command* ListCommand::clone() const
{
	return new ListCommand(*this);
}
