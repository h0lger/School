#include "point.h"

//Konstruktor
Point::Point(double x, double y, double size) : Shape(x, y)
{
	_size = size;
}

Point::Point(const Point &p) : Shape(p._x, p._y)
{
	_size = p._size;
}

double Point::area()
{
	return _size;
}

void Point::print()
{
	std::cout << "POINT: ";
	Shape::print(); //använder basklassens print för att få ut pos
	std::cout << _size << "\n";
}

Point *Point::clone()
{
	Point *tmp = new Point(*this);
	return tmp;
}
