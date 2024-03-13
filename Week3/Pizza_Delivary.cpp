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

struct DeliveryPizza {
	char client[MAX_SIZE_OF_NAME];
	int number[MAX_SIZE_OF_NUMBER];
	char adress[MAX_SIZE_OF_ADRESS];
	double price;
	int count;
};

void readDeliveryInBinaryFile(DeliveryPizza& dp, std::ifstream& ifs) {

	ifs.read((char*)&dp, sizeof(dp));

	for (int i = 0; i < dp.count; i++) {
		Pizza p;
		ifs.read((char*)&p, sizeof(p));
	}
}

void readDeliveriesFromBinaryFile(DeliveryPizza* arr, size_t size, const char* file) {
	std::ifstream ifs(file, std::ios::binary);

	if (!ifs.is_open()) {
		return;
	}

	for (int i = 0; i < size; i++) {
		readDeliveryInBinaryFile(arr[i], ifs);
	}

	ifs.close();
}

void writeDeliveryInBinaryFile(const DeliveryPizza& dp, std::ofstream& ofs) {
	ofs.write((const char*)&dp, sizeof(dp));

	for (int i = 0; i < dp.count; i++) {
		Pizza p;
		ofs.write((const char*)&p, sizeof(p));
	}
}

void writeDeliveriesInBinaryFile(const DeliveryPizza* arr, size_t size, const char* file) {
	std::ofstream ofs(file, std::ios::binary);

	if (!ofs.is_open()) {
		return; 
	}

	for (int i = 0; i < size; i++) {
		writeDeliveryInBinaryFile(arr[i], ofs);
	}
	ofs.close();
}

void sortArr(DeliveryPizza* arr, size_t size) {
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
void sortByAdressDeliveriesInNewFile(const char* file, const char* newFile, DeliveryPizza* arr, int numberOfDeliveries) {
	
	readDeliveriesFromBinaryFile(arr, numberOfDeliveries, file);
	sortArr(arr, numberOfDeliveries);
	writeDeliveriesInBinaryFile(arr, numberOfDeliveries, newFile);
}
int main()
{	
}
