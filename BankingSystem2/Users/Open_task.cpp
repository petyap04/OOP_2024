#include "../../Tasks/h/Open_task.h"

Open_task::Open_task(User* client):client(client){}

std::ifstream& operator>>(std::ifstream& ifs, Open_task* task)
{
    operator>>(ifs, (Task*)task);
}

std::ofstream& operator<<(std::ofstream& ofs, const Open_task* task)
{
    operator<<(ofs, (Task*)task);
}

Task* Open_task::clone() const
{
    return new Open_task(*this);
}
