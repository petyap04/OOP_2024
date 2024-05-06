#include "Rectangle.h"

Rectangle::Rectangle(int x1, int y1, int x2, int y2):Shapes(2),p1(x1,y1),p2(x2,y2) {}
Rectangle::Rectangle(const Point& p1, const Point& p2):Shapes(2), p1(p1),p2(p2) {}

double Rectangle::getArea() const
{
	Point p3(p1.getX(), p2.getY());
	return getDistanceBetweenTwoPoints(p1, p3) * getDistanceBetweenTwoPoints(p2, p3);
}

double Rectangle::getPer() const
{
	Point p3(p1.getX(), p2.getY());
	return 2 * (getDistanceBetweenTwoPoints(p1, p3) + getDistanceBetweenTwoPoints(p2, p3));
}

bool Rectangle::isPointInside(int x, int y) const
{
	return (x<p1.getX() && x>p2.getX()) || (x<p2.getX() && x>p1.getX()) && (y<p1.getY() && y>p2.getY()) || (y<p2.getY() && y>p1.getY());
}
