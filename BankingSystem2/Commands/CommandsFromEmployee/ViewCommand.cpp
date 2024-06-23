#include "ViewCommand.h"

ViewCommand::ViewCommand(unsigned taskID): taskID(taskID) {}

void ViewCommand::execute()
{
	try {
		System& banking_system = System::getInstance();
		dynamic_cast<Employee*>(banking_system.getCurrentUser())->printTaskAtIndex(taskID);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

Command* ViewCommand::clone() const
{
	return new ViewCommand(*this);
}
