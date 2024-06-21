#include "../../Tasks/h/Open_task.h"

std::ifstream& operator>>(std::ifstream& ifs, Open_task* task)
{
    operator>>(ifs, (Task*)task);
}

std::ofstream& operator<<(std::ofstream& ofs, const Open_task* task)
{
    operator<<(ofs, (Task*)task);
}
