#include "../h/Client.h"

Client::Client(const MyString& firstName, const MyString& secondName, unsigned IDNumber, unsigned age, const MyString& password) :
               User(firstName, secondName, IDNumber, age, password){}


void Client::messages() const
{
    std::ifstream ifs(messagesFile.getData());
    if (!ifs.is_open()) {
        throw std::exception("There has been problem with the opening of the file!");
    }
    unsigned int currNumber = '2';
    while (!ifs.eof()) {
        char buffer[1024];
        ifs.get(buffer, currNumber);
        std::cout << buffer << std::endl;
        currNumber += '1';
    }
}

void Client::list() const
{
    System& banking_system = System::getInstance();
    banking_system.listAllAccountAClientHas(*this);
}

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
