#include "ApproveCommand.h"

ApproveCommand::ApproveCommand( unsigned ind): ind(ind){}

void ApproveCommand::execute()
{
	try {
		System& banking_system = System::getInstance();
		dynamic_cast<Employee*>(banking_system.getCurrentUser())->doTask(ind);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

Command* ApproveCommand::clone() const
{
	return new ApproveCommand(*this);
}
