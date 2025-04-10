#include "DataOfEmployees.h"

int DataOfEmployees::indexEmployeesWithThatName(const char* firstName, const char* secondName) const
{
    for (int i = 0; i < employees.getSize(); i++) {
        if (employees[i].getEmployee()->amITheUserYouAreSearchingFor(firstName,secondName)) {
            return i;
        }
    }
    return -1;
}

void DataOfEmployees::addEmployee(Employee& e)
{
    employees.pushBack(e);
}

void DataOfEmployees::giveTaskToTheEmployeeWithTheLeastTasks(Task* task)
{
    int countOfEmployees = employees.getSize();
    int indexOfCurrEmployeeWithTheLeastTasks = 0;
    unsigned theLeastTasks = employees[0].getEmployee()->getCountOfTasks();
    for (int i = 1; i < countOfEmployees; i++) {
        int currentTasks = employees[i].getEmployee()->getCountOfTasks();
        if (currentTasks < theLeastTasks) {
            indexOfCurrEmployeeWithTheLeastTasks = i;
            theLeastTasks = currentTasks;
        }
    }
    employees[indexOfCurrEmployeeWithTheLeastTasks].addTask(task);
}
