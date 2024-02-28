#include <iostream>
#include <fstream>
const char* fileName = "result.txt";

void sumAndMultOfNumbersInFile() {
	std::ofstream outFile("result.txt");
	if (!outFile.is_open())return;
	int a, b, c;
	std::cin >> a >> b >> c;
	int sum = a + b + c;
	int mult = a * b * c;
	outFile << sum << " " << mult;
	outFile.close();
}
void printSub() {
	std::ifstream inFile("result.txt");
	if (!inFile.is_open())return;
	int sum, mult;
	inFile >> sum >> mult;
	std::cout << sum - mult;
	inFile.close();
}
int main()
{
	sumAndMultOfNumbersInFile();
	printSub();
}

