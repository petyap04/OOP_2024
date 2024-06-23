#include "../h/Client.h"

Client::Client(const MyString& firstName, const MyString& secondName, unsigned IDNumber, unsigned age, const MyString& password) :
               User(firstName, secondName, IDNumber, age, password){}


void Client::messages() const
{
    for (int i = 0; i < container_messages.getSize(); i++) { 
        std::cout << i + 1 << container_messages[i].getMessage() << std::endl;
    }
}

void Client::addMessage(Message&& message)
{
    container_messages.pushBack(message);
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
