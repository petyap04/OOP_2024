#include "../h/Employee.h"

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

std::ifstream& operator>>(std::ifstream& ifs, Employee* employee)
{
    operator>>(ifs, (User*)employee);
    ifs >> employee->nameOfTheBank;
    ifs >> employee->tasks;
}

std::ofstream& operator<<(std::ofstream& ofs, const Employee* employee)
{
    operator<<(ofs, (const User*)employee);
    ofs << employee->nameOfTheBank;
    ofs << employee->tasks;
}
