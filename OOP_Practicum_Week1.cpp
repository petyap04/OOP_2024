#include <iostream>
//int** createMatrix(size_t rows, size_t colls) 
//{
//	int** mtx = new int* [rows];
//	for (size_t i = 0; i < rows; i++) 
//	{
//		mtx[i] = new int[colls];
//	}
//	return mtx;
//}
//struct Matrix
//{
//	size_t rows;
//	size_t colls;
//	int** mtx = createMatrix(rows, colls);
//};
//void readMatrix(Matrix& mtx)
//{
//	for (size_t i = 0; i < mtx.rows; i++) 
//	{
//		for (size_t j = 0; j < mtx.colls; i++) 
//		{
//			std::cin >> mtx.mtx[i][j];
//		}
//	}
//}
//Matrix& transp(Matrix& trans, const Matrix& mtx) 
//{
//	trans.rows = mtx.colls;
//	trans.colls = mtx.rows;
//	for (size_t i = 0; i < trans.rows; i++) 
//	{
//		for (size_t j = 0; j < trans.colls; i++) 
//		{
//			trans.mtx[i][j]=mtx.mtx[j][i];
//		}
//	}
//}
//void printMatrix(const Matrix& mtx)
//{
//	for (size_t i = 0; i < mtx.rows; i++) 
//	{
//		for (size_t j = 0; j < mtx.colls; i++) 
//		{
//			std::cout << mtx.mtx[i][j];
//		}
//	}
//}
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
Rational& sumOfRational(Rational& r1, const Rational& r2) 
{
	r1.num = r1.num * r2.dom + r2.num * r1.dom;
	r1.dom *= r2.dom;
	int gcdOfNumAndDom = gcd(r1.num, r1.dom);
	r1.num /= gcdOfNumAndDom;
	r1.dom /= gcdOfNumAndDom;
	return r1;
}
int main()
{
	/*Matrix mtx;
	std::cin >> mtx.rows >> mtx.colls;
	readMatrix(mtx);
	Matrix trans;
	transp(trans, mtx);
	printMatrix(trans);*/
	Rational r1{ 1,4 };
	Rational r2{ 3,12 };
	sumOfRational(r1, r2);
	std::cout << r1.num << "/" << r1.dom;
}
//Задача 2. Да се създаде структура, която представя комплексно число. Създайте функция, които връща сбора и такава, 
//която връща произведението на 2 комплексни числа. Създайте подходяща функция за принтиране на комплексно число.
//Използвайте подходящ namespace.