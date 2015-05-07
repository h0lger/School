#ifndef CIRCLE_H
#define CIRCLE_H
#define CIRCLE "CIRCLE"
#include "shape.h"
class Circle : public Shape
{
public:
	Circle(double x, double y, double radie);
	Circle(const Circle &); //kopieringskonstruktor
	//~Circle();
	double area(); //override
    void print(ostream& os); //override
	Circle *clone() const; //override
	
private:
	double _r;
};

#endif
