#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"
class Rectangle : public Shape
{
public:
	Rectangle(double x, double y, double width, double height);
	//~Rectangle();
	double area(); //override
	
private:
	double _width, _height;
};

#endif