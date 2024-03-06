#include <iostream>
#include <fstream>
constexpr int SIZE = 4;

enum class Errorlist {
	the_file_is_not_open,
	empty_file,
	no_more_text_in_the_file, 
	no_error
};
struct Colour {
	unsigned int red;
	unsigned int green;
	unsigned int blue;
	Errorlist error;
};
Colour& colourNumberToStruct(Colour& c, unsigned int number) {
	c.red = number / 65536;
	number %= 65536;
	c.green = number / 256;
	c.blue = number % 256;
	return c;
}
unsigned int colourStructToNumber(const Colour& c) {
	return c.red * 65536 + c.green * 256 + c.blue;
}

Colour& readColoursFromFile(Colour& c, std::ifstream& ifs) {
	if (ifs.eof()) {
		c.error = Errorlist::no_more_text_in_the_file;
		return c;
	}
	unsigned int colour;
	ifs >> colour;
	ifs.ignore();
	colourNumberToStruct(c, colour);
	return c;
}
void fillArr(Colour* arr, const char* filename) {
	std::ifstream ifs(filename);
	if (!ifs.is_open()) {
		arr[0].error = Errorlist::the_file_is_not_open;
		return;
	}
	if (ifs.eof()) {
		arr[0].error = Errorlist::empty_file;
		return;
	}
	for (int i = 0; i < SIZE; i++) {
		Colour c;
		readColoursFromFile(c, ifs);
		if (c.error != Errorlist::no_error) {
			break;
		}
		arr[i] = c;
	}
}
void writeInTheFile(const Colour* arr, const char* filename) {
	std::ofstream ofs(filename);
	if (!ofs.is_open()) {
		return;
	}
	for (int i = 0; i < SIZE; i++) {
		if (arr[i].error != Errorlist::no_error) {
			break;
		}
		ofs << colourStructToNumber(arr[i]);
		if (i == SIZE - 1) {
			break;
		}
		ofs << "|";
	}
}
void writeInTheFileColoursWithAValueRed(const Colour* arr, const char* filename, unsigned int value) {
	std::ofstream ofs(filename);
	if (!ofs.is_open()) {
		return;
	}
	if (value >= 256) {
		return;
	}
	for (int i = 0; i < SIZE; i++) {
		if (arr[i].error != Errorlist::no_error) {
			break;
		}
		if (arr[i].red >= value) {
			ofs << colourStructToNumber(arr[i]);
		}
		if (i == SIZE - 1) {
			break;
		}
		ofs << "|";
	}
}
int main() {
	Colour arr[SIZE];
	fillArr(arr, "result.txt");
	writeInTheFile(arr, "result.txt");
	writeInTheFileColoursWithAValueRed(arr, "red.txt", 250);
}
