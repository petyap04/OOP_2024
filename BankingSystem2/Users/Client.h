#pragma once
#include "User.h"
#include "../../Helpers/MyString.h"
#include "../../System.h"
#include <fstream>

class Client: public User
{
private:
	MyString messagesFile = "fileWithMessages";
public:
	Client() = default;
	Client(const MyString& firstName, const MyString& secondName, unsigned IDNumber, unsigned age, const MyString& password);
	friend std::ifstream& operator>>(std::ifstream& ifs, Client* client);
	friend std::ofstream& operator<<(std::ofstream& ofs, const Client* client);
	void messages()const;
	void list()const;
	User* clone()const;
};

