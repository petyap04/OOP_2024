#include "../../Tasks/h/Change_task.h"

std::ifstream& operator>>(std::ifstream& ifs, Change_task* task)
{
    operator>>(ifs, (Task*)task);
}

std::ofstream& operator<<(std::ofstream& ofs, const Change_task* task)
{
    operator<<(ofs, (Task*)task);
}

Change_task::Change_task(User* user, unsigned account, const MyString& newBank): user(user), account(account), newBank(newBank){}

Task* Change_task::clone() const
{
    return new Change_task(*this);
}
