#include "../h/Login.h"
#include <fstream>
#include <sstream>
void LoginCommand::registerUser(const MyString& firstName, const MyString& secondName, const MyString& password, unsigned id, unsigned age)
{
	// validation
	const MyString currentPossition("Client");
	currentUser = createUser(firstName, secondName, currentPossition, id, age, password);
	users.pushBack(currentUser);

	std::ofstream ofs("userDataBase.txt", std::ios::app);
	if (!ofs.is_open()) {
		std::cout << "Invalid file name" << std::endl;
		return;
	}
	ofs << currentUser << '\n';
	ofs.close();
}
void LoginCommand::login(unsigned id, const MyString& password)
{
	const char* filename = "userDataBase.txt";
	std::ifstream ifs(filename);
	if (!ifs.is_open()) {
		std::cout << "Invalid file name" << std::endl;
		return;
	}
	while (true) {
		char buffer[1024];
		ifs.getline(buffer, 1024);
		if (ifs.eof()) {
			throw std::exception();
		}
		std::stringstream strStream(buffer);
		MyString currentFirstName;
		MyString currentSecondName;
		MyString currentPassword;
		MyString nameOfPosition;
		unsigned currentId;
		unsigned age;
		// firstName secondName password egn age
		strStream >> currentFirstName >> currentSecondName >> currentPassword >> currentId >> age >> nameOfPosition;
		User* user = createUser(currentFirstName, currentSecondName, nameOfPosition, currentId, age, currentPassword);
		users.pushBack(user);
		if (currentId == id) {
			if (currentPassword == password) {
				currentUser = user;
			}
			else {
				std::cout << "Invalid Password for id " << currentId;
			}
		}
	}
	if (!currentUser) {
		throw std::exception("");
	}

}

void LoginCommand::signIn(unsigned id, const MyString& password)
{
	try {
		login(id, password);
	}
	catch (...) {
		std::cout << "User not found try using command signUp" << std::endl;
	}
}

void LoginCommand::signupUser(const MyString& firstName, const MyString& secondName, const MyString& password, unsigned id, unsigned age)
{
	try {
		login(id, password);
	}
	catch (...) {
		registerUser(firstName, secondName, password,  id, age);
	}
}

User* LoginCommand::getUser()
{
	return currentUser;
}
