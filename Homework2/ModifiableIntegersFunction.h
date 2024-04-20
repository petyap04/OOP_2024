#pragma once
#include <fstream>

static const int SIZE_OF_INT16_T = 65536;
static const int MIN_VALUE_OF_INT16_T = -32768;
static const int MAX_VALUE_OF_INT16_T = 32767;
static const int NOT_DEF_POINTS_VALUE = MAX_VALUE_OF_INT16_T + 1;
static const int EXCLUDE_POINTS_VALUE = MAX_VALUE_OF_INT16_T + 2;


class ModifiableIntegersFunction {
	int32_t arrWithValues[SIZE_OF_INT16_T];
public:
	ModifiableIntegersFunction() = default;
	ModifiableIntegersFunction(int16_t(*g)(int16_t));

	int16_t getValueOfFunc(int16_t input) const;
	void funcModif(int16_t spacificInput, int16_t spacificOutput);
	void excudePoint(int16_t input);
	double slope()const;

	ModifiableIntegersFunction& operator+=(const ModifiableIntegersFunction& other);
	ModifiableIntegersFunction& operator-=(const ModifiableIntegersFunction& other);
	friend ModifiableIntegersFunction operator+(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs);
	friend ModifiableIntegersFunction operator-(const ModifiableIntegersFunction & lhs, const ModifiableIntegersFunction & rhs) ;

	friend ModifiableIntegersFunction compositionOfFunctions(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs) ;
    friend ModifiableIntegersFunction reverseFunction(const ModifiableIntegersFunction& func);

	ModifiableIntegersFunction operator^(int times);

	friend bool* operator<(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs);
	friend bool* operator<=(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs);
	friend bool* operator>(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs);
	friend bool* operator>=(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs);
	friend bool* operator==(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs);
	friend bool* operator!=(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs);

	bool injection() const;
	bool surjection() const;
	bool bijection() const;

};
