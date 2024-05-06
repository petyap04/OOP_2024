#pragma once
class Point
{
private:
	int x = 0;
	int y = 0;
public:
	Point() = default;
	Point(int x, int y);
	int getX()const;
	int getY()const;
	friend double getDistanceBetweenTwoPoints(const Point& lhs, const Point& rhs);
};

