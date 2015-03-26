#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
class Shape
{
public:
	//Shape();
	Shape(double x, double y);
	Shape(const Shape &); //kopieringskonstruktor
	//~Shape();
	virtual Shape *clone(); //klonar ett objekt
	double area();
	void print(); //skriver ut figuren (typ, position, storlek)
protected:
	double _x, _y;
};
#endif