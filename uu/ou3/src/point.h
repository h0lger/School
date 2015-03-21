#ifndef POINT_H
#define POINT_H
#include "shape.h"
class Point : public Shape
{
public:
	Point(double x, double y, double size);
	//~Point();
	double area(); //override
	
private:
	double _size;
};
#endif