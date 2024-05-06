#include <iostream>
#include "Complex.h"


Complex::Complex(double real, double im): real(real), im(im) {}

double Complex::getReal()const {
	return real;
}
double Complex::getIm()const {
	return im;
}
void Complex::setReal(double real) {
	this->real = real;
}
void Complex::setIm(double im) {
	this->im = im;
}

Complex& Complex::operator+=(const Complex& other) {
	real += other.real;
	im += other.im;
	return *this;
}
Complex& Complex::operator-=(const Complex& other) {
	real -= other.real;
	im -= other.im;
	return *this;
}
Complex& Complex::operator*=(const Complex& other) {
	double oldReal = real;
	real = real * other.real + im * other.im;
	im = im * other.real + oldReal * other.im;
	return *this;
}
Complex& Complex::operator/=(const Complex& other) {
	Complex otherCopy = other;
	Complex conjugate(other.real, -other.im);
	*this *= conjugate;
	otherCopy *= conjugate;
	if (otherCopy.real != 0) {
		real /= otherCopy.real;
		im /= otherCopy.real;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Complex& comp) {
	return os << comp.real << '+' << comp.im << 'i';
}
std::istream& operator>>(std::istream& is, Complex& comp) {
	return is >> comp;
}

Complex operator+(const Complex& lhs, const Complex& rhs) {
	Complex result(lhs);
	result += rhs;
	return result;
}
Complex operator-(const Complex& lhs, const Complex& rhs) {
	Complex result(lhs);
	result -= rhs;
	return result;
}
Complex operator*(const Complex& lhs, const Complex& rhs) {
	Complex result(lhs);
	result *= rhs;
	return result;
}
Complex operator/(const Complex& lhs, const Complex& rhs) {
	Complex result(lhs);
	result /= rhs;
	return result;
}

bool operator==(const Complex& lhs, const Complex& rhs) {
	return lhs.getReal() == rhs.getReal() && lhs.getIm() == rhs.getIm();
}
bool operator!=(const Complex& lhs, const Complex& rhs) {
	return !(lhs == rhs);
}


int main()
{
  
}


