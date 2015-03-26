#ifndef POINT_H
#define POINT_H
#include "shape.h"
class Point : public Shape
{
public:
	Point(double x, double y, double size);
	Point(const Point &); //kopieringskonstruktor
	//~Point();
	double area(); //override
	void print(); //override
	Point *clone(); //override
	
private:
	double _size;
};
#endif