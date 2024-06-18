#include "DataOfEmployees.h"

int DataOfEmployees::indexEmployeesWithThatName(const char* firstName, const char* secondName) const
{
    for (int i = 0; i < employees.getSize(); i++) {
        if (employees[i].getEmployee().amITheUserYouAreSearchingFor(firstName, secondName)) {
            return i;
        }
    }
    return -1;
}

void DataOfEmployees::addEmployee(const Employee& e)
{
    employees.pushBack(e);
}
