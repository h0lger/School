#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.h"
class Circle : public Shape
{
public:
	Circle(double x, double y, double radie);
	Circle(const Circle &); //kopieringskonstruktor
	//~Circle();
	double area(); //override
	void print(); //override
	Circle *clone(); //override
	
private:
	double _r;
};

#endif