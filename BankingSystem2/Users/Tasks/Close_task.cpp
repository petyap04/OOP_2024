#include "../../Tasks/h/Close_task.h"

std::ifstream& operator>>(std::ifstream& ifs, Close_task* task)
{
    operator>>(ifs, (Task*)task);
}

std::ofstream& operator<<(std::ofstream& ofs, const Close_task* task)
{
    operator<<(ofs, (Task*)task);
}