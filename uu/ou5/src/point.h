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
    void print(ostream& os); //override
	Point *clone() const; //override
	
private:
	double _size;
};
#endif
