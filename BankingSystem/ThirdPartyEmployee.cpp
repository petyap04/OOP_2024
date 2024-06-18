#include "ThirdPartyEmployee.h"
#include "ThirdPartyEmployee.h"

ThirdPartyEmployee::ThirdPartyEmployee(const char* firstName, const char* secondName, unsigned IDNumber, unsigned age, const char* password) :
                                       User(firstName, secondName, IDNumber, age, password){}

User* ThirdPartyEmployee::clone() const
{
    return new ThirdPartyEmployee(*this);
}
