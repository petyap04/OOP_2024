#include "Client.h"

Client::Client(const char* firstName, const char* secondName, unsigned IDNumber, unsigned age, const char* password) : 
               User(firstName, secondName, IDNumber, age, password){}


User* Client::clone() const
{
    return new Client(*this);
}


