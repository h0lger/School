#include "rectangle.h"

//Konstruktor
Rectangle::Rectangle(double x, double y, double width, double heigth) : Shape(x, y)
{
	_width = width;
	_height = heigth;
}

double Rectangle::area()
{
	return _width * _height;
}