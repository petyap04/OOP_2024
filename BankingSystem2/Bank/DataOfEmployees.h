#pragma once
#include "../../Helpers/MyString.h"
#include "../../Helpers/Vector.hpp"
#include "DataOfEmployeeOfTheBank.h"
#include "../../Users/h/Employee.h"

class DataOfEmployees
{
	Vector<DataOfEmployeeOfTheBank> employees;
public:
	int indexEmployeesWithThatName(const char* firstName, const char* secondName) const;
	void addEmployee(Employee& e);
	void giveTaskToTheEmployeeWithTheLeastTasks(Task* task);
	friend class Bank;
};

