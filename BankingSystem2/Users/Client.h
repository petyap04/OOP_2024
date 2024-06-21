#pragma once
#include "User.h"

class Client: public User
{
public:
	Client() = default;
	Client(const MyString& firstName, const MyString& secondName, unsigned IDNumber, unsigned age, const MyString& password);
	friend std::ifstream& operator>>(std::ifstream& ifs, Client* client);
	friend std::ofstream& operator<<(std::ofstream& ofs, const Client* client);

	User* clone()const;
};

