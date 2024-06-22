#include "../../Tasks/h/Close_task.h"

std::ifstream& operator>>(std::ifstream& ifs, Close_task* task)
{
    operator>>(ifs, (Task*)task);
}

std::ofstream& operator<<(std::ofstream& ofs, const Close_task* task)
{
    operator<<(ofs, (Task*)task);
}

Close_task::Close_task(User* client, unsigned account): client(client), account(account) {}

Task* Close_task::clone() const
{
    return new Close_task(*this);
}
