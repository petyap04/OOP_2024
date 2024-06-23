#include "TaskCommand.h"

void TaskCommand::execute()
{
	try {
		System& banking_system = System::getInstance();
		dynamic_cast<Employee*>(banking_system.getCurrentUser())->printTasks();
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

Command* TaskCommand::clone() const
{
	return new TaskCommand(*this);
}
