#include "DataOfEmployeeOfTheBank.h"

DataOfEmployeeOfTheBank::DataOfEmployeeOfTheBank(const Employee& employee):employee(employee) {}

const Employee& DataOfEmployeeOfTheBank::getEmployee() const
{
	return employee;
}
