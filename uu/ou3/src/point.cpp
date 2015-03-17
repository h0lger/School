#include "point.h"

//Konstruktor
Point::Point(double x, double y, double size) : Shape(x, y)
{
	_size = size;
}
