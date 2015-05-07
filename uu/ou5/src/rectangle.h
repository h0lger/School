#ifndef RECTANGLE_H
#define RECTANGLE_H
#define RECTANGLE "RECTANGLE"
#include "shape.h"

class Rectangle : public Shape
{
public:
	Rectangle(double x, double y, double width, double height);
	Rectangle(const Rectangle &); //kopieringskonstruktor
	//~Rectangle();
	double area(); //override
    void print(ostream& os); //override
	Rectangle *clone() const; //override
	
private:
	double _width, _height;
};

#endif
