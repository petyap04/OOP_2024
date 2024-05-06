#pragma once
#include "Point.h"

class Shapes
{
private:
	Point* points= nullptr;
	size_t numberOfPoints = 0;

	void copyFrom(const Shapes& other);
	void free();
public:
	Shapes(size_t pointsCount);
	virtual double getArea() const= 0;
	virtual double getPer() const;
	virtual bool isPointInside(int x, int y) const= 0;
	virtual~Shapes();
};
