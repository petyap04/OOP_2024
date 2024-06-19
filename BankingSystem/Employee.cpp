#include "Employee.h"
#include "Employee.h"

Employee::Employee(const char* firstName, const char* secondName, unsigned IDNumber, unsigned age, const char* password, const char* nameOfTheBank) :
                   User(firstName, secondName, IDNumber, age, password), nameOfTheBank(nameOfTheBank) {}

void Employee::addTask(Task* task)
{
    tasks.pushBack(task);
}

User* Employee::clone() const
{
    return new Employee(*this);
}

unsigned Employee::getCountOfTasks() const
{
    return tasks.getSize();
}
