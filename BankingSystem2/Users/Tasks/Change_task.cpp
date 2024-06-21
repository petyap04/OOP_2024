#include "../../Tasks/h/Change_task.h"

std::ifstream& operator>>(std::ifstream& ifs, Change_task* task)
{
    operator>>(ifs, (Task*)task);
}

std::ofstream& operator<<(std::ofstream& ofs, const Change_task* task)
{
    operator<<(ofs, (Task*)task);
}