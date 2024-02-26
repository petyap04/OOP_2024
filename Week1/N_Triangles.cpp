#include <iostream>

struct Point {
    int x;
    int y;
};
void readPoint(Point& point) {
    std::cin >> point.x >> point.y;
}
struct Triangle {
    Point p1;
    Point p2;
    Point p3;
};
void readTriangle(Triangle& triangle)
{
    readPoint(triangle.p1);
    readPoint(triangle.p2);
    readPoint(triangle.p3);
}
double distanceBetweenTwoPoints(const Point& p1, const Point& p2) {
    double dx = (p1.x - p2.x);
    double dy = (p1.y - p2.y);
    return std::sqrt(dx * dx + dy * dy);
}
double areaOfTriangle(const Triangle triangle) {
    double side1 = distanceBetweenTwoPoints(triangle.p1, triangle.p2);
    double side2 = distanceBetweenTwoPoints(triangle.p2, triangle.p3);
    double side3 = distanceBetweenTwoPoints(triangle.p1, triangle.p3);
    double halfp = (side1 + side2 + side3) / 2;
    return std::sqrt(halfp * (halfp - side1) * (halfp - side2) * (halfp - side3));
}
void fillWithAreaOfTriangle(const Triangle* trianglesArr, double* areaArr, size_t size){ 
    for (size_t i = 0; i < size; i++)
    {
        areaArr[i] = areaOfTriangle(trianglesArr[i]);
    }
}
void sortByArea(Triangle* trianglesArr, size_t size) {
    double* areaArr = new double[size];
    fillWithAreaOfTriangle(trianglesArr, areaArr, size);
    for (size_t i = 0; i < size - 1; i++) {
        int minElIndex = i;
        for (size_t j = i + 1; j < size; j++)
        {
            if (areaArr[j] < areaArr[minElIndex]) {
                minElIndex = j;
            }
        }
        std::swap(areaArr[i], areaArr[minElIndex]);
        std::swap(trianglesArr[i], trianglesArr[minElIndex]);
    }
    delete[]areaArr;
}
void printPoint(const Point& p) {
    std::cout << "(" << p.x << "." << p.y << ")";
}
void printTriangle(const Triangle& triangle){
    printPoint(triangle.p1);
    printPoint(triangle.p2);
    printPoint(triangle.p3);
    std::cout << std::endl;
}
int main()
{
    size_t n;
    std::cin >> n;
    Triangle* trianglesArr = new Triangle[n];
    for (size_t i = 0; i < n; i++)
    {
        readTriangle(trianglesArr[i]);
    }
    sortByArea(trianglesArr, n);
    for (size_t i = 0; i < n; i++)
    {
        printTriangle(trianglesArr[i]);
    }
    delete[]trianglesArr;
}
