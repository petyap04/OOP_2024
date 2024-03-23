#pragma once
#include "Waffle.h"
#define MAX_SIZE_OF_WAFFLES 30

class Market
{
	Waffle arr[MAX_SIZE_OF_WAFFLES];
	int countOfWaffles = 0;
	double income = 0;
	double expenses = 0;
public:
	Market();
	Market(const Waffle* arr, int countOfWaffles, double income, double expenses);
	int getCountOfWaffles()const;
	double getIncome()const;
	double getExpenses()const;
	void setCountOfWaffles(int countOfWaffles);
	void setIncome(double income);
	void setExpenses(double expenses);
	void setWaffleArr(const Waffle& arr, int countOfWaffles);
};
