#include <iostream>
#include <fstream>
#include "Waffle.h"
#include "Market.h"


Waffle::Waffle()=default;
Waffle::Waffle(const char* Brand, int grams, double wholesalePrice, double endCustomerPrice) {
	setBrand(Brand);
	setGrams(grams);
	setWholesalePrice(wholesalePrice);
	setEndCustomerPrice(endCustomerPrice);
}
const char* Waffle::getBrand() const{
	return Brand;
}
int Waffle::getGrams()const{
	return grams;
}
double Waffle::getWholesalePrice()const{
	return wholesalePrice;
}
double Waffle::getEndCustomerPrice()const{
	return endCustomerPrice;
}

void Waffle::setBrand(const char* Brand) {
     if (Brand && strlen(Brand) <= MAX_SIZE_OF_NAME) {
		    strcpy(this->Brand, Brand);
	 }
}
void Waffle::setGrams(int grams){
	if (grams > 0) {
		this->grams = grams;
	}
}
void Waffle::setWholesalePrice(double price){
	if (price > 0) {
		this->wholesalePrice = price;
	}
}
void Waffle::setEndCustomerPrice(double price){
	if (price > 0) {
		this->endCustomerPrice = price;
	}
}



Market::Market() = default;
Market::Market(const Waffle* arr, int countOfWaffles, double income, double expenses) {

}
int Market::getCountOfWaffles()const {

}
double Market::getIncome()const {

}
double Market::getExpenses()const {

}
void Market::setCountOfWaffles(int countOfWaffles) {
	this->countOfWaffles = countOfWaffles;
}
void Market::setIncome(double income) {
	this->income = income;
}
void Market::setExpenses(double expenses) {
	this->expenses = expenses;
}

int main() {

}
