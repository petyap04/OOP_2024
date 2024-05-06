#include "Triangle.h"
#include <iostream>

Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3):Shapes(3), p1(x1,y1), p2(x2,y2),p3(x3,y3) {}
Triangle::Triangle(const Point& p1, const Point& p2, const Point& p3):Shapes(3), p1(p1),p2(p2), p3(p3){}

double Triangle::getArea() const
{
	double side1 = getDistanceBetweenTwoPoints(p1, p2);
	double side2 = getDistanceBetweenTwoPoints(p1, p3);
	double side3 = getDistanceBetweenTwoPoints(p2, p3);
	double halfPer = (side1 + side2 + side3) / 2;
	return std::sqrt(halfPer * (halfPer - side1) * (halfPer - side2) * (halfPer - side3));
}

double Triangle::getPer() const
{
	return getDistanceBetweenTwoPoints(p1, p2) + getDistanceBetweenTwoPoints(p1, p3) + getDistanceBetweenTwoPoints(p2, p3);
}

bool Triangle::isPointInside(int x, int y) const
{
	Point newPoint(x, y);
	Triangle tr1(p1, p2, newPoint);
	Triangle tr2(p1, p3, newPoint);
	Triangle tr3(p2, p3, newPoint);
	return (abs(getArea() - (tr1.getArea() + tr2.getArea() + tr3.getArea()))) <= 0,0001;
}
