#pragma once
#include <cstring>
#define MAX_SIZE_OF_NAME 20

class Waffle
{
	char Brand[MAX_SIZE_OF_NAME + 1] = "";
	int grams = 0;
	double wholesalePrice = 0;
	double endCustomerPrice = 0;
public:
	Waffle();
	Waffle(const char* Brand, int grams, double wholesalePrice, double endCustomerPrice);
	const char* getBrand() const;
	int getGrams()const;
	double getWholesalePrice()const;
	double getEndCustomerPrice()const;
	void setBrand(const char* Brand);
	void setGrams(int grams);
	void setWholesalePrice(double price);
	void setEndCustomerPrice(double price);
};
