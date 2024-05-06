#pragma once
#include "Shapes.h"
#include "Point.h"

class Rectangle :public Shapes
{
private:
	Point p1;
	Point p2;
public:
	Rectangle(int x1, int y1, int x2, int y2);
	Rectangle(const Point& p1, const Point& p2);
	double getArea()const override;
	double getPer()const override;
	bool isPointInside(int x, int y)const override;
};

