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

Shape::~Shape()
{
	std::cout << "~Shape()";
	_x = 0;
	_y = 0;
}

//Positionen
void Shape::print()
{
	std::cout << "(" << _x << "," << _y << ") ";
}

double Shape::area()
{
	std::cout << "Ska inte användas";
	return 0;
}


Shape* Shape::clone() const
{
	Shape* tmp = new Shape(*this);
	return tmp;
}

double Shape::getX()
{
	return _x;
}

double Shape::getY()
{
	return _y;
}