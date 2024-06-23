#pragma once
#include "User.h"
#include "../../Helpers/MyString.h"
#include "../../System.h"
#include "Message.h"
#include <fstream>

class Client: public User
{
private:
	Vector<Message> container_messages;
public:
	Client() = default;
	Client(const MyString& firstName, const MyString& secondName, unsigned IDNumber, unsigned age, const MyString& password);
	friend std::ifstream& operator>>(std::ifstream& ifs, Client* client);
	friend std::ofstream& operator<<(std::ofstream& ofs, const Client* client);
	void messages()const;
	void addMessage(Message&& message);
	void list()const;
	User* clone()const;
};

