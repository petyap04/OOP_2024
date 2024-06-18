#pragma once
#include "User.h"
class UsersContainer
{
private:
	User** container = nullptr;
	unsigned users = 0;
	unsigned capacity = 8;

	void copyFrom(const UsersContainer& other);
	void moveFrom(UsersContainer&& other);
	void free();
	void resize(unsigned newCap);
public:
	UsersContainer();
	UsersContainer(const UsersContainer& other) = delete;
	UsersContainer& operator=(const UsersContainer& other) = delete;

	int indexOfUser(const char* firstName, const char* secondName, const char* password)const;
	void addUser(User*&& u);
	const User* getUser(unsigned ind)const;

	~UsersContainer();
};
