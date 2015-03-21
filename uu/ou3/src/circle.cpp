#include "circle.h"
#include <cmath>

//Konstruktor
Circle::Circle(double x, double y, double radie) : Shape(x, y)
{
	_r = radie;
}

double Circle::area()
{
	return M_PI * (_r * _r);
}