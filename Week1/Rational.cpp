#include <iostream>
#include <assert.h>

struct Rational
{
	int num;
	int dom;
};

int gcd(int a, int b)
{
	if (a < b)
		std::swap(a, b);
	while (b != 0) {
		int temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

void rationalize(Rational& r1)
{
	int gcdOfNumAndDom = gcd(r1.num, r1.dom);
	r1.num /= gcdOfNumAndDom;
	r1.dom /= gcdOfNumAndDom;
}

bool isValid(const Rational& r1)
{
	return r1.dom != 0;
}

Rational& sumOfRational(const Rational& r1, const Rational& r2)
{
	assert(isValid(r1) && isValid(r2));
	Rational sum{ r1.num,r1.dom };
	sum.num = r1.num * r2.dom + r2.num * r1.dom;
	sum.dom *= r2.dom;
	rationalize(sum);
	return sum;
}

Rational& multiplication(const Rational& r1, const Rational& r2)
{
	assert(isValid(r1) && isValid(r2));
	Rational mul{ r1.num,r1.dom };
	mul.num *= r2.num;
	mul.dom *= r2.dom;
	rationalize(mul);
	return mul;
}

void printRationalNumber(const Rational& r1) {
	std::cout << r1.num << "/" << r1.dom << std::endl;
}

int main()
{
	Rational r1{ 1,4 };
	Rational r2{ 3,12 };
	Rational sum{ sumOfRational(r1, r2) };
	Rational mul{ multiplication(r1, r2) };
	printRationalNumber(sum);
	printRationalNumber(mul);
}
