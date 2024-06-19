#pragma once
#include "Command.h"
#include "Polymorphic_Ptr.hpp"
#include "Queue.hpp"
class CommandExecutor
{
private:
	Queue<Polymorphic_Ptr<Command>> toBeExecuted;
	CommandExecutor() = default;
	~CommandExecutor() = default;
public:
	static CommandExecutor& getInstance() {
		static CommandExecutor executor;
		return executor;
	}
	void add(Command* c);
	void execute();
	CommandExecutor(const CommandExecutor&) = delete;
	CommandExecutor& operator=(const CommandExecutor&) = delete;
};

