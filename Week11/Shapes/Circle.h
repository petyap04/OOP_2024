#pragma once
#include "Shapes.h"
#include "Point.h"
constexpr double PI = 3.1415;

class Circle :public Shapes
{
private:
	Point p;
	double rad = 0;
public:
	Circle(int x1, int y1, double rad);
	Circle(const Point& p, double rad);
	double getArea()const override;
	double getPer()const override;
	bool isPointInside(int x, int y)const override;
};

