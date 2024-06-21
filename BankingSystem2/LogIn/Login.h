#pragma once
#include "../../Helpers/MyString.h"
#include "../../Users/h/User.h"
#include "../../Users/h/UsersFactory.h"
class LoginCommand {
private:
	User* currentUser = nullptr;
	Vector<Polymorphic_Ptr<User>> users;
	void registerUser(const MyString& fisrtName, const MyString& secondName, const MyString& password, unsigned id, unsigned age);
	void login(unsigned id, const MyString& password);
public:
	void signIn(unsigned id, const MyString& password);
	void signupUser(const MyString& firstName, const MyString& secondName, const MyString& password, unsigned id, unsigned age);
	User* getUser();
};