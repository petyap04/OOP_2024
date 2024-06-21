#include "../h/Client.h"

Client::Client(const MyString& firstName, const MyString& secondName, unsigned IDNumber, unsigned age, const MyString& password) :
               User(firstName, secondName, IDNumber, age, password){}


User* Client::clone() const
{
    return new Client(*this);
}

std::ifstream& operator>>(std::ifstream& ifs, Client* client)
{
    operator>>(ifs, (User*)client);
}

std::ofstream& operator<<(std::ofstream& ofs, const Client* client)
{
    operator<<(ofs, (const User*)client);
}
