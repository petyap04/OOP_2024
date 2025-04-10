#pragma once
#include "Employee.h"
#include "Vector.hpp"
#include "DataOfEmployeeOfTheBank.h"


class DataOfEmployees
{
	Vector<DataOfEmployeeOfTheBank> employees;
public:
	int indexEmployeesWithThatName(const char* firstName, const char* secondName) const;
	void addEmployee(Employee& e);
	void giveTaskToTheEmployeeWithTheLeastTasks(Task* task);
	friend class Bank;
};

