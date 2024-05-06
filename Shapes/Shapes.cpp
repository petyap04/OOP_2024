
#include <iostream>
#include "Shapes.h"
#include "Triangle.h"
#include "Circle.h"
#include "Rectangle.h"
#include <assert.h>


void Shapes::copyFrom(const Shapes& other)
{
	numberOfPoints = other.numberOfPoints;
	points = new Point[numberOfPoints];
	for (int i = 0; i < numberOfPoints; i++) {
		points[i] = other.points[i];
	}
}

void Shapes::free()
{
	delete[]points;
	numberOfPoints = 0;
}

Shapes::Shapes(size_t pointsCount)
{
	points = new Point[pointsCount];
	numberOfPoints = pointsCount;
}

double Shapes::getPer() const
{
	assert(numberOfPoints >= 3);
	double per = 0;
	for (int i = 0; i < numberOfPoints - 1; i++) {
		per += getDistanceBetweenTwoPoints(points[i], points[i + 1]);
	}
	return per + getDistanceBetweenTwoPoints(points[numberOfPoints - 1], points[0]);
}

Shapes::~Shapes()
{
	free();
}

int main() {
	Shapes* arr[3];
	arr[0] = new Circle(1, 1, 3);
	arr[1] = new Triangle(0, 0, 3, 3, 0, 2);
	arr[2] = new Rectangle(1, 1, 2, 2);
	std::cout << arr[0]->getArea() << std::endl;
	std::cout << arr[1]->getArea() << std::endl;
	std::cout << arr[2]->getArea() << std::endl;

	
}