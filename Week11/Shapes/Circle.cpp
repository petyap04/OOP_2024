#include "Circle.h"
#include <iostream>

Circle::Circle(int x1, int y1, double rad):Shapes(1),p(x1,y1), rad(rad) {}
Circle::Circle(const Point& p, double rad):Shapes(1), p(p), rad(rad) {}

double Circle::getArea() const
{
	return PI * rad * rad;
}

double Circle::getPer() const
{
	return 2 * PI * rad;
}

bool Circle::isPointInside(int x, int y) const
{
	Point p2(x, y);
	return abs(getDistanceBetweenTwoPoints(p, p2) - rad <= 0.0001);
}
