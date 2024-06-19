#pragma once
#include "User.h"
#include "MyString.h"
#include "Task.h"
#include "Polymorphic_Ptr.hpp"
#include "Vector.hpp"

class Employee: public User
{
	MyString nameOfTheBank;
	Vector<Polymorphic_Ptr<Task>> tasks;
public:
	Employee() = default;
	Employee(const char* firstName, const char* secondName, unsigned IDNumber, unsigned age, const char* password, const char* nameOfTheBank);
	void addTask(Task* task);
	User* clone()const;
	unsigned getCountOfTasks()const;
	friend class DataOfEmployeeOfTheBank;
};


