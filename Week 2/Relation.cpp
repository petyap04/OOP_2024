#include <iostream>
#include <fstream>
#include <assert.h>
constexpr int MAX_RELATIONS = 25;
const char* FILE_NAME = "result1.txt";

struct Pair {
	unsigned int firstNumber;
	unsigned int secondNumber;
};
struct Relation {
	int numberOfRelations;
	Pair arr[MAX_RELATIONS];
};

void addPairToRelation(Relation& r) {
	assert(r.numberOfRelations < MAX_RELATIONS - 1);
	std::ofstream outFile("result1.txt");
	if (!outFile.is_open())return;
	std::cin >> r.arr[r.numberOfRelations].firstNumber >> r.arr[r.numberOfRelations].secondNumber;
	outFile << "(" << r.arr[r.numberOfRelations].firstNumber << "," << r.arr[r.numberOfRelations].secondNumber << ")";
	r.numberOfRelations++;
	outFile.close();
}
void writeRelationToFile(Relation& r) {
	std::ofstream outFile("result1.txt");
	if (!outFile.is_open())return;
	for (int i = 0; i < r.numberOfRelations; i++) {
		std::cin >> r.arr[i].firstNumber >> r.arr[i].secondNumber;
		outFile << "(" << r.arr[i].firstNumber << "," << r.arr[i].secondNumber << ")";
	}
	outFile.close();
}
void readRelationFromFile(Relation& r) {
	std::ifstream inFile("result1.txt");
	if (!inFile.is_open())return;
	int i = 0;
	while (true) {
		inFile.get();
		inFile >> r.arr[i].firstNumber;
		inFile.get();
		inFile >> r.arr[i].secondNumber;
		inFile.get();
		if (inFile.eof()) {
			break;
		}
		i++;
		if (i >= r.numberOfRelations)break;
	}
	inFile.close();
}
int main() {
	Relation r1;
	std::cin >> r1.numberOfRelations;
	writeRelationToFile(r1);
	readRelationFromFile(r1);
	addPairToRelation(r1);
}
