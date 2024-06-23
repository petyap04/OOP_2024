#pragma once
#include "User.h"
#include "../Tasks/h/Task.h"
#include "../../Helpers/Polymorphic_Ptr.hpp"
#include "../../Helpers/Vector.hpp"

class Employee: public User
{
private:
	MyString nameOfTheBank;
	Vector<Polymorphic_Ptr<Task>> tasks;
public:
	Employee() = default;
	Employee(const char* firstName, const char* secondName, unsigned IDNumber, unsigned age, const char* password, const char* nameOfTheBank);
	void addTask(Task* task);
	void doTask(unsigned ind);
	void dontDoTask(unsigned ind);
	Task* getTask(unsigned ind);
	unsigned getCountOfTasks()const;
	void printTasks()const;
	void printTaskAtIndex(unsigned ind)const;
	void theTaskHasBeenDone(unsigned ind);

	friend std::ifstream& operator>>(std::ifstream& ifs, Employee* employee);
	friend std::ofstream& operator<<(std::ofstream& ofs, const Employee* employee);

	User* clone()const;
	friend class DataOfEmployeeOfTheBank;
};


