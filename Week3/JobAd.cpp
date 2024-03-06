#include <iostream>
#include <fstream>

struct JobAd {
	long long payment;
	unsigned int empoyees;
	unsigned int holidays;
    char name[25];
};

JobAd& initialJob(JobAd& j) {
	std::cin >> j.payment >> j.empoyees >> j.holidays;
	std::cin.ignore();
	std::cin.getline(j.name, 25);
	return j;
}

void printOffer(const JobAd& j) {
	std::cout << j.payment << j.empoyees << j.holidays << j.name << std::endl;
}

void writeInTheFile(const char* file, unsigned int n) {

	std::ofstream writeInFile(file, std::ios::binary || std::ios::app);

	if (!writeInFile.is_open()) {
		return;
	}

	for (int i = 0; i < n; i++) {
		JobAd j;
		initialJob(j);
		writeInFile.write((const char*)&j, sizeof(j));
	}

	writeInFile.close();
}
void filterOffers(const char* filePath, long long minSalary) {

	std::ifstream readFromFile(filePath, std::ios::binary || std::ios::app);

	if (!readFromFile.is_open()) {
		return;
	}

	while (!readFromFile.eof()) {
		JobAd j;
		readFromFile.read((char*)&j, sizeof(j));
		if (j.payment >= minSalary) {
			printOffer(j);
		}
	}

	readFromFile.close();
}
bool existOffer(const char* filePath, const char* name) {

	std::ifstream readFromFile(filePath, std::ios::binary || std::ios::app);

	if (!readFromFile.is_open()) {
		return false;
	}

	while (!readFromFile.eof()) {
		JobAd j;
		readFromFile.read((char*)&j, sizeof(j));
		if (strcmp(j.name, name) == 0) {
			return true;
		}
	}

	readFromFile.close();
	return false;
}

void perfectOffer(const char* filePath, int maxCoworkers, int minVacancyDays, int minSalary) {
	std::ifstream readFromFile(filePath, std::ios::binary);
	std::ofstream writeInFile("result.txt", std::ios::binary);

	if (!readFromFile.is_open() && !writeInFile.is_open()) {
		return;
	}

	while (!readFromFile.eof()) {
		JobAd j;
		readFromFile.read((char*)&j, sizeof(j));
		if (j.empoyees <= maxCoworkers && j.holidays >= minVacancyDays && j.payment >= minSalary) {
			writeInFile.write((const char*)&j, sizeof(j));
		}
	}
}

void showAllOffers(const char* filePath) {

	std::ifstream readFromFile(filePath, std::ios::binary || std::ios::app);

	if (!readFromFile.is_open()) {
		return;
	}

	while (!readFromFile.eof()) {
		JobAd j;
		readFromFile.read((char*)&j, sizeof(j));
		printOffer(j);
	}
	readFromFile.close();
}

enum class Request{
	a,
	i,
	s,
	f,
	q
};

Request readRequest(char ch) {
	switch (ch) {
	case'a':return Request::a;
	case'i':return Request::i;
	case's':return Request::s;
	case'f':return Request::f;
	case'q':return Request::q;
	}
}

void completeTheRequest(const Request& r) {
	switch (r){
	case Request::a:writeInTheFile("result.txt", 1); break;
	case Request::i:showAllOffers("result.txt"); break;
	case Request::s:existOffer("result.txt", "SAP"); break;
	case Request::f:filterOffers("result.txt", 5000); break;
	case Request::q:break;
	}
}

int main()
{
	char ch;
	std::cin >> ch;
	Request r = readRequest(ch);
	completeTheRequest(r);
}
