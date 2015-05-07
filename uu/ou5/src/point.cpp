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

void Point::print(ostream& os)
{
    os << POINT << " ";
    Shape::print(os); //använder basklassens print för att få ut pos
    os << _size;
}

Point *Point::clone() const
{
	Point *tmp = new Point(*this);
	return tmp;
}
