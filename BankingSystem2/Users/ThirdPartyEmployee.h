#pragma once
#include "User.h"

class ThirdPartyEmployee : public User
{
public:
	ThirdPartyEmployee() = default;
	ThirdPartyEmployee(const char* firstName, const char* secondName, unsigned IDNumber, unsigned age, const char* password);
	friend std::ifstream& operator>>(std::ifstream& ifs, ThirdPartyEmployee* client);
	friend std::ofstream& operator<<(std::ofstream& ofs, const ThirdPartyEmployee* client);
	User* clone()const;
};

