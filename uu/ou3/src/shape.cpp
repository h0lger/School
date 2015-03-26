#include "shape.h"

Shape::Shape(double x, double y)
{
	_x = x;
	_y = y;
}

Shape::Shape(const Shape &s)
{
	_x = s._x;
	_y = s._y;
}

//Positionen
void Shape::print()
{
	std::cout << "(" << _x << "," << _y << ") ";
}

Shape* Shape::clone()
{
	Shape* tmp = new Shape(*this);
	return tmp;
}