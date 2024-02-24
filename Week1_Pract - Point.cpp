#include <iostream>
#include <assert.h>

struct Point {
    double x;
    double y;
};
void readPoint(Point& p) {
    std::cin >> p.x;
    std::cin >> p.y;
}
void printPoint(const Point& p) {
    std::cout << "(" << p.x << "," << p.y << ")" << std::endl;
}
double distaceFromCenter(const Point& p) {
    return sqrt(p.x * p.x + p.y * p.y);
}
double distanceBetweenTwoPoints(const Point& p1, const Point& p2) {
    return std::sqrt((p1.y - p2.y) * (p1.y - p2.y) + (p1.x - p2.x) * (p1.x - p2.x));
}
struct Intercept {
    Point p1;
    Point p2;
    double distance;
};
void readIntercept(Intercept& i) {
    readPoint(i.p1);
    readPoint(i.p2);
    i.distance = distanceBetweenTwoPoints(i.p1, i.p2);
}
bool isPositive(double coordinat) {
    return coordinat >= 0;
}
unsigned int quadrant(const Point& p) {
    if (isPositive(p.x)) {
        if (isPositive(p.y))return 1;
        else return 2;
    }
    else {
        if (isPositive(p.y))return 4;
        else return 3;
    }
}
bool isPartOfTheCircle(const Point& p, double rad) {
    assert(std::abs(p.x) <= rad && std::abs(p.y) <= rad);
    double distance = distanceBetweenTwoPoints(p, { 0,0 });
    if (distance <= rad)return true;
    else return false;
}
int main()
{
    
}
