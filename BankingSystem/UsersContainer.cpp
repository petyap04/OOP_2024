#include "UsersContainer.h"
#include <iostream>

void UsersContainer::copyFrom(const UsersContainer& other)
{
	users = other.users;
	capacity = other.capacity;
	container = new User * [capacity];
	for (int i = 0; i < users; i++) {
		container[i] = other.container[i]->clone();
	}
}

void UsersContainer::moveFrom(UsersContainer&& other)
{
	users = other.users;
	capacity = other.capacity;
	container = other.container;

	other.container = nullptr;
	other.users = other.capacity = 0;
}

void UsersContainer::free()
{
	for (int i = 0; i < users; i++) {
		delete container[i];
	}
	delete[]container;
	container = nullptr;
	users = capacity = 0;
}

void UsersContainer::resize(unsigned newCap)
{
	User** newContainer = new User * [newCap];
	for (int i = 0; i < users; i++) {
		newContainer[i] = container[i];
	}
	delete[]container;
	container = newContainer;
	capacity = newCap;
}

UsersContainer::UsersContainer()
{
	container = new User * [capacity];
}

User* UsersContainer::operator[](unsigned index)
{
	return container[index];
}

const User* UsersContainer::operator[](unsigned index) const
{
	return container[index];
}

int UsersContainer::indexOfUser(const char* firstName, const char* secondName, const char* password) const
{
	for (int i = 0; i < users; i++) {
		if (strcmp(container[i]->getFirstName().getData(), firstName) == 0 && 
			strcmp(container[i]->getSecondName().getData(), secondName) == 0 && 
			container[i]->isThePasswordRight(password)) {
			return i;
		}
	}
	return -1;
}

void UsersContainer::addUser(User*&& u)
{
	if (users == capacity) {
		resize(capacity * 2);
	}
	container[users++] = u;
}

const User* UsersContainer::getUser(unsigned ind) const
{
	if (ind < users) {
		return container[ind];
	}
	throw std::out_of_range("There is no element at that index");
}

UsersContainer::~UsersContainer()
{
	free();
}
