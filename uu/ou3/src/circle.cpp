#include "circle.h"
#include <cmath>

//Konstruktor
Circle::Circle(double x, double y, double radie) : Shape(x, y)
{
	_r = radie;
}

Circle::Circle(const Circle &c) : Shape(c._x, c._y)
{	
	_r = c._r;
}

double Circle::area()
{
	return M_PI * (_r * _r);
}

void Circle::print()
{
	std::cout << "CIRCLE: ";
	Shape::print();
	std::cout << _r << "\n";
}

Circle * Circle::clone()
{
	Circle *tmp = new Circle(*this);
	return tmp;
}

