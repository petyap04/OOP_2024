#include <iostream>
#include <fstream>

void selfPrint() {
	std::ifstream ifs("Week2.cpp");
	if (!ifs.is_open())
		return;
	while (!ifs.eof()) {
		char buffer[1024];
		ifs.getline(buffer, 1024);
		std::cout << buffer << std::endl;
	}
}
int main() {
	selfPrint();
}
