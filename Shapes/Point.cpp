#include "Point.h"
#include <iostream>

Point::Point(int x, int y):x(x),y(y) {}

int Point::getX() const
{
	return x;
}

int Point::getY() const
{
	return y;
}

double getDistanceBetweenTwoPoints(const Point& lhs, const Point& rhs) 
{
	double dx = rhs.x - lhs.x;
	double dy = rhs.y - lhs.y;
	return std::sqrt(dx * dx + dy * dy);
}
