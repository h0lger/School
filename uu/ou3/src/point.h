#ifndef POINT_H
#include "shape.h"
class Point : public Shape
{
public:
	Point(double x, double y, double size);
	~Point();
	
private:
	double _size;
};
#endif