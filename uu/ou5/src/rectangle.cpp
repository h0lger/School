#include "rectangle.h"

//Konstruktor
Rectangle::Rectangle(double x, double y, double width, double heigth) : Shape(x, y)
{
	_width = width;
	_height = heigth;
}

Rectangle::Rectangle(const Rectangle &r) : Shape(r._x, r._y)
{
	_width = r._width;
	_height = r._height;
}

double Rectangle::area()
{
	return _width * _height;
}

void Rectangle::print(ostream& os)
{
    os << "RECTANGLE: ";
    Shape::print(os);
    os << "(" << _width << "," << _height << ")";
}

Rectangle *Rectangle::clone() const
{
	Rectangle *tmp = new Rectangle(*this);
	return tmp;
}
