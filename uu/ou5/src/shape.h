#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>

using namespace std;
class Shape
{
public:
	//Shape();
	Shape(double x, double y);
	Shape(const Shape &); //kopieringskonstruktor
	virtual ~Shape();
	virtual Shape *clone() const; //klonar ett objekt
	virtual double area();
    virtual void print(ostream& os); //skriver ut figuren (typ, position, storlek)
	double getX();
	double getY();
	
protected:
	double _x, _y;
};
#endif
