#include <iostream>
#include <fstream>
constexpr char SEP = ',';
constexpr int NUMBER_OF_STUDENTS = 2;
constexpr int CRITERIA = 5;

enum class HairColor {
	brown,
	black,
	blond,
	red,
	white
};
struct Student {
	char firstName[16];
	char secondName[16];
	int fn[5];
	double averageGrade;
	HairColor h;
};
void printHairColor(const HairColor& h, std::ofstream& ofs) {
	switch (h) {
	case HairColor::brown:ofs << "brown"; break;
	case HairColor::black:ofs << "black"; break;
	case HairColor::blond:ofs << "blond"; break;
	case HairColor::red:ofs << "red"; break;
	case HairColor::white:ofs << "white"; break;
	}
}

Student& initializationOfStudent(Student& s) {
	std::cin.getline(s.firstName, 16, ',');
	std::cin.getline(s.secondName, 16, ',');
	for (int i = 0; i < 5; i++) {
		std::cin >> s.fn[i];
	}
	std::cin.ignore();
	std::cin >> s.averageGrade;
	std::cin.ignore();
	int hair;
	std::cin >> hair;
	s.h = (HairColor)hair;
	return s;
}

void readArr(Student* arr, size_t size) {
	for (int i = 0; i < size; i++) {
		Student s;
		arr[i] = initializationOfStudent(s);
	}
}
void writeStudentInFile(std::ofstream& ofs, const Student& st) {
	ofs << st.firstName << SEP << st.secondName << SEP;
	for (int i = 0; i < 5; i++) {
		ofs << st.fn[i];
	}
	ofs << SEP << st.averageGrade << SEP;
	printHairColor(st.h, ofs);
}
void fillFile(const char* file, const Student* studentsArr, size_t size) {
	std::ofstream ofs(file);

	if (!ofs.is_open()) {
		return;
	}

	for (int i = 0; i < size; i++) {
		writeStudentInFile(ofs, studentsArr[i]);
	}
}

int main()
{
	Student studentsArr[1024];
	readArr(studentsArr, NUMBER_OF_STUDENTS);
	fillFile("result.txt", studentsArr, NUMBER_OF_STUDENTS);
}
