#include "../h/ThirdPartyEmployee.h"

ThirdPartyEmployee::ThirdPartyEmployee(const char* firstName, const char* secondName, unsigned IDNumber, unsigned age, const char* password) :
                                       User(firstName, secondName, IDNumber, age, password){}

User* ThirdPartyEmployee::clone() const
{
    return new ThirdPartyEmployee(*this);
}

std::ifstream& operator>>(std::ifstream& ifs, ThirdPartyEmployee* client)
{
    operator>>(ifs, (User*)client);
}

std::ofstream& operator<<(std::ofstream& ofs, const ThirdPartyEmployee* client)
{
    operator<<(ofs, (const User*)client);
}
