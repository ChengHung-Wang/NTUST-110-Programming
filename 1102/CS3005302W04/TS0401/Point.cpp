// Name: 王正宏
// Date: March 13, 2022
// Last Update: March 13, 2022
// Problem statement: Class Point in plane
#include "Point.h"

using namespace std;

void Point::Set(int vertical, int horizontal)
{
	Point::vertical = vertical;
	Point::horizontal = horizontal;
}

void Point::Move(int x, int y)
{
	Point::vertical += x;
	Point::horizontal += y;
}
void Point::Rotate()
{
	std::swap(Point::vertical, Point::horizontal);
	Point::horizontal *= -1;
}
