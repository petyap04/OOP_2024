#pragma once
#include "Employee.h"
class DataOfEmployeeOfTheBank
{
	const Employee& employee;
public:
	DataOfEmployeeOfTheBank() = default;
	DataOfEmployeeOfTheBank(const Employee& employee);
	const Employee& getEmployee()const;
};

