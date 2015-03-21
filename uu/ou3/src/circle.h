#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.h"
class Circle : public Shape
{
public:
	Circle(double x, double y, double radie);
	//~Circle();
	double area(); //override
	
private:
	double _r;
};

#endif