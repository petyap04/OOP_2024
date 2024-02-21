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

Rational& sumOfRational( const Rational& r1, const Rational& r2)
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
	std::cout << r1.num << "/" << r1.dom<<std::endl;
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
//Задача 2. Да се създаде структура, която представя комплексно число. Създайте функция, които връща сбора и такава, 
//която връща произведението на 2 комплексни числа. Създайте подходяща функция за принтиране на комплексно число.
//Използвайте подходящ namespace.
//адача 3. Една група се състои от краен брой студенти, като броят на студентите се приема от конзолата. 
//Всеки студент се характеризира с оценка, факултетен номер, име и специалност {СИ, ИС, КН, ПМ, М, ИНФ}.
//Създайте структура, която описва група.Структурата също така трябва да пази средния успех на групата.
//Да се направи функция, която създава група, прочитайки информация от стандартния вход.Средния успех трябва да се сметне след въвеждане на информацията.
//Да се направи функция, която приема група и минимален успех за стипендия, и връща колко студенти ще получават стипендия.
//Да се направи функция, която приема група и минимален успех за стипендия и извежда сортирани всички студенти, които ще получават стипендия идния семестър.
//(Бонус)Да се направи функция която по дадена група и фн връща дали студентът е в групата(Възможно най - оптимално).
//tip: Сортирайте всяка група по фн.