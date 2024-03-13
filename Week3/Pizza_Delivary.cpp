#include <iostream>
#include <fstream>
constexpr int MAX_SIZE_OF_NAME = 50;
constexpr int MAX_SIZE_OF_NUMBER = 20;
constexpr int MAX_SIZE_OF_ADRESS = 100;

enum class Type {
	Margarita,
	Neapolitan,
	Chicago,
	NewYork,
	Sicilian,
	Greek,
	California,
	Detroit,
};

enum class Size {
	S,
	M,
	L
};

struct Pizza {
	Type t;
	Size s;
	double priceOfPizza;
};

struct DelivaryPizza {
	char client[MAX_SIZE_OF_NAME];
	int number[MAX_SIZE_OF_NUMBER];
	char adress[MAX_SIZE_OF_ADRESS];
	double price;
	int count;
};

void readDelivaryInBinaryFile(const DelivaryPizza& dp, std::ifstream& ifs) {

	ifs.read((char*)&dp, sizeof(dp));

	for (int i = 0; i < dp.count; i++) {
		Pizza p;
		ifs.read((char*)&p, sizeof(p));
	}
}

void readDelivariesFromBinaryFile(DelivaryPizza* arr, size_t size, const char* file) {
	std::ifstream ifs(file, std::ios::binary);

	if (!ifs.is_open()) {
		return;
	}

	for (int i = 0; i < size; i++) {
		readDelivaryInBinaryFile(arr[i], ifs);
	}

	ifs.close();
}

void writeDelivaryInBinaryFile(const DelivaryPizza& dp, std::ofstream& ofs) {
	ofs.write((const char*)&dp, sizeof(dp));

	for (int i = 0; i < dp.count; i++) {
		Pizza p;
		ofs.write((const char*)&p, sizeof(p));
	}
}

void writeDelivariesInBinaryFile(const DelivaryPizza* arr, size_t size, const char* file) {
	std::ofstream ofs(file, std::ios::binary);

	if (!ofs.is_open()) {
		return; 
	}

	for (int i = 0; i < size; i++) {
		writeDelivaryInBinaryFile(arr[i], ofs);
	}
	ofs.close();
}

void sortArr(DelivaryPizza* arr, size_t size) {
	for (int i = 0; i < size - 1; i++) {
		int indexOfMinEl = i;
		for (int j = i + 1; j < size; j++) {
			if (strcmp(arr[indexOfMinEl].adress, arr[j].adress) < 0) {
				indexOfMinEl = j;
			}
		}
		std::swap(arr[i], arr[indexOfMinEl]);
	}
}
void sortByAdressDelivariesInNewFile(const char* file, const char* newFile, DelivaryPizza* arr, int numberOfDeliveries) {
	
	readDelivariesFromBinaryFile(arr, numberOfDeliveries, file);
	sortArr(arr, numberOfDeliveries);
	writeDelivariesInBinaryFile(arr, numberOfDeliveries, newFile);
}
int main()
{	
}
