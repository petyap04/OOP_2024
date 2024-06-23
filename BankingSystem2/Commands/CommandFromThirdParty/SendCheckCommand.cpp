#include "SendCheckCommand.h"

SendCheckCommand::SendCheckCommand(double sum, const MyString code, unsigned Id):sum(sum), code(code), Id(Id){}

Command* SendCheckCommand::clone() const
{
	return new SendCheckCommand(*this);
}
