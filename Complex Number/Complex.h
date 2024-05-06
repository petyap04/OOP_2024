#pragma once
class Complex
{
private:
	double real = 0;
	double im = 0;

public:
	Complex() = default;
	Complex(double real, double im);

	double getReal()const;
	double getIm()const;
	void setReal(double real);
	void setIm(double im);

	Complex& operator+=(const Complex& other);
	Complex& operator-=(const Complex& other);
	Complex& operator*=(const Complex& other);
	Complex& operator/=(const Complex& other);

	friend std::ostream& operator<<(std::ostream& os, const Complex& comp);
	friend std::istream& operator>>(std::istream& is, Complex& comp);
};

Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const Complex& rhs);
Complex operator*(const Complex& lhs, const Complex& rhs);
Complex operator/(const Complex& lhs, const Complex& rhs);

bool operator==(const Complex& lhs, const Complex& rhs);
bool operator!=(const Complex& lhs, const Complex& rhs);